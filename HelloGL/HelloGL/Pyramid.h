#pragma once
#include "SceneObject.h"
#include "Structures.h"

class Pyramid : public SceneObject
{
private:
    Vector3 _position;
    GLfloat _rotation;

public:
    Pyramid(Mesh* mesh,Texture2D* texture, float x, float y, float z);

    virtual ~Pyramid();

    virtual void Update() override;
    virtual void Draw() override;
};
