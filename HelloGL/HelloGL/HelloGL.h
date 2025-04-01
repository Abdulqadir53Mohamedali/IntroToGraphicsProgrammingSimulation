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
	Camera* camera;
	SceneObject* objects[1000];



public:

	HelloGL(int argc, char* argv[]);
	void InitObjects();
	void InitGl(int argc, char* argv[]);
	void Display();
	void Keyboard(unsigned char key, int x, int y);
	void Update();
	~HelloGL(void);
	
};

