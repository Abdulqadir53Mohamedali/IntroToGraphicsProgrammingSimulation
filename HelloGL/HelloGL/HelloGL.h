#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

#define REFRESHRATE 16
const int preferredRefresh = 16;

struct Vector3 {
 
	float x, y, z;
};
struct Camera{
 
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};



class HelloGL
{

private:
	float rotationTraingle;
	float rotationRect;
	float rotation;
	Camera* camera;
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

