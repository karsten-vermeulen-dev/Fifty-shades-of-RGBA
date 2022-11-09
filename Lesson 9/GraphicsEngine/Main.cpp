#include <iostream>
#include <math.h>
#include "Input.h"
#include "Screen.h"
#include "Shader.h"
#include "Utility.h"

Shader shader;
bool isAppRunning{ true };

GLuint VAO{ 0 };
GLuint EBO{ 0 };
GLuint vertexVBO{ 0 };
GLuint colorVBO{ 0 };

int main(int argc, char* argv[])
{
	Utility::Initialize();

	if (!Screen::Instance()->Initialize(1280, 720, 4.6f, true))
	{
		return 0;
	}

	Screen::Instance()->SetColor(0.15f, 0.15f, 0.15f);

	Shader::Initialize();

	shader.Create("Shaders/Main.vert", "Shaders/Main.frag");
	shader.Use();

	GLfloat vertices[] = { -0.5f,  0.5f, 0.0f,
							0.5f,  0.5f, 0.0f,
							0.5f, -0.5f, 0.0f,
						   -0.5f, -0.5f, 0.0f };

	GLfloat colors[] = { 1.0f, 0.0f, 0.0f,
						 0.0f, 0.0f, 1.0f,
						 0.0f, 1.0f, 0.0f,
						 0.0f, 1.0f, 1.0f };

	GLuint indices[] = { 0, 1, 3,
						 3, 1, 2 };

	auto vertexAttributeID = shader.GetAttributeID("vertexIn");
	auto colorAttributeID = shader.GetAttributeID("colorIn");

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &vertexVBO);
	glGenBuffers(1, &colorVBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(vertexAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertexAttributeID);

	glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
	glVertexAttribPointer(colorAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(colorAttributeID);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);

	while (isAppRunning)
	{
		Screen::Instance()->Refresh();

		Input::Instance()->Update();

		if (Input::Instance()->IsXClicked())
		{
			isAppRunning = false;
		}

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		Screen::Instance()->Present();
	}

	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &colorVBO);
	glDeleteBuffers(1, &vertexVBO);
	glDeleteVertexArrays(1, &VAO);

	glDisableVertexAttribArray(colorAttributeID);
	glDisableVertexAttribArray(vertexAttributeID);

	shader.Destroy();

	Shader::Shutdown();
	Screen::Instance()->Shutdown();

	return 0;
}