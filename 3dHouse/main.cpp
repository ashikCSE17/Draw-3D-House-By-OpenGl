#include <iostream>
#include <stdlib.h>
#include<windows.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

//Called when a key is pressed


//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	//you can have upto 8 lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	//glShadeModel(GL_SMOOTH); //Enable smooth shading
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 800.0);
}


float _angle = -70.0f;

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -8.0f);

	//Add ambient light
	//sh that shines everywhere in our scene by the same amount
	//every face gets the same amount
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2) and intensity //can be greater than 1 so not like color
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	//Add positioned light
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	//Add directed light
	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	// 0 because direced light source
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

	glRotatef(_angle, 0.0f, -1.0f, 0.0f);





//front part
glColor3f(0.6,0,0.4);
    glBegin(GL_QUADS);

    glVertex3f(-1.5,-2,0);
    glVertex3f(1.5,-2,0);
    glVertex3f(1.5,0,0);
    glVertex3f(-1.5,0,0);
    glEnd();


//back part
glColor3f(0.6,0,0.9);
    glBegin(GL_QUADS);

    glVertex3f(-1.5,-2,-2);
    glVertex3f(1.5,-2,-2);
    glVertex3f(1.5,0,-2);
    glVertex3f(-1.5,0,-2);
    glEnd();

//right part
glColor3f(1,0,1);
    glBegin(GL_QUADS);

    glVertex3f(1.5,-2,0);
    glVertex3f(1.5,-2,-2);
    glVertex3f(1.5,0,-2);
    glVertex3f(1.5,0,0);
    glEnd();


//Left part
glColor3f(0,1,1);
    glBegin(GL_QUADS);

    glVertex3f(-1.5,-2,0);
    glVertex3f(-1.5,0,0);
    glVertex3f(-1.5,0,-2);
    glVertex3f(-1.5,-2,-2);
    glEnd();

//front roof
glColor3f(0,1,0);
    glBegin(GL_QUADS);

    glVertex3f(-1.5,0,0);
    glVertex3f(1.5,0,0);
    glVertex3f(0.8,1,-1);
    glVertex3f(-0.8,1,-1);
    glEnd();


//back roof
glColor3f(0,1,1);
    glBegin(GL_QUADS);

    glVertex3f(1.5,0,-2);
    glVertex3f(-1.5,0,-2);
    glVertex3f(-0.8,1,-1);
    glVertex3f(0.8,1,-1);
    glEnd();

//right roof
glColor3f(0,1.354,1.12);
    glBegin(GL_TRIANGLES);

    glVertex3f(1.5,0,0);
    glVertex3f(1.5,0,-2);
    glVertex3f(0.8,1,-1);
    glEnd();

//left roof
glColor3f(0.9,1,0.1);
    glBegin(GL_TRIANGLES);

    glVertex3f(-1.5,0,-2);
    glVertex3f(-1.5,0,0);
    glVertex3f(-0.8,1,-1);
    glEnd();











	glutSwapBuffers();
}

void update(int value) {
	_angle += 1.5f;
	if (_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);

	//Create the window
	glutCreateWindow("3dHouse: Md. Ashikul Aziz Siddique");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}
