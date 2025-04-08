#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "Cube.h"
#include "MeshLoader.h"


#define REFRESHRATE 16
const int preferredRefresh = 16;

class HelloGL
{

private:
	float rotationTraingle;
	float rotationRect;
	float rotation;

	Vector4* _lightPosition;
	Material* _material;

	Lighting* _lightData;
	Camera* camera;
	SceneObject* objects[500];



public:

	HelloGL(int argc, char* argv[]);
	void InitObjects();
	void InitLighting();
	void InitMaterial();
	void InitGl(int argc, char* argv[]);
	void Display();
	void Keyboard(unsigned char key, int x, int y);
	void Update();
	~HelloGL(void);
	
};

