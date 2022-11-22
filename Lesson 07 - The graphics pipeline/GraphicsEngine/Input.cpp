#include "Input.h"

Input* Input::Instance()
{
	static Input* input = new Input();
	return input;
}

bool Input::IsXClicked() const
{
	return isXClicked;
}

bool Input::IsKeyPressed() const
{
	return isKeyPressed;
}

char Input::GetKeyUp() const
{
	return keyUp;
}

char Input::GetKeyDown() const
{
	return keyDown;
}

bool Input::IsLeftButtonClicked() const
{
	return isLeftButtonClicked;
}

bool Input::IsRightButtonClicked() const
{
	return isRightButtonClicked;
}

bool Input::IsMiddleButtonClicked() const
{
	return isMiddleButtonClicked;
}

int Input::GetMouseWheelMotion() const
{
	return mouseWheelMotion;
}

const SDL_Point& Input::GetMouseMotion() const
{
	return mouseMotion;
}

const SDL_Point& Input::GetMousePosition() const
{
	return mousePosition;
}

void Input::Update()
{
	SDL_Event events;

	mouseMotion = { 0, 0 };
	mouseWheelMotion = 0;

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
			mouseMotion.x = events.motion.xrel;
			mouseMotion.y = events.motion.yrel;

			mousePosition.x = events.motion.x;
			mousePosition.y = events.motion.y;

			break;
		}

		case SDL_MOUSEWHEEL:
		{
			mouseWheelMotion = events.wheel.y;
			break;
		}
		}
	}
}