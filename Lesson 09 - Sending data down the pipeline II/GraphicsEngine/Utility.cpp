#include <assert.h>
#include <iostream>
#include "gl.h"
#include "Utility.h"

HANDLE Utility::consoleHandle{ nullptr };

void Utility::Initialize()
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Utility::Log(const std::string& message, Severity severity)
{
	//Did you forget to call Initialize()?
	assert(consoleHandle);

	SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(severity));
	std::cout << message << std::endl;
	SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(Severity::Default));
}

void Utility::DisplayGraphicsProfile()
{
	std::cout << "Graphics card vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Graphics card model: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void Utility::CheckGLError()
{
	//This will return the first error that 
	//occured since this function was last called
	GLenum errorCode = glGetError();

	switch (errorCode)
	{

	case GL_NO_ERROR:
	{
		Log("There are no errors.", Severity::Success);
		break;
	}

	case GL_INVALID_ENUM:
	{
		Log("Invalid enumeration type passed.", Severity::Failure);
		break;
	}

	case GL_INVALID_VALUE:
	{
		Log("Numeric value outside of accepted range.", Severity::Failure);
		break;
	}

	case GL_INVALID_OPERATION:
	{
		Log("Invalid operation.", Severity::Failure);
		break;
	}

	case GL_INVALID_FRAMEBUFFER_OPERATION:
	{
		Log("Framebuffer object incomplete.", Severity::Failure);
		break;
	}

	case GL_STACK_OVERFLOW:
	{
		Log("Stack overflow.", Severity::Failure);
		break;
	}

	case GL_STACK_UNDERFLOW:
	{
		Log("Stack underflow.", Severity::Failure);
		break;
	}

	case GL_OUT_OF_MEMORY:
	{
		Log("Out of memory.", Severity::Failure);
		break;
	}
	}
}