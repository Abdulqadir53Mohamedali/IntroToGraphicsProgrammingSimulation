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

/*<summary>


<summary>*/
class HelloGL
{

private:
	Vector4* _lightPosition;
	Material* _material;

	Lighting* _lightData;
	Camera* camera;
	SceneObject* objects[700];



public:

	HelloGL(int argc, char* argv[]);
	void InitObjects();
	void InitLighting();
	void InitMaterial();
	void InitGl(int argc, char* argv[]);
	void Draw();
	void DrawString(const char* text, Vector3* position, Color*);
	void Display();
	void Keyboard(unsigned char key, int x, int y);
	void Update();
	~HelloGL(void);
	
};

