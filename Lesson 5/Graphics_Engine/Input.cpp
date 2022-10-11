#include "Input.h"

Input* Input::Instance()
{
	static Input* input = new Input();
	return input;
}

bool Input::IsXClicked()
{
	return isXClicked;
}

bool Input::IsKeyPressed()
{
	return isKeyPressed;
}

char Input::GetKeyUp()
{
	return keyUp;
}

char Input::GetKeyDown()
{
	return keyDown;
}

bool Input::IsLeftButtonClicked()
{
	return isLeftButtonClicked;
}

bool Input::IsRightButtonClicked()
{
	return isRightButtonClicked;
}

bool Input::IsMiddleButtonClicked()
{
	return isMiddleButtonClicked;
}

int Input::GetMousePositionX()
{
	return mousePositionX;
}

int Input::GetMousePositionY()
{
	return mousePositionY;
}

int Input::GetMouseMotionX()
{
	return mouseMotionX;
}

int Input::GetMouseMotionY()
{
	return mouseMotionY;
}

void Input::Update()
{
	SDL_Event events;

	mouseMotionX = 0;
	mouseMotionY = 0;
	mousePositionX = 0;
	mousePositionY = 0;

	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{
		case SDL_QUIT:
		{
			isXClicked = true;
			break;
		}

		case SDL_KEYDOWN:
		{
			isKeyPressed = true;
			keyDown = events.key.keysym.sym;
			break;
		}

		case SDL_KEYUP:
		{
			isKeyPressed = false;
			keyUp = events.key.keysym.sym;
			break;
		}

		case SDL_MOUSEBUTTONDOWN:
		{
			switch (events.button.button)
			{
			case SDL_BUTTON_LEFT:
			{
				isLeftButtonClicked = true;
				break;
			}

			case SDL_BUTTON_RIGHT:
			{
				isRightButtonClicked = true;
				break;
			}

			case SDL_BUTTON_MIDDLE:
			{
				isMiddleButtonClicked = true;
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
				isLeftButtonClicked = false;
				break;
			}

			case SDL_BUTTON_RIGHT:
			{
				isRightButtonClicked = false;
				break;
			}

			case SDL_BUTTON_MIDDLE:
			{
				isMiddleButtonClicked = false;
				break;
			}
			}

			break;
		}

		case SDL_MOUSEMOTION:
		{
			mouseMotionX = events.motion.xrel;
			mouseMotionY = events.motion.yrel;

			mousePositionX = events.motion.x;
			mousePositionY = events.motion.y;
		}
		}
	}
}