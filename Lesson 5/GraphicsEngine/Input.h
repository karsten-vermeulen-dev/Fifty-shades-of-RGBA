#pragma once
#include <SDL.h>

class Input
{

public:

	static Input* Instance();

	bool IsXClicked();
	bool IsKeyPressed();

	char GetKeyUp();
	char GetKeyDown();

	bool IsLeftButtonClicked();
	bool IsRightButtonClicked();
	bool IsMiddleButtonClicked();

	int GetMousePositionX();
	int GetMousePositionY();

	int GetMouseMotionX();
	int GetMouseMotionY();

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

	int mouseMotionX{ 0 };
	int mouseMotionY{ 0 };

	int mousePositionX{ 0 };
	int mousePositionY{ 0 };

};