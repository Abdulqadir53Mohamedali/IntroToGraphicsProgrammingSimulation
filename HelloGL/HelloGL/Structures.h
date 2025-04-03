#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

struct Vector3 {

	float x, y, z;
};
struct Camera {

	Vector3 eye;
	Vector3 center;
	Vector3 up;
};
struct Color {
	GLfloat r, g, b;
};
struct Vertex {
	GLfloat x, y, z;
};

struct TexCoord {
	GLfloat u;
	GLfloat v;
};
struct Mesh {
	Vertex* Vertices;
	Color* Colors;
	GLushort* Indicies;
	int TexCordCount, VertexCount, ColorCount, IndexCount;

	TexCoord* TexCoords;
};