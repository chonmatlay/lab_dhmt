#include "tchar.h"
#include <windows.h>
#include "gl.h"
#include "glut.h"
#include "math.h"
#include "Mesh.h"
#include "supportClass.h"
#define PI 3.141592654


Mesh meshShape1;

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void drawText(int xPos, int yPos, char str[])
{

	glRasterPos2i(xPos, yPos); //Position

	void* font = GLUT_BITMAP_9_BY_15;
	for (int i = 0; i < strlen(str); i++)
	{
		glutBitmapCharacter(font, str[i]);
	}
}
void drawLine(float x1, float y1, float len, float angle, float& x2, float& y2) {
	float ang = angle * PI / 180;
	float x_add = len * cos(ang);
	float y_add = len * sin(ang);
	x2 = x1 + x_add;
	y2 = y1 + y_add;
	//glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
	glFlush();
}
void draw10angle(float x1 , float y1 , float angle , float len ) {
	float x2, y2;
	for (int i = 0; i < 10; i++) {
		drawLine(x1, y1,len, angle + i * 36, x2, y2);
		x1 = x2;
		y1 = y2;
	}
}
void drawSquare(float x1, float y1, float angle, float len) {
	for (int i = 0; i < 10; i++) {
		drawLine(x1, y1, len, angle + i * 90, x1, y1);
		//x1 = x2;
		//y1 = y2;
	}

}
void drawTriangle(float x1 , float y1 , float angle , float len ) {
	float x2, y2; 
	float x3, y3;
	glFlush();
	drawLine(x1, y1, len, angle + 60, x3, y3);
	drawLine(x1, y1, len, angle, x2, y2);
	//glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	glBegin(GL_LINES);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
	glFlush();
}

void myDisplay(){
	meshShape1.CreateCylinder(50, 25, 10);
	meshShape1.DrawColor();
	meshShape1.DrawWireframe();
}


// Constants and variables...
// Menu item constants
enum { RED_ITEM, GREEN_ITEM, BLUE_ITEM, QUIT_ITEM };


// Menu callback: choice is value of the chosen menu entry
void menu(int choice) {
	switch (choice) {
	case RED_ITEM:
		glColor3f(1.0, 0.0, 0.0); // Red
		myDisplay();
		break;
	case GREEN_ITEM:
		glColor3f(0.0, 1.0, 0.0); // Green
		myDisplay();
		break;
	case BLUE_ITEM:
		glColor3f(0.0, 0.0, 1.0); // Blue
		myDisplay();
		break;
	case QUIT_ITEM:
		exit(0);
		break;
	default:
		break;
	}
}

// Create the menu, add the items, and attach to the mouse button
void createMenu() {
	// create menu
	int	m = glutCreateMenu(menu); // simultaneously registers callback

	//add entries: 2nd parameter is value returned when entry is selected

	glutAddMenuEntry("Red", RED_ITEM);
	glutAddMenuEntry("Green", GREEN_ITEM);
	glutAddMenuEntry("Blue", BLUE_ITEM);
	glutAddMenuEntry("Quit", QUIT_ITEM);

	// attach button to menu: overrides mouse callback for RIGHT button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int _tmain(int argc, _TCHAR* argv[])
{

	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set the display mode
	glutInitWindowSize(640, 480); //set window size
	glutInitWindowPosition(100, 150); //set window position on screen
	glutCreateWindow("Output Text"); //open the screen window

	createMenu();

	glutDisplayFunc(myDisplay);

	myInit();
	glutMainLoop();
	return 0;
}










