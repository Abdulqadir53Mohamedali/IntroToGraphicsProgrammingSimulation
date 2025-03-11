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
	float rotation;
public:

	HelloGL(int argc, char* argv[]);
	void Display();
	void DisplayTriangles();
	void DrawPentagon();
	void Update();
	~HelloGL(void);
	
};

