#pragma once
#include <string>
#include <Windows.h>

class Utility
{

public:

	//TODO - Do we really need these beyond the first two lessons?
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

	static void Initialize();
	
	static void Log(const std::string& message, 
		Severity severity = Severity::Default);
	
	static void DisplayGraphicsProfile();

	static void CheckGLError();

private:

	static HANDLE consoleHandle;

};