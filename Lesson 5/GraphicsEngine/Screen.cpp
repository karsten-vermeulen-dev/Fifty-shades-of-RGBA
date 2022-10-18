#include <Windows.h>
#include <gl/GL.h>
#include <iostream>
#include "Screen.h"

Screen* Screen::Instance()
{
	static Screen* screen = new Screen;
	return screen;
}

void Screen::SetColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glClearColor(r, g, b, a);
}

bool Screen::Initialize(int width, int height, float version)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Error initializing SDL." << std::endl;
		system("pause");
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);

	version *= 10.0f;
	auto major = int(version) / 10;
	auto minor = int(version) % 10;

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);

	window = SDL_CreateWindow("Graphics Engine",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	if (!window)
	{
		std::cout << "Error creating SDL window." << std::endl;
		system("pause");
		return false;
	}

	context = SDL_GL_CreateContext(window);

	if (!context)
	{
		std::cout << "Error creating OpenGL context. "
			"The context is either invalid or not supported by your graphics card." << std::endl;
		system("pause");
		return false;
	}

	return true;
}

void Screen::Refresh()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Screen::Present()
{
	SDL_GL_SwapWindow(window);
}

void Screen::Shutdown()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}