#include "Renderer.h"

Renderer::Renderer() : isRunning(false) {}

Renderer::~Renderer() = default;

Renderer& Renderer::getInstance() {
	static Renderer instance;
	return instance;
}

void Renderer::execute() {
	std::lock_guard<std::mutex> guard(lock);
	if (isRunning) {
		return;
	}
	isRunning = true;

	try {
		while (isRunning) {
			render();
		}
	}
	catch (...) {
		isRunning = false;
		throw;
	}

	isRunning = false;
}

void Renderer::initialize() {
	SDL_Surface* img = SDL_LoadBMP("base_background.bmp");
	GLuint tex = create_GL_texture(img);
}

void Renderer::render() {
	//Render the cells
}