#include "HelloGL.h"
#include "GLUTCallbacks.h"

Vertex HelloGL::vertices[] = { 1, 1, 1, -1, 1, 1, -1,-1, 1, // v0-v1-v2 (front)

-1,-1, 1, 1,-1, 1, 1, 1, 1, // v2-v3-v0


1, 1, 1, 1,-1, 1, 1,-1,-1, // v0-v3-v4 (right)

1,-1,-1, 1, 1,-1, 1, 1, 1, // v4-v5-v0


1, 1, 1, 1, 1,-1, -1, 1,-1, // v0-v5-v6 (top)

-1, 1,-1, -1, 1, 1, 1, 1, 1, // v6-v1-v0


-1, 1, 1, -1, 1,-1, -1,-1,-1, // v1-v6-v7 (left)

-1,-1,-1, -1,-1, 1, -1, 1, 1, // v7-v2-v1


-1,-1,-1, 1,-1,-1, 1,-1, 1, // v7-v4-v3 (bottom)

1,-1, 1, -1,-1, 1, -1,-1,-1, // v3-v2-v7


1,-1,-1, -1,-1,-1, -1, 1,-1, // v4-v7-v6 (back)

-1, 1,-1, 1, 1,-1, 1,-1,-1 }; // v6-v5-v4
Color HelloGL::colors[] = { 1, 1, 1, 1, 1, 0, 1, 0, 0, // v0-v1-v2 (front)

1, 0, 0, 1, 0, 1, 1, 1, 1, // v2-v3-v0


1, 1, 1, 1, 0, 1, 0, 0, 1, // v0-v3-v4 (right)

0, 0, 1, 0, 1, 1, 1, 1, 1, // v4-v5-v0


1, 1, 1, 0, 1, 1, 0, 1, 0, // v0-v5-v6 (top)

0, 1, 0, 1, 1, 0, 1, 1, 1, // v6-v1-v0


1, 1, 0, 0, 1, 0, 0, 0, 0, // v1-v6-v7 (left)

0, 0, 0, 1, 0, 0, 1, 1, 0, // v7-v2-v1


0, 0, 0, 0, 0, 1, 1, 0, 1, // v7-v4-v3 (bottom)

1, 0, 1, 1, 0, 0, 0, 0, 0, // v3-v2-v7


0, 0, 1, 0, 0, 0, 0, 1, 0, // v4-v7-v6 (back)

0, 1, 0, 0, 1, 1, 0, 0, 1 }; // v6-v5-v4

Vertex HelloGL::indexedVertices[] = { 1, 1, 1, -1, 1, 1, // v0,v1,

-1,-1, 1, 1,-1, 1, // v2,v3

1,-1,-1, 1, 1,-1, // v4,v5

-1, 1,-1, -1,-1,-1 }; // v6,v7
Color HelloGL::indexedColors[] = { 1, 1, 1, 1, 1, 0, // v0,v1,

1, 0, 0, 1, 0, 1, // v2,v3

0, 0, 1, 0, 1, 1, // v4,v5

0, 1, 0, 0, 0, 0 }; //v6,v7
GLushort HelloGL::indices[] = { 0, 1, 2, 2, 3, 0, // front

0, 3, 4, 4, 5, 0, // right

0, 5, 6, 6, 1, 0, // top

1, 6, 7, 7, 2, 1, // left

7, 4, 3, 3, 2, 7, // bottom

4, 7, 6, 6, 5, 4 }; // back


HelloGL::HelloGL(int argc, char* argv[]) 
{
    rotation = 0.0f;
    rotationRect = 0.0f;
    rotationTraingle = 0.0f;
    
    camera = new Camera();
    camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;

    //camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
    camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
    camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	GLUTCallbacks::Init(this);

 	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
    glutKeyboardFunc(GLUTCallbacks::Keyboard);

    glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE); // How long timer should wait before calling method | Method that should be called upon this  || Parameter passwed in to timer function
    
    // Changes matrix mode to projectin matrixs
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Sets the viewport to be the entire window 
    glViewport(0, 0, 800, 800);
    
    // Sets the correct perspective
        //  45 is the field of view,
        // 1 is the aspect ratio (a square window)
        // the next 1 is the front clipping plane. This can be set to zero, but this is not usually done. Note, anything a distance of 1 from the camera (between zero and 1) won’t be visible. You could set this to 0.5 for example?
        // 1000 is the far clipping plane, nothing past 1000 units from the camera will be drawn
    gluPerspective(45, 1, 0, 1000);

    // Switches us back to the model view matrix
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

	glutMainLoop();

}
void HelloGL::Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(rotationTraingle, 1.0f, 0.0f, 0.0f);
    DrawIndexedCubeAlt();
    glPopMatrix();

    ///*glPushMatrix();
    //this->DrawRectangle();

    //glPopMatrix();

    //glPushMatrix();
    //this->DrawSqaure();

    //glPopMatrix();*/

    //glPushMatrix();
    //this->DrawTriangle();

    //glPopMatrix();

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
    glTranslatef(0.6f, 0.0f, -5.0f);  // Move triangle to right
    glRotatef(rotationTraingle, 1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.2f, -0.2f);
    glVertex2f(0.0f, 0.2f);
    glEnd();

}
void HelloGL::DrawSqaure() {

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
    }if (key == 'z') {
        camera->eye.z +=0.1f;

    }if (key == 'q') {
        camera->eye.z -=0.1f;

    }if (key == 'e') {
        camera->eye.y +=0.1f;

    }if (key == 'u') {
        camera->eye.y -=0.1f;

    }
}

