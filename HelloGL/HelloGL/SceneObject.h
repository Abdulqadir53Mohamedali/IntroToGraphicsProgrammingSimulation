#pragma once
#include "Structures.h"
#include "Texture2D.h"


class SceneObject
{
protected:
	Mesh* _mesh;
	Texture2D* _texture;

public :
	Vector3 _position;

	SceneObject(Mesh* mesh, Texture2D* texture);
	virtual ~SceneObject();
	virtual void Update();
	virtual void Draw();

};

