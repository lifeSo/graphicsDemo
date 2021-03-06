/**
 * @Date: 2017.06.08
 */

#include <GL/glut.h>
#include <math.h>

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 900.0);
}

// 画螺旋线。
void drawSpriralLine() {
	GLfloat pi2 = 3.1415936 * 2;
	GLfloat one = 1.0;
	GLfloat zero = 0.0;
	GLfloat r = 450;
	GLfloat x = 500.0;
	GLfloat y = 450.0;
	GLfloat c = 0.08;

	glBegin(GL_POINTS);
	for (GLfloat j = 0; j < pi2 * 10; j += 0.01) {
		r = r < zero ? zero : r;
		glVertex2f(x + r * cos(j) + one, y + r * sin(j) + one);
		glVertex2f(x + r * cos(j) + one, y + r * sin(j) - one);
		glVertex2f(x + r * cos(j) - one, y + r * sin(j) + one);
		glVertex2f(x + r * cos(j) - one, y + r * sin(j) - one);
		glVertex2f(x + r * cos(j), y + r * sin(j));
		r -= c;
	}
	glEnd();
}

// 通过修改视口，在同一个显示窗口中，画出四个螺旋圈。
// 视口指定在输出设备上的什么位置进行观察。
void simulate(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glViewport(500, 450, 500, 450);    //    右上
	drawSpriralLine();

	glViewport(0, 0, 500, 450);        //    左下
	drawSpriralLine();

	glViewport(0, 450, 500, 450);    //    左上
	drawSpriralLine();

	glViewport(500, 0, 500, 450);    // 右下
	drawSpriralLine();

	glFlush();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(1000, 900);
	glutCreateWindow("spiral line OpenGL Program");

	init();
	glutDisplayFunc(simulate);
	glutMainLoop();

	return 0;
}
