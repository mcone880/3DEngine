#include "Engine.h"

namespace MAC {

	void Engine::Startup() {
		systems.push_back(std::make_unique<AudioSystem>());
		systems.push_back(std::make_unique<EventSystem>());
		systems.push_back(std::make_unique<InputSystem>());
		systems.push_back(std::make_unique<Renderer>());
		systems.push_back(std::make_unique<ResourceSystem>());

		std::for_each(systems.begin(), systems.end(), [](auto& system) { system->Startup(); });

		REGISTER_CLASS(Actor);
		REGISTER_CLASS(AudioComponent);
		REGISTER_CLASS(CameraComponent);
		REGISTER_CLASS(FreeCameraController);
		REGISTER_CLASS(MeshComponent);
		REGISTER_CLASS(ModelComponent);
		REGISTER_CLASS(LightComponent);
	}

	void Engine::Shutdown() {
		std::for_each(systems.begin(), systems.end(), [](auto& system) { system->Shutdown(); });
	}

	void Engine::Update() {
		time.Tick();
		std::for_each(systems.begin(), systems.end(), [this](auto& system) { system->Update(this->time.deltaTime); });
	}

	void Engine::Draw(Renderer* renderer) {
		std::for_each(systems.begin(), systems.end(), [renderer](auto& system) { if (dynamic_cast<GraphicSystem*>(system.get())) dynamic_cast<GraphicSystem*>(system.get())->Draw(renderer); });
	}
}