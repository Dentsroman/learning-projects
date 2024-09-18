#include "Renderer.h"
#include <iostream>
#include <fstream>
#include <sstream>

const char* vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec2 aPos;

void main() {
    gl_Position = vec4(aPos, 0.0, 1.0);
}
)";

const char* fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;

void main() {
    FragColor = vec4(1.0, 1.0, 1.0, 1.0); // White color
}
)";

Renderer& Renderer::getInstance(int width, int height, const std::string& title) {
    static Renderer instance(width, height, title);
    return instance;
}

Renderer::Renderer(int width, int height, const std::string& title)
    : width(width), height(height), title(title), window(nullptr), shaderProgram(0), VBO(0), VAO(0) {}

Renderer::~Renderer() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
}

void Renderer::initialize() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        exit(EXIT_FAILURE);
    }

    glViewport(0, 0, width, height);

    shaderProgram = createShaderProgram();
    setupGrid();
}

GLuint Renderer::compileShader(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    return shader;
}

GLuint Renderer::createShaderProgram() {
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    int success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cerr << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

void Renderer::generateGrid(int numCells, float gridSize) {
    vertices.clear();
    float step = gridSize / numCells;
    for (int i = 0; i <= numCells; ++i) {
        float pos = -gridSize / 2 + i * step;
        // Vertical lines
        vertices.push_back(pos);
        vertices.push_back(-gridSize / 2);
        vertices.push_back(pos);
        vertices.push_back(gridSize / 2);

        // Horizontal lines
        vertices.push_back(-gridSize / 2);
        vertices.push_back(pos);
        vertices.push_back(gridSize / 2);
        vertices.push_back(pos);
    }
    setupGrid();
}

void Renderer::setupGrid() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Renderer::render() {
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, vertices.size() / 2);
    glBindVertexArray(0);
}

void Renderer::run() {
    while (!glfwWindowShouldClose(window)) {
        render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Renderer::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}