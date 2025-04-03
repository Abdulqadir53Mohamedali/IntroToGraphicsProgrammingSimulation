#pragma once
#include "SceneObject.h"
#include "Structures.h"

class Cube : public SceneObject
{
private :
	Vector3 _position;
	//static  Vertex* indexedvertices;
	//static  Color* indexedcolors;
	//static GLushort* indices;
	GLfloat _rotation;




public :
	static int numVertices, numColors, numIndicies;

	Cube(Mesh* mesh,Texture2D* texture,float x,float y,float z);
	~Cube();

	void Draw();
	static bool Load(char* path);
	void Update();
	void SetRotation();
};

