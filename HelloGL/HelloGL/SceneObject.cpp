#include "SceneObject.h"
/*<summary>


<summary>*/
SceneObject::SceneObject(Mesh* mesh,Texture2D* texture) {
	_mesh = mesh;
	_texture = texture;

	
}
SceneObject::~SceneObject()
{
}

void SceneObject::Update()
{
}

void SceneObject::Draw()
{
}