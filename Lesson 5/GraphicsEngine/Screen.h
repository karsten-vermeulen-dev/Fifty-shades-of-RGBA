#pragma once
#include <SDL.h>

class Screen
{

public:

	static Screen* Instance();

	bool Initialize();
	void Clear();
	void Present();
	void Shutdown();

private:

	Screen() {}
	Screen(const Screen&);
	Screen& operator=(const Screen&);

	SDL_Window* window{ nullptr };
	SDL_GLContext context{ nullptr };

};