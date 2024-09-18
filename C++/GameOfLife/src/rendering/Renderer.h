#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>
#include glfw
#include opengl

class Renderer {
public:
    static Renderer& getInstance(int width = 800, int height = 600, const std::string& title = "2D Grid");
    void initialize();
    void generateGrid(int numCells, float gridSize);
    void render();
    void run();

private:
    Renderer(int width, int height, const std::string& title);
    ~Renderer();
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    int width;
    int height;
    std::string title;
    GLFWwindow* window;
    GLuint shaderProgram;
    GLuint VBO, VAO;
    std::vector<float> vertices;

    GLuint compileShader(GLenum type, const char* source);
    GLuint createShaderProgram();
    void setupGrid();
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

#endif // RENDERER_H