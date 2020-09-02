
#include <iostream>
#include <GL/glut.h>
using namespace std;

void ChangeSize(int w, int h)
{
	GLfloat aspectRatio;
	if (h == 0)
		h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h)
		glOrtho(-10.0, 10.0, -10 / aspectRatio, 10.0 / aspectRatio, 1.0, -1.0);
	else
		glOrtho(-10.0 * aspectRatio, 10.0 * aspectRatio, -10.0, 10.0, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	for (int i = -10; i < 10; i++)
		for (int j = -10; j < 10; j++)
		{
			glPushMatrix();
			glTranslatef(i, j, 0);
			glColor3ub(rand() % 255, rand() % 255, rand() % 255);
			glBegin(GL_QUADS);
			glVertex2i(0, 0);
			glVertex2i(1, 0);
			glVertex2i(1, 1);
			glVertex2i(0, 1);
			glEnd();
			glPopMatrix();
		}

	glFlush();
}


int main(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("GLUT Test");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutMainLoop();
	return 0;
}
