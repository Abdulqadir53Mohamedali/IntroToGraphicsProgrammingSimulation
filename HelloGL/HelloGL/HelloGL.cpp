#include "HelloGL.h"
#include "Pyramid.h"  
 

#include "GLUTCallbacks.h"


HelloGL::HelloGL(int argc, char* argv[]) 
{/*
    rotation = 0.0f;
    rotationRect = 0.0f;
    rotationTraingle = 0.0f;*/

    InitGl(argc, argv);

    InitObjects();
    InitLighting();

	glutMainLoop();

}

void HelloGL::InitObjects() {
    camera = new Camera();

    //camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;

    camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
    camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
    camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

    Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
    Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");

    Texture2D* texture = new Texture2D();
    texture->Load((char*)"Penguins.raw", 512, 512);

    for (int i = 0; i < 500; i++)
    {
        objects[i] = new Cube(cubeMesh,texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);

    }
    for (int i = 500; i < 700; i++)
    {
        objects[i] = new Pyramid(pyramidMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
    }    



}
void HelloGL::InitGl(int argc, char* argv[]) {
    GLUTCallbacks::Init(this);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Simple OpenGL Program");
    glEnable(GL_TEXTURE_2D);
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
        // the next 1 is the front clipping plane. This can be set to zero, but this is not usually done. Note, anything a distance of 1 from the camera (between zero and 1) won’t be visible
        // 1000 is the far clipping plane, nothing past 1000 units from the camera will be drawn
    gluPerspective(45, 1, 1, 1000);

    // Switches us back to the model view matrix
    glMatrixMode(GL_MODELVIEW);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glCullFace(GL_BACK);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

}

void HelloGL::Display()
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    for (int i = 0; i < 500; i++)
    {
        InitMaterial();
        GLfloat amb[4] = {
            _material->Ambient.x,
            _material->Ambient.y,
            _material->Ambient.z,
            _material->Ambient.w
        };

        GLfloat dif[4] = {
            _material->Diffuse.x,
            _material->Diffuse.y,
            _material->Diffuse.z,
            _material->Diffuse.w
        };

        GLfloat spe[4] = {
            _material->Specular.x,
            _material->Specular.y,
            _material->Specular.z,
            _material->Specular.w
        };

        glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, spe);
        glMaterialf(GL_FRONT, GL_SHININESS, _material->Shininess);

        objects[i]->Draw();
    }    

    for (int i = 500; i < 700; i++)
    {
        InitMaterial();
        GLfloat amb[4] = {
            _material->Ambient.x,
            _material->Ambient.y,
            _material->Ambient.z,
            _material->Ambient.w
        };

        GLfloat dif[4] = {
            _material->Diffuse.x,
            _material->Diffuse.y,
            _material->Diffuse.z,
            _material->Diffuse.w
        };

        GLfloat spe[4] = {
            _material->Specular.x,
            _material->Specular.y,
            _material->Specular.z,
            _material->Specular.w
        };

        glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);
        glMaterialfv(GL_FRONT, GL_SPECULAR, spe);
        glMaterialf(GL_FRONT, GL_SHININESS, _material->Shininess);

        objects[i]->Draw();
    }    

    Draw();
    glFlush(); 
    glutSwapBuffers();

}
void HelloGL::Keyboard(unsigned char key, int x, int y) {
    //if (key == 'd') {
    //    rotationTraingle += 2.5f;


    //}if (key == 'a') {
    //    rotationTraingle -= 2.0f;    //if (key == 'd') {
    //    rotationTraingle += 2.5f;


    //}if (key == 'a') {
    //    rotationTraingle -= 2.0f;
    if (key == 'z') {
        camera->eye.z += 0.1f;

    }if (key == 'q') {
        camera->eye.z -= 0.1f;

    }if (key == 'e') {
        camera->eye.y += 0.1f;

    }if (key == 'u') {
        camera->eye.y -= 0.1f;

    }
    if (key == 'a') {
        for (int i = 0; i < 500;i++) {
            objects[i]->_position.x += 0.1f;
        }

    }    
    if (key == 'b') {
        for (int i = 0; i < 500;i++) {
            objects[i]->_position.x -= 0.1f;
        }

    }
}
void HelloGL::InitLighting(){
    _lightPosition = new Vector4();
    _lightPosition->x = 0.0;
    _lightPosition->y = 0.0;
    _lightPosition->z = 1.0;
    _lightPosition->w = 0.0;

    _lightData = new Lighting();
    _lightData->Ambient.x = 0.2;
    _lightData->Ambient.y = 0.2;
    _lightData->Ambient.z = 0.2;
    _lightData->Ambient.w = 1.0;

    _lightData->Diffuse.x = 0.8;
    _lightData->Diffuse.y = 0.8;
    _lightData->Diffuse.z = 0.8;
    _lightData->Diffuse.w = 1.0;

    _lightData->Specular.x = 0.2;
    _lightData->Specular.y = 0.2;
    _lightData->Specular.z = 0.2;
    _lightData->Specular.w = 1.0;
}
void HelloGL::InitMaterial() {
    _material = new Material();

    _material->Ambient.x = 0.8;
    _material->Ambient.y = 0.05;
    _material->Ambient.z = 0.05;
    _material->Ambient.w = 1.0;

    _material->Diffuse.x = 0.8;
    _material->Diffuse.y = 0.05;
    _material->Diffuse.z = 0.05;
    _material->Diffuse.w = 1.0;

    _material->Specular.x = 1.0;
    _material->Specular.y = 1.0;
    _material->Specular.z = 1.0;
    _material->Specular.w = 1.0;

    _material->Shininess = 100.0f;

}
void HelloGL::DrawString(const char* text, Vector3* position, Color*) {

    
    glPushMatrix();
        glTranslatef(position->x, position->y, position->z);
        glRasterPos2f(0.0f, 0.0f);
    glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);




    glPopMatrix();
}
void HelloGL::Draw() {

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();

    gluOrtho2D(0, 800, 0, 800);

    // switch to mdoel view to place text
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    //  lighting disabled so the text colour is consistent
    glDisable(GL_LIGHTING);
    // don’t want text tinted by the texture environment:
    glDisable(GL_TEXTURE_2D);

    glColor3f(0.0f, 1.0f, 0.0f);  // green text


    Vector3 screenPos = { 500.0f, 750.0f, 0.0f };
    DrawString("500 cubes : 200 Pyramids", &screenPos, nullptr);

    // Re-enable what was turned off
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);

    // Restore the modelview
    glPopMatrix();

    // Restore projection matrix
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}




