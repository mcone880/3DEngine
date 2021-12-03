#pragma once
#include "Framework/System.h"
#include "Math/Transform.h"
#include <sdl.h>
#include <glad/glad.h>
#include <string>

namespace MAC {

	class Renderer : public System {
	public:
		void Startup() override;
		void Shutdown() override;
		void Update(float dt) override;

		void Create(const std::string& name, int width, int height);
		void BeginFrame();
		void EndFrame();

	private:
		SDL_GLContext context;
		SDL_Window* window{ nullptr };
	};
}