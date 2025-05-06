#pragma once

#include "SceneObject.h"
#include "Structures.h"

class Monkey : public SceneObject
{
private:
    Vector3 _position;
    GLfloat _rotation;

public:
    Monkey(Mesh* mesh, Texture2D* texture, float x, float y, float z);

    virtual ~Monkey();

    virtual void Update() override;
    virtual void Draw() override;



};

