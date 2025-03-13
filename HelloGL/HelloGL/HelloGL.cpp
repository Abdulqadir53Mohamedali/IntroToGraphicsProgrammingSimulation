#include "HelloGL.h"
#include "GLUTCallbacks.h"

HelloGL::HelloGL(int argc, char* argv[]) 
{
    rotation = 0.0f;
    rotationRect = 0.0f;
    rotationTraingle = 0.0f;

	GLUTCallbacks::Init(this);

 	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
    glutKeyboardFunc(GLUTCallbacks::Keyboard);

    glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE); // How long timer should wait before calling method | Method that should be called upon this  || Parameter passwed in to timer function


	glutMainLoop();

}
void HelloGL::Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    /*glPushMatrix();
    this->DrawRectangle();

    glPopMatrix();

    glPushMatrix();
    this->DrawSqaure();

    glPopMatrix();*/

    glPushMatrix();
    this->DrawTriangle();

    glPopMatrix();

    glFlush(); 
    glutSwapBuffers();

}
 
void DrawTriangles() {
    //// --- Scalene Triangle (all sides different) ---
//glBegin(GL_TRIANGLES);
//    glColor3f(1.0f, 0.0f, 0.0f);  // Red
//    glVertex2f(-0.9f, -0.4f);
//    glVertex2f(-0.7f, -0.4f);
//    glVertex2f(-0.85f, -0.1f);
//glEnd();

//// --- Isosceles Triangle (two sides equal) ---
//glBegin(GL_TRIANGLES);
//    glColor3f(0.0f, 1.0f, 0.0f);  // Green
//    glVertex2f(-0.6f, -0.4f);
//    glVertex2f(-0.4f, -0.4f);
//    glVertex2f(-0.5f,  0.0f);
//glEnd();

//// --- Equilateral Triangle (all sides same length) ---
//glBegin(GL_TRIANGLES);
//    glColor3f(0.0f, 0.0f, 1.0f);  // Blue
//    glVertex2f(-0.3f, -0.4f);
//    glVertex2f(-0.1f, -0.4f);
//    glVertex2f(-0.2f, -0.2f); 
//glEnd();

//// --- Acute Triangle (all angles < 90°) ---
//glBegin(GL_TRIANGLES);
//    glColor3f(1.0f, 1.0f, 0.0f);  // Yellow
//    glVertex2f( 0.0f, -0.4f);
//    glVertex2f( 0.2f, -0.4f);
//    glVertex2f( 0.25f, -0.2f);
//glEnd();

//// --- Right Triangle (one angle = 90°) ---
//glBegin(GL_TRIANGLES);
//    glColor3f(0.0f, 1.0f, 1.0f);  // Cyan
//    glVertex2f(0.4f, -0.4f);
//    glVertex2f(0.6f, -0.4f);
//    glVertex2f(0.4f, -0.2f);
//glEnd();

//// --- Obtuse Triangle (one angle > 90°) ---
//glBegin(GL_TRIANGLES);
//    glColor3f(1.0f, 0.0f, 1.0f);  // Magenta
//    // Coordinates arranged so that one angle is clearly obtuse
//    glVertex2f(0.75f, -0.4f);
//    glVertex2f(1.00f, -0.4f);
//    glVertex2f(0.70f, -0.3f);
//glEnd();
}
void HelloGL::DrawTriangle() {
    glTranslatef(0.6f, 0.0f, 0.0f);  // Move triangle to right
    glRotatef(rotationTraingle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.0f, 0.2f);
    glEnd();

}void HelloGL::DrawSqaure() {

    glTranslatef(0.0f, 0.0f, 0.0f); // Centered square
    glColor3f(1.0f, 0.0f, 0.0f);  // Red
    glRotatef(rotation, 0.0f, 0.0f, -1.0f);   // rotates by rotation vlue upon the z-axis 
    glBegin(GL_POLYGON);
    glVertex2f(-0.2, 0.2); // top-left
    glVertex2f(0.2, 0.2); // top-right
    glVertex2f(0.2, -0.2);// bottom-right
    glVertex2f(-0.2, -0.2); // bottom-left
    glEnd();
}
void HelloGL::DrawRectangle() {
    glTranslatef(-0.7f, 0.0f, 0.0f);  // Move rectangle to left
    glRotatef(rotationRect, 0.0f, 0.0f, 1.0f); // Rotate
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.3f, 0.15f);
    glVertex2f(0.3f, 0.15f);
    glVertex2f(0.3f, -0.15f);
    glVertex2f(-0.3f, -0.15f);
    glEnd();
}
void HelloGL::DrawPentagon() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);

        glColor3f(1.0f, 1.0f, 0.0f);

        glVertex2f(0.4f, 0.6f);   // Top
        
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.57f, 0.18f);  // Right-top

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.75f, -0.48f); // Right-bottom
        glVertex2f(-0.35f, -0.48f); // Left-bottom
        glVertex2f(-0.57f, 0.18f);  // Left-top
    glEnd();
    glFlush();

}
void HelloGL::Keyboard(unsigned char key, int x, int y) {
    if (key == 'd') {
        rotationTraingle += 2.5f;

    }if (key == 'a') {
        rotationTraingle -= 2.0f;
    }
}


void HelloGL::Update() {


    //rotationRect += 4.0f;   // Rectangle rotates fast
    //rotation += 1.0f; // Square rotates medium speed
    
    //rotationTraingle += 0.5f; // Triangle rotates slowly 


    //Sleep(10);

    if (rotation >= 360.0f) {
        rotation = 0.0f;
    }
    if (rotationRect >= 360.0f) 
    {
        rotationRect = 0.0f;
    }
    if (rotationTraingle >= 360.0f) 
    {
        rotationTraingle = 0.0f;
;   }

    glutPostRedisplay();// causes scene to redraw itself after the update has finishe

}

HelloGL::~HelloGL(void) {

}