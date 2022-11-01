//TODO - Remove these in Lesson 5 as well as here
//#include <Windows.h>
//#include <gl/GL.h>

#include <iostream>
#include <math.h>

#include "Input.h"
#include "Screen.h"
#include "Utility.h"

bool isAppRunning{ true };

Utility::Vector2D scale{ 0.5f, 0.5f };
Utility::Vector3D position{ 0.0f, 0.0f, 0.0f };

int main(int argc, char* argv[])
{
	Utility::Initialize();

	if (!Screen::Instance()->Initialize(1280, 720, 4.6f))
	{
		return 0;
	}

	Screen::Instance()->SetColor(0.15f, 0.15f, 0.15f);

	while (isAppRunning)
	{
		Screen::Instance()->Refresh();

		Input::Instance()->Update();

		if (Input::Instance()->IsXClicked())
		{
			isAppRunning = false;
		}

		Screen::Instance()->Present();
	}

	Screen::Instance()->Shutdown();
	return 0;
}