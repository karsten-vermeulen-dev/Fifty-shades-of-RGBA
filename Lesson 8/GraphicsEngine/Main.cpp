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

GLuint VBO{ 0 };

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

	GLfloat VBOData[] = { -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
						   0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
						  -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
						  -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
						   0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
						   0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f };

	auto vertexAttributeID = shader.GetAttributeID("vertexIn");
	auto colorAttributeID = shader.GetAttributeID("colorIn");

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VBOData), VBOData, GL_STATIC_DRAW);

	glVertexAttribPointer(vertexAttributeID, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
	glVertexAttribPointer(colorAttributeID, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

	glEnableVertexAttribArray(vertexAttributeID);
	glEnableVertexAttribArray(colorAttributeID);
	
	auto time = 0.0f;
	auto timeID = shader.GetUniformID("time");

	while (isAppRunning)
	{
		Screen::Instance()->Refresh();

		Input::Instance()->Update();

		if (Input::Instance()->IsXClicked())
		{
			isAppRunning = false;
		}

		time += 0.01f;
		shader.SendData("time", time);

		glDrawArrays(GL_TRIANGLES, 0, 6);

		Screen::Instance()->Present();
	}

	glDeleteBuffers(1, &VBO);
	glDisableVertexAttribArray(colorAttributeID);
	glDisableVertexAttribArray(vertexAttributeID);

	shader.Destroy();

	Shader::Shutdown();
	Screen::Instance()->Shutdown();

	return 0;
}