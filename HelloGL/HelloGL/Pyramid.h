#pragma once
#include "SceneObject.h"
#include "Structures.h"

class Pyramid : public SceneObject
{
private:
    Vector3 _position;

public:
    Pyramid(Mesh* mesh, float x, float y, float z);

    virtual ~Pyramid() {}

    virtual void Update() override;
    virtual void Draw() override;
};
