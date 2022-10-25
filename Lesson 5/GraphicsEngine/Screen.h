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

	void SetColor(GLuint r = 0,
		GLuint g = 0,
		GLuint b = 0,
		GLuint a = 1);

	bool Initialize(int width, int height, float version);
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