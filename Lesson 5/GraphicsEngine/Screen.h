#pragma once
#include <SDL.h>

class Screen
{

public:

	static Screen* Instance();

	void SetColor(GLfloat r = 0.0f,
		GLfloat g = 0.0f,
		GLfloat b = 0.0f,
		GLfloat a = 1.0f);

	bool Initialize();
	void Refresh();
	void Present();
	void Shutdown();

private:

	Screen() {}
	Screen(const Screen&);
	Screen& operator=(const Screen&);

	SDL_Window* window{ nullptr };
	SDL_GLContext context{ nullptr };

};