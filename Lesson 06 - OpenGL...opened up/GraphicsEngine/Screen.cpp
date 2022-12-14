#include "gl.h"
#include <iostream>
#include "Screen.h"
#include "Utility.h"

Screen* Screen::Instance()
{
	static Screen* screen = new Screen;
	return screen;
}

void Screen::SetColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glClearColor(r, g, b, a);
}

void Screen::SetColor(GLuint r, GLuint g, GLuint b, GLuint a)
{
	glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, a);
}

bool Screen::Initialize(int width, int height, float version, bool isCore)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		Utility::Log("Error initializing SDL.", Utility::Severity::Failure);
		system("pause");
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	if (isCore)
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	}

	else
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	}

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
		Utility::Log("Error creating SDL window.", Utility::Severity::Failure);
		system("pause");
		return false;
	}

	context = SDL_GL_CreateContext(window);

	if (!context)
	{
		Utility::Log("Error creating OpenGL context. "
			"The context is either invalid or not supported by your graphics card.",
			Utility::Severity::Failure);
		system("pause");
		return false;
	}

	if (!gladLoaderLoadGL())
	{
		Utility::Log("Error loading OpenGL extensions.", Utility::Severity::Failure);
		return false;
	}

	Utility::Log("Application window created successfully.", Utility::Severity::Success);
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