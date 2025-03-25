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
	static  Vertex indexedVertices[];
	static  Color indexedColors[];
	static GLushort indices[];
	GLfloat _rotation;



public :
	Cube(float x,float y,float z);
	~Cube();

	void Draw();
	void Update();
	void SetRotation();
};

