#pragma once
#include "Structures.h"

/*<summary>


<summary>*/
class Texture2D
{

private:
	GLuint _ID;
	int _width, _height;


public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);


	GLint GetID() const { return _ID; }
	int GetWidth() const { return _width;  }
	int GetHeight() const { return _height; }
};

