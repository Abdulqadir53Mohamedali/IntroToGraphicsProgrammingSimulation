// This only loads **RAW** files , get the tgaLoader from blackbaord to load other types in 

#include "Texture2D.h"
#include "MeshLoader.h"
#include <iostream>
#include <fstream>
using namespace std;

/*<summary>


<summary>*/
bool Texture2D::Load(char* path, int width, int height) {
	char* tempTextureData; 
	int fileSize; 
	ifstream inFile;

	_width = width; 
	_height = height;

	inFile.open(path, ios::binary);

	if (!inFile.good()) {
		std::cerr << "Can't open texture file " << path << "\n";
		return false;
	}

	inFile.seekg(0, ios::end); // Seek to end of file
	fileSize = (int)inFile.tellg(); // Get current poistion in file - The End, this gives  the total file size
	tempTextureData = new char[fileSize]; // Creates a new array to store data 
	inFile.seekg(0, ios::beg); // Seek back to beggining of file 
	inFile.read(tempTextureData, fileSize); // Read in all the data in one go 
	inFile.close(); // Closes the file

	cout << path << " loaded." << "\n";

	glGenTextures(1, &_ID); // Get next Texture ID
	glBindTexture(GL_TEXTURE_2D, _ID); // Bind texture to the ID
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData); // Specify details of the texture image
	
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	delete[] tempTextureData; // Clears up the data that is unused / not needed anymore 
	return true;


}
Texture2D::Texture2D(){

}
Texture2D::~Texture2D() {
	glDeleteTextures(1, &_ID);
}