void HelloGL::Update() {


    //rotationRect += 4.0f;   // Rectangle rotates fast
    //rotation += 1.0f; // Square rotates medium speed
    
    //rotationTraingle += 0.5f; // Triangle rotates slowly 


    //Sleep(10);

    // Resets ModelViewMatric in every frame , so transfromations fromt he previous don't get included in the current one 
    glLoadIdentity();
    gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);

    

    GLfloat amb[4] = {
        _lightData->Ambient.x,
        _lightData->Ambient.y,
        _lightData->Ambient.z,
        _lightData->Ambient.w
    };

    GLfloat dif[4] = {
        _lightData->Diffuse.x,
        _lightData->Diffuse.y,
        _lightData->Diffuse.z,
        _lightData->Diffuse.w
    };

    GLfloat spe[4] = {
        _lightData->Specular.x,
        _lightData->Specular.y,
        _lightData->Specular.z,
        _lightData->Specular.w
    };

    GLfloat pos[4] = {
        _lightPosition->x,
        _lightPosition->y,
        _lightPosition->z,
        _lightPosition->w
    };

    // Sets each property with a single call
    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
    glLightfv(GL_LIGHT0, GL_SPECULAR, spe);
    glLightfv(GL_LIGHT0, GL_POSITION, pos);

    for (int i = 0; i < 500; i++)
    {
        objects[i]->Update();
    }    
    for (int i = 500; i < 700; i++)
    {
        objects[i]->Update();
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