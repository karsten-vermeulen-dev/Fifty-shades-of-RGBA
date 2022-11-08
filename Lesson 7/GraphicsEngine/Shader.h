#pragma once

#include "gl.h"
#include <string>

class Shader
{

public:

	static bool Initialize();
	static void Shutdown();

	bool Create(const std::string& vertexFilename,
		const std::string& fragmentFilename);

	void Use() const;
	void Destroy() const;

private:

	static GLint vertexShaderID;
	static GLint fragmentShaderID;

	bool LinkProgram();
	bool CompileShaders(const std::string& filename);

	GLuint programID{ 0 };
};