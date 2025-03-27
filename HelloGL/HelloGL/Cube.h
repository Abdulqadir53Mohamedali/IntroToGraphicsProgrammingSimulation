#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"

class Cube
{
private :
	Vector3 _position;
	static  Vertex* indexedVertices;
	static  Color* indexedColors;
	static GLushort* indices;
	GLfloat _rotation;



public :
	static int numVertices, numColors, numIndicies;

	Cube(float x,float y,float z);
	~Cube();

	void Draw();
	static bool Load(char* path);
	void Update();
	void SetRotation();
};