void HelloGL::DrawCube()

{

    glBegin(GL_TRIANGLES);

    // face v0-v1-v2

    glColor3f(1, 1, 1);

    glVertex3f(1, 1, 1);

    glColor3f(1, 1, 0);

    glVertex3f(-1, 1, 1);

    glColor3f(1, 0, 0);

    glVertex3f(-1, -1, 1);

    // face v2-v3-v0

    glColor3f(1, 0, 0);

    glVertex3f(-1, -1, 1);

    glColor3f(1, 0, 1);

    glVertex3f(1, -1, 1);

    glColor3f(1, 1, 1);

    glVertex3f(1, 1, 1);

    // face v0-v3-v4

    glColor3f(1, 1, 1);

    glVertex3f(1, 1, 1);

    glColor3f(1, 0, 1);

    glVertex3f(1, -1, 1);

    glColor3f(0, 0, 1);

    glVertex3f(1, -1, -1);

    // face v4-v5-v0

    glColor3f(0, 0, 1);

    glVertex3f(1, -1, -1);

    glColor3f(0, 1, 1);

    glVertex3f(1, 1, -1);

    glColor3f(1, 1, 1);

    glVertex3f(1, 1, 1);


    // face v0-v5-v6

    glColor3f(1, 1, 1);

    glVertex3f(1, 1, 1);

    glColor3f(0, 1, 1);

    glVertex3f(1, 1, -1);

    glColor3f(0, 1, 0);

    glVertex3f(-1, 1, -1);

    // face v6-v1-v0

    glColor3f(0, 1, 0);

    glVertex3f(-1, 1, -1);

    glColor3f(1, 1, 0);

    glVertex3f(-1, 1, 1);

    glColor3f(1, 1, 1);

    glVertex3f(1, 1, 1);


    // face v1-v6-v7

    glColor3f(1, 1, 0);

    glVertex3f(-1, 1, 1);

    glColor3f(0, 1, 0);

    glVertex3f(-1, 1, -1);

    glColor3f(0, 0, 0);

    glVertex3f(-1, -1, -1);

    // face v7-v2-v1

    glColor3f(0, 0, 0);

    glVertex3f(-1, -1, -1);

    glColor3f(1, 0, 0);

    glVertex3f(-1, -1, 1);

    glColor3f(1, 1, 0);

    glVertex3f(-1, 1, 1);


    // face v7-v4-v3

    glColor3f(0, 0, 0);

    glVertex3f(-1, -1, -1);

    glColor3f(0, 0, 1);

    glVertex3f(1, -1, -1);

    glColor3f(1, 0, 1);

    glVertex3f(1, -1, 1);

    // face v3-v2-v7

    glColor3f(1, 0, 1);

    glVertex3f(1, -1, 1);

    glColor3f(1, 0, 0);

    glVertex3f(-1, -1, 1);

    glColor3f(0, 0, 0);

    glVertex3f(-1, -1, -1);


    // face v4-v7-v6

    glColor3f(0, 0, 1);

    glVertex3f(1, -1, -1);

    glColor3f(0, 0, 0);

    glVertex3f(-1, -1, -1);

    glColor3f(0, 1, 0);

    glVertex3f(-1, 1, -1);

    // face v6-v5-v4

    glColor3f(0, 1, 0);

    glVertex3f(-1, 1, -1);

    glColor3f(0, 1, 1);

    glVertex3f(1, 1, -1);

    glColor3f(0, 0, 1);

    glVertex3f(1, -1, -1);


    glEnd();

}
void HelloGL::DrawCubeArray() {
    //glPushMatrix();
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 36; i++) {
        glColor3fv(&colors[i].r);
        glVertex3fv(&vertices[i].x);
    }
    glEnd();
    //glPopMatrix();

}
void HelloGL::DrawIndexedCube() {
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 36; i++) {
        glColor3f(colors[i].r, colors[i].g, colors[i].b);
        glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
    }
    glEnd();
}
void HelloGL::DrawCubeArrayAlt()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    glPushMatrix();
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glPopMatrix();

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void HelloGL::DrawIndexedCubeAlt()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
    glColorPointer(3, GL_FLOAT, 0, indexedColors);

    glPushMatrix();
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
    glPopMatrix();

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void HelloGL::Update() {


    //rotationRect += 4.0f;   // Rectangle rotates fast
    //rotation += 1.0f; // Square rotates medium speed
    
    //rotationTraingle += 0.5f; // Triangle rotates slowly 


    //Sleep(10);

    // Resets ModelViewMatric in every frame , so transfromations fromt he previous don't get included in the current one 
    glLoadIdentity();
    gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);

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