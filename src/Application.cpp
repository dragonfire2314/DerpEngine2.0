#include "Application.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include <ecs/EntityManager.h>
#include <ecs/ComponentManager.h>
#include <ecs/SystemManager.h>
#include <ecs/Components.h>

namespace DERP {

    Application::Application()
	{
		printf("App Started\n");
	}

	Application::~Application()
	{

	}

    void Application::Run()
	{
		//Loader temp shader
		// renderer->SetUp();

		float lastFrameTime = 0.0f;

		//Engine loop
		do {
			//Time keeping
			// float currentTime = glfwGetTime();
			// TIME::deltaTime = currentTime - lastFrameTime;
			// TIME::time = currentTime;
			// lastFrameTime = currentTime;

			//Clear screen
			// renderer->ClearScreen(); 
			//Run physics

			//Render
			// renderer->Render();

			// Swap buffers
			glfwSwapBuffers((GLFWwindow*)window);
			glfwPollEvents();

		} while (glfwGetKey((GLFWwindow*)window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
			glfwWindowShouldClose((GLFWwindow*)window) == 0);
	}

    void Application::Init(uint32_t width, uint32_t height)
	{
		screenWidth = width;
		screenHeight = height;
		/*
			GLFW INIT
		*/
		start();
		/*
			ECS INTI
		*/
		//ECS component init
		CM::RegisterComponent<Transform>();
		CM::RegisterComponent<Camera>();
		/*
			RENDERER
		*/
		// renderer->renderWidth = screenWidth;
		// renderer->renderHeight = screenHeight;
	}

    void Application::start()
	{
		// Initialise GLFW
		glewExperimental = true; // Needed for core profile
		if (!glfwInit())
		{
			fprintf(stderr, "Failed to initialize GLFW\n");
		}

		glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

		// Open a window and create its OpenGL context
		// (In the accompanying source code, this variable is global for simplicity)
		window = glfwCreateWindow(screenWidth, screenHeight, "Derp Engine", NULL, NULL);
		if (window == NULL) {
			fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible.\n");
			glfwTerminate();
		}
		glfwMakeContextCurrent((GLFWwindow*)window); // Initialize GLEW
		glewExperimental = true; // Needed in core profile
		if (glewInit() != GLEW_OK) {
			fprintf(stderr, "Failed to initialize GLEW\n");
		}

		// Ensure we can capture the escape key being pressed below
		glfwSetInputMode((GLFWwindow*)window, GLFW_STICKY_KEYS, GL_TRUE);
	}
}