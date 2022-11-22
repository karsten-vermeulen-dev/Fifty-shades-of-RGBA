#include <fstream>
#include "Shader.h"
#include "Utility.h"

GLint Shader::vertexShaderID = 0;
GLint Shader::fragmentShaderID = 0;

bool Shader::Initialize()
{
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

	if (vertexShaderID == 0)
	{
		Utility::Log("Error creating vertex shader object. Possible causes could be a "
			"very old graphics card that does not support modern OpenGL.",
			Utility::Severity::Failure);
		return false;
	}

	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	if (fragmentShaderID == 0)
	{
		Utility::Log("Error creating fragment shader object. Possible causes could be a "
			"very old graphics card that does not support modern OpenGL.",
			Utility::Severity::Failure);
		return false;
	}

	return true;
}

void Shader::Shutdown()
{
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}

bool Shader::Create(const std::string& vertexFilename, const std::string& fragmentFilename)
{
	programID = glCreateProgram();

	//If the shader program ID is 0 it means an error occurred. Possible causes are 
	//that GLAD has not been set up properly yet or your graphics card is very old
	if (programID == 0)
	{
		Utility::Log("Error creating shader program. Possible causes could be a "
			"very old graphics card that does not support modern OpenGL.",
			Utility::Severity::Failure);
		return false;
	}

	if (!CompileShaders(vertexFilename))
	{
		return false;
	}

	if (!CompileShaders(fragmentFilename))
	{
		return false;
	}

	if (!LinkProgram())
	{
		return false;
	}

	return true;
}

void Shader::Use() const
{
	glUseProgram(programID);
}

void Shader::Destroy() const
{
	glDeleteProgram(programID);
}

bool Shader::LinkProgram()
{
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);
	glDetachShader(programID, vertexShaderID);
	glDetachShader(programID, fragmentShaderID);

	GLint result = 0;
	glGetProgramiv(programID, GL_LINK_STATUS, &result);

	if (result == GL_FALSE)
	{
		GLchar error[1000];
		GLsizei bufferSize = 1000;
		glGetProgramInfoLog(programID, bufferSize, &bufferSize, error);
		Utility::Log("Error linking shader program:", Utility::Severity::Failure);
		Utility::Log(error, Utility::Severity::Failure);
		return false;
	}

	return true;
}

bool Shader::CompileShaders(const std::string& filename)
{
	std::fstream file(filename, std::ios_base::in);

	if (!file.is_open())
	{
		Utility::Log("Error loading shader file \"" + (filename)+"\"."
			"Possible causes could be a corrupt or missing file. It could also be "
			"that the filename and/or path are incorrectly spelt.", Utility::Severity::Failure);
		return false;
	}

	std::string line;
	std::string sourceCode;

	while (!file.eof())
	{
		getline(file, line);
		sourceCode += line + "\n";
	}

	file.close();

	auto shaderID = 0;

	if (filename.find(".vert") != std::string::npos)
	{
		shaderID = vertexShaderID;
	}

	else
	{
		shaderID = fragmentShaderID;
	}

	const GLchar* finalCode = reinterpret_cast<const GLchar*>(sourceCode.c_str());
	glShaderSource(shaderID, 1, &finalCode, nullptr);
	glCompileShader(shaderID);

	GLint compileResult;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileResult);

	if (compileResult == GL_FALSE)
	{
		GLchar error[1000];
		GLsizei bufferSize = 1000;
		glGetShaderInfoLog(shaderID, bufferSize, &bufferSize, error);
		Utility::Log("Error compiling '" + filename + "':", Utility::Severity::Failure);
		Utility::Log(error, Utility::Severity::Failure);
		return false;
	}

	Utility::Log("'" + filename + "' compiled successfully.", Utility::Severity::Success);

	return true;
}