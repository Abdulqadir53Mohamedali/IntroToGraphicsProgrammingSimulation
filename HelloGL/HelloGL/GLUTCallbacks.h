#pragma once
class HelloGL;

namespace GLUTCallbacks {
	void Init(HelloGL* gl);
	void Display();
    void DisplayTriangles();
	void DrawPentagon();
	void Timer(int preferredRefresh);
}