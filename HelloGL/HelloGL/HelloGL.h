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
struct Color {
	GLfloat r, g, b;
};
struct Vertex {
	GLfloat x,y,z;
};



class HelloGL
{

private:
	float rotationTraingle;
	float rotationRect;
	float rotation;
	Camera* camera;
	static  Vertex vertices[];
	static  Color colors[];	

	static  Vertex indexedVertices[];
	static  Color indexedColors[];
	static GLushort indices[];

public:

	HelloGL(int argc, char* argv[]);
	void Display();
	void DrawCubeArray();
	void DrawCube();
	void DrawIndexedCube();
	void DisplayTriangles();
	void DrawTriangle();
	void DrawRectangle();
	void DrawSqaure();
	void DrawPentagon();
	void Keyboard(unsigned char key, int x, int y);
	void Update();
	~HelloGL(void);
	
};

