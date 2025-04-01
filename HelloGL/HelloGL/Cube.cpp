#include "Cube.h"
#include "GLUTCallbacks.h"
#include <iostream>
#include <fstream>


Cube::Cube(Mesh* mesh,float x, float y, float z) : SceneObject(mesh){
    _rotation = 0.0;
    _position.x = x;
    _position.y = y;
    _position.z = z;
}
//Vertex Cube::indexedVertices[] = { 1, 1, 1, -1, 1, 1, // v0,v1,
//
//-1,-1, 1, 1,-1, 1, // v2,v3
//
//1,-1,-1, 1, 1,-1, // v4,v5
//
//-1, 1,-1, -1,-1,-1 }; // v6,v7
//Color Cube::indexedColors[] = { 1, 1, 1, 1, 1, 0, // v0,v1,
//
//1, 0, 0, 1, 0, 1, // v2,v3
//
//0, 0, 1, 0, 1, 1, // v4,v5
//
//0, 1, 0, 0, 0, 0 }; //v6,v7
//GLushort Cube::indices[] = { 0, 1, 2, 2, 3, 0, // front
//
//0, 3, 4, 4, 5, 0, // right
//
//0, 5, 6, 6, 1, 0, // top
//
//1, 6, 7, 7, 2, 1, // left
//
//7, 4, 3, 3, 2, 7, // bottom
//
//4, 7, 6, 6, 5, 4 }; // back

//Vertex* Cube::indexedVertices = nullptr;
//Color* Cube::indexedColors = nullptr;
//GLushort* Cube::indices = nullptr;

int Cube::numVertices = 0;
int Cube::numColors = 0;
int Cube::numIndicies = 0;


void Cube::Draw() 
{
    if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indicies != nullptr) {
        glPushMatrix();
        glTranslatef(_position.x, _position.y, _position.z);
        glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
        glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);

        glPushMatrix();
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indicies);
        glPopMatrix();

        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);

        glPopMatrix();
    }

}
//bool Cube::Load(char* path) {
//    std::ifstream inFile;
//    inFile.open(path);
//    if (!inFile.good()) {
//        std::cerr << "Can't open text file" << path << std::endl;
//        return false;
//    }
//    inFile >> numVertices;
//    indexedVertices = new Vertex[numVertices];
//    for (int i = 0; i < numVertices; i++) {
//        inFile >> indexedVertices[i].x>> indexedVertices[i].y>> indexedVertices[i].z;
//    }  
//    inFile >> numColors;
//    indexedColors = new Color[numColors];
//    for (int i = 0; i < numColors; i++) {
//        inFile >> indexedColors[i].r>> indexedColors[i].g>> indexedColors[i].b;
//
//    }  
//    inFile >> numIndicies;
//    indices = new GLushort[numIndicies];
//    for (int i = 0; i < numIndicies; i++) {
//        inFile >> indices[i];
//
//    }
//    inFile.close();
//
//    return true;
//}
void Cube::Update() {
    _rotation += 1.0;

}

// In Cube.cpp
Cube::~Cube()
{
}
