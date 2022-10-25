#include <Windows.h>
#include <gl/GL.h>

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

	static auto number{ 0.0f };

	Utility::DisplayGraphicsProfile();

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

		static bool isErrorChecked = false;

		if (!isErrorChecked)
		{
			////check if an error occurred and store its value
			//GLenum errorValue = glGetError();

			////if OpenGL legacy code executed without error no error will be flagged
			//if (errorValue == GL_NO_ERROR)
			//{
			//	Utility::Log("Old fixed function code executed successfully.",
			//		Utility::Severity::Success);
			//}

			////otherwise OpenGL will flag an invalid operation error
			//else if (errorValue == GL_INVALID_OPERATION)
			//{
			//	Utility::Log("Old fixed function code could not run.",
			//		Utility::Severity::Failure);
			//}

			Utility::CheckGLError();

			isErrorChecked = true;
		}

		Screen::Instance()->Present();
	}

	Screen::Instance()->Shutdown();
	return 0;
}