#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

/*<summary>


<summary>*/
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

struct Vector4 {
	float x, y, z,w;

};

struct Lighting {
	Vector4 Ambient;
	Vector4 Diffuse;
	Vector4 Specular;

};

struct Material {
	Vector4 Ambient;
	Vector4 Diffuse;
	Vector4 Specular;
	GLfloat Shininess;
};
struct Mesh {
	Vertex* Vertices;
	//Color* Colors;
	Vector3* Normals;
	GLushort* Indicies;
	int TexCordCount, VertexCount, NormalCount, IndexCount;

	TexCoord* TexCoords;
};

//struct ObjectNode {
//	SceneObject* object;// data 
//	ObjectNode* next;
//};

