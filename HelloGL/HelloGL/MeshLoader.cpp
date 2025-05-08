#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

/*<summary>


<summary>*/
namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadNormals(ifstream& inFile, Mesh& mesh);
	//void LoadColors(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);
	void LoadTexCoord(ifstream& inFile, Mesh& mesh);

	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}
	}

	void LoadNormals(ifstream& inFile, Mesh& mesh)
	{

		inFile >> mesh.NormalCount;

		if (mesh.NormalCount > 0)
		{
			mesh.Normals = new Vector3[mesh.NormalCount];
			for (int i = 0; i < mesh.NormalCount; i++) {
				inFile >> mesh.Normals[i].x >> mesh.Normals[i].y >> mesh.Normals[i].z;

			}
		}
	}/*	void LoadColours(ifstream& inFile, Mesh& mesh)
	{

		inFile >> mesh.ColorCount;

		if (mesh.ColorCount > 0)
		{
			mesh.Colors = new Color[mesh.ColorCount];
			for (int i = 0; i < mesh.ColorCount; i++) {
				inFile >> mesh.Colors[i].r >> mesh.Colors[i].g >> mesh.Colors[i].b;

			}
		}
	}*/
	void LoadTexCoord(ifstream& inFile, Mesh& mesh) {
		inFile >> mesh.TexCordCount;

		if (mesh.TexCordCount > 0)
		{
			mesh.TexCoords = new TexCoord[mesh.TexCordCount];
			for (int i = 0; i < mesh.TexCordCount; i++) {
				inFile >> mesh.TexCoords[i].u >> mesh.TexCoords[i].v;

			}
		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.IndexCount;

		if (mesh.IndexCount > 0) {
			mesh.Indicies = new GLushort[mesh.IndexCount];
			for (int i = 0; i < mesh.IndexCount; i++) {
				inFile >> mesh.Indicies[i];

			}
		}

	}

	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())
		{
			cerr << "Can't open texture file " << path << endl;
			return nullptr;
		}

		//}
		LoadVertices(inFile, *mesh);
		//if (path == "cube.txt") {
		LoadTexCoord(inFile, *mesh);
		LoadNormals(inFile, *mesh);

		LoadIndices(inFile, *mesh);
		//LOAD DATA USING METHODS ABOVE
		inFile.close();
		return mesh;
	}
}