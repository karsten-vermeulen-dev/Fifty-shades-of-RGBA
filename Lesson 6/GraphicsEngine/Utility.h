#pragma once
#include <string>
#include <Windows.h>

class Utility
{

public:

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

	enum class Severity
	{
		Default = 8,
		Success = 2,
		Warning = 14,
		Failure = 4
	};

	//TODO - Add OpenGL debug callback function
	
	static void Initialize();
	
	//TODO - Allow logging output to a file
	static void Log(const std::string& message, 
		Severity severity = Severity::Default);
	
	static void DisplayGraphicsProfile();

	static void CheckGLError();

private:

	static HANDLE consoleHandle;

};