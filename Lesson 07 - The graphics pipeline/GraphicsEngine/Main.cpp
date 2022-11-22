//TODO - Remove these in Lesson 5 as well as here
//#include <Windows.h>
//#include <gl/GL.h>

#include <iostream>
#include <math.h>

#include "Input.h"
#include "Screen.h"
#include "Shader.h"
#include "Utility.h"

Shader shader;
bool isAppRunning{ true };

int main(int argc, char* argv[])
{
	Utility::Initialize();

	if (!Screen::Instance()->Initialize(1280, 720, 4.6f))
	{
		return 0;
	}

	Screen::Instance()->SetColor(0.15f, 0.15f, 0.15f);

	Shader::Initialize();

	shader.Create("Shaders/Main.vert", "Shaders/Main.frag");
	shader.Use();

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

	shader.Destroy();

	Shader::Shutdown();
	Screen::Instance()->Shutdown();

	return 0;
}