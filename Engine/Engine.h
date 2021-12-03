#pragma once

#define REGISTER_CLASS(CLASS) MAC::ObjectFactory::Instance().Register<CLASS>(#CLASS);
#define CREATE_ENGINE_OBJECT(CLASS) MAC::ObjectFactory::Instance().Create<MAC::CLASS>(#CLASS);

//Audio
#include "Audio/AudioSystem.h"

//core
#include "Core/FileSystem.h"
#include "Core/Timer.h"
#include "Core/Utilities.h"
#include "Core/Json.h"
#include "Core/Serializable.h"

//Framework
#include "Framework/EventSystem.h"
#include "Framework/System.h"
#include "Framework/Singleton.h"
#include "Framework/Factory.h"

//Math
#include "MathTypes.h"
#include "Math/Random.h"
#include "Math/MathUtils.h"
#include "Math/Transform.h"

//Graphics
#include "Graphics/Renderer.h"
#include "Graphics/Texture.h"
#include "Graphics/Material.h"
#include "Graphics/VertexBuffer.h"

//STD
#include <vector>
#include <algorithm>
#include <memory>

//Input
#include "Input/InputSystem.h"

//resource
#include "Resource/ResourceSystem.h"

//objects
#include "Object/Actor.h"
#include "Object/Object.h"
#include "Object/Scene.h"

//Components
#include "Component/PhysicsComponent.h"
#include "Component/AudioComponent.h"
#include "Component/CameraComponent.h"
#include "Component/MeshComponent.h"
#include "Component/ModelComponent.h"
#include "Component/FreeCameraController.h"
#include "Component/LightComponent.h"

namespace MAC {
	using ObjectFactory = Singleton<Factory<std::string, Object>>;

	class Engine {
	public:
		void Startup();
		void Shutdown();

		void Update();
		void Draw(Renderer* renderer);

		template<typename T>
		T* Get();

	public:
		FrameTimer time;

	private:
		std::vector<std::unique_ptr<System>> systems;
	};

	template<typename T>
	inline T* Engine::Get()
	{
		for (auto& system : systems) {
			if (dynamic_cast<T*>(system.get())) return dynamic_cast<T*>(system.get());
		}
		return nullptr;
	}
}