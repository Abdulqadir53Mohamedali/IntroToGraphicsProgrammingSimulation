#include "Cube.h"
#include "GLUTCallbacks.h"
#include <iostream>
#include <fstream>


Cube::Cube(Mesh* mesh,Texture2D* texture, float x, float y, float z) : SceneObject(mesh,texture){
    _rotation = 0.0;
    _position.x = x;
    _position.y = y;
    _position.z = z;
}

/*<summary>


<summary>*/
int Cube::numVertices = 0;
int Cube::numColors = 0;
int Cube::numIndicies = 0;

/*<summary>


<summary>*/
void Cube::Draw() 
{
    if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indicies != nullptr) {
 
        glPushMatrix();

        glTranslatef(_position.x, _position.y, _position.z);
        glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
        glBindTexture(GL_TEXTURE_2D, _texture->GetID());
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
 
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        //glEnableClientState(GL_COLOR_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
        //glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);

        glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);
        glNormalPointer(GL_FLOAT, 0, _mesh -> Normals);
        glPushMatrix();
        glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indicies);
        glPopMatrix();

        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glPopMatrix();
    }

}
/*<summary>


<summary>*/
void Cube::Update() {
    _rotation += 1.0;

}

// In Cube.cpp
Cube::~Cube()
{
}
