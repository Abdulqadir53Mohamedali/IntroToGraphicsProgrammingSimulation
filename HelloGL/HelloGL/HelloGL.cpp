#include "HelloGL.h"
#include "GLUTCallbacks.h"






HelloGL::HelloGL(int argc, char* argv[]) 
{/*
    rotation = 0.0f;
    rotationRect = 0.0f;
    rotationTraingle = 0.0f;*/
    
    camera = new Camera();

    //camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;

    camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
    camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
    camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

    Cube::Load((char*)"cube.txt");
    for (int i = 0; i < 200; i++) 
    {
        cube[i] = new Cube (((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);

    }
	GLUTCallbacks::Init(this);

 	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
    //glutKeyboardFunc(GLUTCallbacks::Keyboard);

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
    gluPerspective(45, 1, 1, 1000);

    // Switches us back to the model view matrix
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glCullFace(GL_BACK);

	glutMainLoop();

}
void HelloGL::Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (int i = 0; i < 200; i++)
    {
        cube[i]->Draw();
    }
    glFlush(); 
    glutSwapBuffers();

}
void HelloGL::Keyboard(unsigned char key, int x, int y) {
    if (key == 'd') {
        rotationTraingle += 2.5f;


    }if (key == 'a') {
        rotationTraingle -= 2.0f;
    }if (key == 'z') {
        camera->eye.z += 0.1f;

    }if (key == 'q') {
        camera->eye.z -= 0.1f;

    }if (key == 'e') {
        camera->eye.y += 0.1f;

    }if (key == 'u') {
        camera->eye.y -= 0.1f;

    }
}





void HelloGL::Update() {


    //rotationRect += 4.0f;   // Rectangle rotates fast
    //rotation += 1.0f; // Square rotates medium speed
    
    //rotationTraingle += 0.5f; // Triangle rotates slowly 


    //Sleep(10);

    // Resets ModelViewMatric in every frame , so transfromations fromt he previous don't get included in the current one 
    glLoadIdentity();
    gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
    
    for (int i = 0; i < 200; i++)
    {
        cube[i]->Update();
    }
    //if (rotation >= 360.0f) {
    //    rotation = 0.0f;
    //}
//    if (rotationRect >= 360.0f) 
//    {
//        rotationRect = 0.0f;
//    }
//    if (rotationTraingle >= 360.0f) 
//    {
//        rotationTraingle = 0.0f;
//;   }

    glutPostRedisplay();// causes scene to redraw itself after the update has finishe

}

HelloGL::~HelloGL(void) {

}