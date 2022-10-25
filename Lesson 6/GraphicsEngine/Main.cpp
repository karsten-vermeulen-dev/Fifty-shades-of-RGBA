#include <Windows.h>
#include <gl/GL.h>

#include <iostream>
#include <math.h>

#include "Input.h"
#include "Screen.h"

bool isAppRunning{ true };

struct Vector2D
{
	float x = 0.0f;
	float y = 0.0f;
};

struct Vector3D
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

Vector2D scale{ 0.5f, 0.5f };
Vector3D position{ 0.0f, 0.0f, 0.0f };

int main(int argc, char* argv[])
{
	if (!Screen::Instance()->Initialize(1280, 720, 4.6f))
	{
		return 0;
	}

	Screen::Instance()->SetColor(0.15f, 0.15f, 0.15f);

	static auto number{ 0.0f };

	while (isAppRunning)
	{
		number += 0.01f;

		Screen::Instance()->Refresh();

		Input::Instance()->Update();

		if (Input::Instance()->IsXClicked())
		{
			isAppRunning = false;
		}

		if (Input::Instance()->IsKeyPressed())
		{
			if (Input::Instance()->GetKeyDown() == 'a')
			{
				position.x -= 0.01f;
			}

			else if (Input::Instance()->GetKeyDown() == 'd')
			{
				position.x += 0.01f;
			}

			else if (Input::Instance()->GetKeyDown() == 'w')
			{
				position.y += 0.01f;
			}

			else if (Input::Instance()->GetKeyDown() == 's')
			{
				position.y -= 0.01f;
			}
		}

		glBegin(GL_QUADS);

		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(position.x - scale.x, position.y + scale.y, position.z + 0.0f);

		glColor3f(0.5f, 0.0f, 1.0f);
		glVertex3f(position.x + scale.x, position.y + scale.y, position.z + 0.0f);

		glColor3f(0.0f, 1.0f, 0.5f);
		glVertex3f(position.x + scale.x, position.y - scale.y, position.z + 0.0f);

		glColor3f(1.0f, 0.0f, 0.5f);
		glVertex3f(position.x - scale.x, position.y - scale.y, position.z + 0.0f);

		glEnd();

		Screen::Instance()->Present();
	}

	Screen::Instance()->Shutdown();
	return 0;
}