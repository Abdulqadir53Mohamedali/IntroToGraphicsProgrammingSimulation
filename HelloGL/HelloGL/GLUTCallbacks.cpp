#include "GLUTCallbacks.h"

#include "HelloGL.h"



namespace GLUTCallbacks {
	namespace{
		HelloGL* helloGL = nullptr;

	}
	void Init(HelloGL* gl) {
		helloGL = gl;

	}
	void Display() {
		if (helloGL != nullptr) {
			helloGL->Display();
		}
	}		
	void DisplayTriangles() {
		if (helloGL != nullptr) {
			helloGL->Display();
		}
	}
	
	void DrawPentagon() {
		if (helloGL != nullptr) {
			helloGL->DrawPentagon();
		}
	}
	void Timer(int preferredRefresh) {
		helloGL->Update();
		glutTimerFunc(preferredRefresh, GLUTCallbacks::Timer, preferredRefresh);
	}
}
//GLUTCallbacks::Init(this);