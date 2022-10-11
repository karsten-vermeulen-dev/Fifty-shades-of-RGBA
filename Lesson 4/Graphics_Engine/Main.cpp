#include <Windows.h>
#include <gl/GL.h>

#include <iostream>
#include <math.h>
#include <SDL.h>

bool isAppRunning{ true };
SDL_Window* window{ nullptr };
SDL_GLContext context{ nullptr };

struct Vector2D
{
	float x = 0.0f;
	float y = 0.0f;
};

struct Vector3D
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

Vector2D scale { 0.1f, 0.1f };
Vector3D position { 0.0f, 0.0f, 0.0f };

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Error initializing SDL" << std::endl;
		system("pause");
		return 0;
	}

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

	window = SDL_CreateWindow("Graphics Engine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280,
		720,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	if (!window)
	{
		std::cout << "SDL window could not be created." << std::endl;
		system("pause");
		return 0;
	}

	context = SDL_GL_CreateContext(window);

	if (!context)
	{
		std::cout << "OpenGL context could not be created. "
			"The context is either invalid or not supported by your graphics card" << std::endl;
		system("pause");
		return 0;
	}

	static auto number{ 0.0f };

	while (isAppRunning)
	{
		number += 0.01f;

		glClear(GL_COLOR_BUFFER_BIT);

		SDL_Event events;

		while (SDL_PollEvent(&events))
		{
			switch (events.type)
			{

			case SDL_QUIT:
			{
				isAppRunning = false;
				break;
			}

			case SDL_KEYDOWN:
			{
				char key = events.key.keysym.sym;
				std::cout << "The " << key << " was pressed" << std::endl;
				break;
			}

			case SDL_KEYUP:
			{
				char key = events.key.keysym.sym;
				std::cout << "The " << key << " was released" << std::endl;
				break;
			}

			case SDL_MOUSEBUTTONDOWN:
			{
				switch (events.button.button)
				{

				case SDL_BUTTON_LEFT:
				{
					std::cout << "Left mouse button was clicked." << std::endl;
					break;
				}

				case SDL_BUTTON_RIGHT:
				{
					std::cout << "Right mouse button was clicked." << std::endl;
					break;
				}

				case SDL_BUTTON_MIDDLE:
				{
					std::cout << "Middle mouse button was clicked." << std::endl;
					break;
				}
				}

				break;
			}

			case SDL_MOUSEBUTTONUP:
			{
				switch (events.button.button)
				{

				case SDL_BUTTON_LEFT:
				{
					std::cout << "Left mouse button was released." << std::endl;
					break;
				}

				case SDL_BUTTON_RIGHT:
				{
					std::cout << "Right mouse button was released." << std::endl;
					break;
				}

				case SDL_BUTTON_MIDDLE:
				{
					std::cout << "Middle mouse button was released." << std::endl;
					break;
				}
				}

				break;
			}

			case SDL_MOUSEMOTION:
			{
				auto mouseMotionX = events.motion.xrel;
				auto mouseMotionY = events.motion.yrel;

				auto mousePositionX = events.motion.x;
				auto mousePositionY = events.motion.y;

				auto mousePositionXNDC = mousePositionX / 1280.0f * 2.0f - 1.0f;
				auto mousePositionYNDC = mousePositionY / 720.0f * 2.0f - 1.0f;

				position.x = mousePositionXNDC;
				position.y = -mousePositionYNDC;

				break;
			}

			case SDL_MOUSEWHEEL:
			{
				auto wheelMotion = events.wheel.y;
				std::cout << wheelMotion << std::endl;

				scale.x += wheelMotion * 0.01f;
				scale.y += wheelMotion * 0.01f;

				break;
			}

			}
		}

		glBegin(GL_QUADS);

		glColor3f(1.0f, std::sin(std::abs(number)), 0.0f);
		glVertex3f(position.x - scale.x, position.y + scale.y, position.z + 0.0f);

		glColor3f(std::cos(std::abs(number)), 0.0f, 0.0f);
		glVertex3f(position.x + scale.x, position.y + scale.y, position.z + 0.0f);

		glColor3f(0.0f, std::sin(std::abs(number)), 0.0f);
		glVertex3f(position.x + scale.x, position.y - scale.y, position.z + 0.0f);

		glColor3f(0.0f, 0.0f, std::cos(std::abs(number)));
		glVertex3f(position.x - scale.x, position.y - scale.y, position.z + 0.0f);

		glEnd();

		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}