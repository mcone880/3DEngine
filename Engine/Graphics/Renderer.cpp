#include "Renderer.h"
#include "Math/MathUtils.h"
#include <iostream>

namespace MAC {

	void Renderer::Startup() {
		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		}
	}

	void Renderer::Shutdown() {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
	}

	void Renderer::Update(float dt) {

	}

	void Renderer::Create(const std::string& name, int width, int height) {
		window = SDL_CreateWindow(name.c_str(), 100, 100, width, height, SDL_WINDOW_SHOWN);
		if (window == nullptr) {
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	}

	void Renderer::BeginFrame() {
		SDL_RenderClear(renderer);
	}

	void Renderer::EndFrame() {
		SDL_RenderPresent(renderer);
	}
}