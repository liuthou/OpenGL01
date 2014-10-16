#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*
	�ó������������һ����ɫ�Ĵ������뻭һ����ɫ�ľ���
*/

#pragma region ��Բ
// const int n = 88;
// const GLfloat R = 0.5;
// const GLfloat Pi = 3.141592653f;
// void myDisplay(void)
// {
// 	int i;
// 	//��gl��ͷ�ĺ�������OPenGL��׼����
// 	glClear(GL_COLOR_BUFFER_BIT);
// 	/*glRectf(-0.5f, -0.5f, 0.5f, 0.5f);*/
// 	glBegin(GL_POLYGON);
// 	for (int i = 0; i < n; i++)
// 	{
// 		glVertex2f(R * cos(2 * Pi / n * i), R * sin(2 * Pi / n * i));
// 	}
// 	glEnd();
// 	glFlush();
// }

#pragma endregion

#pragma region �������
/*
const GLfloat Pi = 3.1415926536f;

void myDisplay(void)
{
	GLfloat a = 1 / (2 - 2 * cos(72 * Pi / 180));
	GLfloat bx = a * cos(18 * Pi / 180);
	GLfloat by = a * sin(18 * Pi / 180);
	GLfloat cy = -a * cos(18 * Pi / 180);
	GLfloat
		PointA[2] = { 0, a },
		PointB[2] = { bx, by },
		PointC[2] = { 0.5, cy },
		PointD[2] = { -0.5, cy },
		PointE[2] = { -bx, by };
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
		glVertex2fv(PointA);
		glVertex2fv(PointC);
		glVertex2fv(PointE);
		glVertex2fv(PointB);
		glVertex2fv(PointD);
	glEnd();
	glFlush();
}
*/
#pragma endregion

#pragma region �����Һ�����ͼ��
/*
const GLfloat factor = 0.1f;
void myDisplay(void)
{
	GLfloat x;
		glClear(GL_COLOR_BUFFER_BIT);
		glEnable(GL_LINE_STIPPLE);
		glBegin(GL_LINES);		
		glVertex2f(-1.0f, 0.0f);
		glVertex2f(1.0f, 0.0f);	//������������Ի�x��
		glVertex2f(0.0f, -1.0f);
		glVertex2f(0.0f, 1.0f);	//������������Ի�һy��
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (x = -1.0f / factor; x < 1.0f / factor; x += 0.01f)
	{
		glVertex2f(x * factor, sin(x) * factor);
	}
	glEnd();
	glFlush();

}*/
#pragma endregion

#pragma region ���淴��
/*
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT, GL_FILL);	//��������Ϊ���ģʽ
	glPolygonMode(GL_BACK, GL_LINE);	//���÷���Ϊ����ģʽ
	glFrontFace(GL_CCW);	//������ʱ�뷽��Ϊ����
	glBegin(GL_POLYGON);	//����ʱ�����һ��������, �����·�
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, -0.5f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(-0.5f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);	//��˳ʱ�����һ��������,�����Ϸ�
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, 0.0f);
	glEnd();
	glFlush();
}*/
#pragma endregion

#pragma region λͼ
/*
void myDisplay(void)
{
	static GLubyte Mask[128];
	FILE *fp;
	fp = fopen("mask.bmp", "rb");
	if (!fp)
		exit(0);
	if (fseek(fp, -(int)sizeof(Mask), SEEK_END))
		exit(0);
	if (!fread(Mask, sizeof(Mask), 1, fp))
		exit(0);
	fclose(fp);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(Mask);
	glRectf(-0.5f, -0.5f, 0.0f, 0.0f);	//���·�����һ�����ο�Ч����������
	glDisable(GL_POLYGON_STIPPLE);
	glRectf(0.0f, 0.0f, 0.5f, 0.5f);	//���Ϸ�����һ����©��Ч����������
	glFlush();
}
*/
#pragma endregion

#pragma region ��ɫ
/*
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 1.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush();
}*/
#pragma endregion

#pragma region ����
/*
void myDisplay(void)
{
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}*/
#pragma endregion

#pragma region �ƶ���ɫģ��
/**/
const GLdouble Pi = 3.1415926536;
void myDisplay(void)
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.0f, 0.0f);
	for ( i = 0; i < 9; i++)
	{
		glColor3f(i & 0x04, i & 0x02, i & 0x01);
		glVertex2f(cos(i * Pi / 4), sin(i * Pi / 4));
	}
	glEnd();
	glFlush();
}
#pragma endregion


int main(int argc, char *argv[])
{
	//��glut��ͷ�Ķ���GLUT�ṩ�ĺ���
	/*��GLUT���г�ʼ��*/
	glutInit(&argc, argv);
	/*������ʾ��ʽ RGB | ������*/
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	/*����λ��*/
	glutInitWindowPosition(100, 100);
	/*���ô��ڴ�С*/
	glutInitWindowSize(400, 400);
	/*����*/
	glutCreateWindow("��һ��OpenGL����");
	/*����ͼʱ����ú���*/
	glutDisplayFunc(&myDisplay);
	/*��Ϣѭ��*/
	glutMainLoop();
	return 0;
}