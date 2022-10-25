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

//OLD CODE - WIP
////********************************
//	//display graphics card profile
//	//********************************
//
//	//display the manufacturer of the graphics hardware 
//std::cout << (const char*)(glGetString(GL_VENDOR)) << std::endl;
//
////display the make and model of the graphics card 
//std::cout << (const char*)(glGetString(GL_RENDERER)) << std::endl;
//
////display the current OpenGL version and mode set 
//std::cout << (const char*)(glGetString(GL_VERSION)) << std::endl;
//
////**********************************
////set up extensions manually
////**********************************
//
////create pointer to function
//PFNGLGETSTRINGIPROC glGetStringi = nullptr;
//
////assign address of function to pointer using Windows platform-specific function
//glGetStringi = (PFNGLGETSTRINGIPROC)wglGetProcAddress("glGetStringi");
//
////check for errors otherwise go ahead and use the extension function
//if (glGetStringi == nullptr)
//{
//	std::cout << "Extension function not supported by your graphics card." << std::endl;
//}
//
//else
//{
//
//	//get total number of extensions supported by our graphics card
//	GLint totalExtensions;
//	glGetIntegerv(GL_NUM_EXTENSIONS, &totalExtensions);
//
//	//loop through all extensions and display them
//	for (GLint i = 0; i < totalExtensions; i++)
//	{
//		std::cout << "Extension #" << i + 1 << ": "
//			<< (const char*)glGetStringi(GL_EXTENSIONS, i) << std::endl;
//	}
//
//}
//
////try load a function exclusive ONLY to the OpenGL 4.5 context 
////on some older cards, this might not work and so we only use
////the function if it's supported and display an error if not
//
//PFNGLBINDTEXTUREUNITPROC glBindTexUnit = nullptr;
//glBindTexUnit = (PFNGLBINDTEXTUREUNITPROC)wglGetProcAddress("glBindTextureUnit");
//
//if (glBindTexUnit)
//{
//	glBindTexUnit(0, 0);
//}
//
//else
//{
//	std::cout << "Your graphics card is too old!" << std::endl;
//}

//=======================================================================

////**********************************
//	//set up extensions using GLAD
//	//**********************************
//
//if (!gladLoadGL())
//{
//	std::cout << "Failed to initialize GLAD" << std::endl;
//	system("pause");
//	return 0;
//}
//
////get total number of extensions supported by our graphics card
//GLint totalExtensions;
//glGetIntegerv(GL_NUM_EXTENSIONS, &totalExtensions);
//
////loop through all extensions and display them
//for (GLint i = 0; i < totalExtensions; i++)
//{
//	std::cout << "Extension #" << i + 1 << ": "
//		<< (const char*)glGetStringi(GL_EXTENSIONS, i) << std::endl;
//}
//
////********************************
////display graphics card profile
////********************************
//
////display the manufacturer of the graphics hardware 
//std::cout << (const char*)(glGetString(GL_VENDOR)) << std::endl;
//
////display the make and model of the graphics card 
//std::cout << (const char*)(glGetString(GL_RENDERER)) << std::endl;
//
////display the current OpenGL version and mode set 
//std::cout << (const char*)(glGetString(GL_VERSION)) << std::endl;
//
////display which GLSL version is supported by the graphics card
//std::cout << (const char*)(glGetString(GL_SHADING_LANGUAGE_VERSION)) << std::endl;