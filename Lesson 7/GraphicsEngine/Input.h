#pragma once
#include <SDL.h>

class Input
{

public:

	static Input* Instance();

	bool IsXClicked() const;
	bool IsKeyPressed() const;

	char GetKeyUp() const;
	char GetKeyDown() const;

	bool IsLeftButtonClicked() const;
	bool IsRightButtonClicked() const;
	bool IsMiddleButtonClicked() const;

	int GetMouseWheelMotion() const;
	const SDL_Point& GetMouseMotion() const;
	const SDL_Point& GetMousePosition() const;

	void Update();

private:

	Input() {}
	Input(const Input&);
	Input& operator=(Input&);

	char keyUp{ 0 };
	char keyDown{ 0 };

	bool isXClicked{ false };
	bool isKeyPressed{ false };

	bool isLeftButtonClicked{ false };
	bool isRightButtonClicked{ false };
	bool isMiddleButtonClicked{ false };

	int mouseWheelMotion{ 0 };
	SDL_Point mouseMotion{ 0, 0 };
	SDL_Point mousePosition{ 0, 0 };

};