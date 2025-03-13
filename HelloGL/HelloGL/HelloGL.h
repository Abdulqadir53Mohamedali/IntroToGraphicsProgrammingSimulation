#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

#define REFRESHRATE 16
const int preferredRefresh = 16;


class HelloGL
{

private:
	float rotationTraingle;
	float rotationRect;
	float rotation;
public:

	HelloGL(int argc, char* argv[]);
	void Display();
	void DisplayTriangles();
	void DrawTriangle();
	void DrawRectangle();
	void DrawSqaure();
	void DrawPentagon();
	void Keyboard(unsigned char key, int x, int y);
	void Update();
	~HelloGL(void);
	
};

