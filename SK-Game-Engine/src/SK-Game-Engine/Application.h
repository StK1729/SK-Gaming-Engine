#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Events/ApplicationEvents.h"
#include "ImGui/ImGuiLayer.h"
#include "SK-Game-Engine/Renderer/Shader.h"
#include "SK-Game-Engine/Renderer/Buffer.h"
#include "SK-Game-Engine/Renderer/VertexArray.h"
#include "Renderer/Renderer.h"


namespace SK_Game_Engine {

	class SKGE_API Application {
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		static Application* s_Instance;
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::unique_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;
		std::shared_ptr<VertexArray> m_SquareVertexArray;
	};

	Application* CreateApplication();
}