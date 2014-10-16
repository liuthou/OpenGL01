#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*
	该程序的作用是在一个黑色的窗口中央画一个白色的矩形
*/

#pragma region 画圆
// const int n = 88;
// const GLfloat R = 0.5;
// const GLfloat Pi = 3.141592653f;
// void myDisplay(void)
// {
// 	int i;
// 	//以gl开头的函数都是OPenGL标准函数
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

#pragma region 画五角星
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

#pragma region 画正弦函数的图形
/*
const GLfloat factor = 0.1f;
void myDisplay(void)
{
	GLfloat x;
		glClear(GL_COLOR_BUFFER_BIT);
		glEnable(GL_LINE_STIPPLE);
		glBegin(GL_LINES);		
		glVertex2f(-1.0f, 0.0f);
		glVertex2f(1.0f, 0.0f);	//以上两个点可以话x轴
		glVertex2f(0.0f, -1.0f);
		glVertex2f(0.0f, 1.0f);	//以上两个点可以话一y轴
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

#pragma region 正面反面
/*
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT, GL_FILL);	//设置正面为填充模式
	glPolygonMode(GL_BACK, GL_LINE);	//设置反面为线性模式
	glFrontFace(GL_CCW);	//设置逆时针方向为正面
	glBegin(GL_POLYGON);	//按逆时针绘制一个正方形, 在左下方
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, -0.5f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(-0.5f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);	//按顺时针绘制一个正方形,在右上方
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, 0.0f);
	glEnd();
	glFlush();
}*/
#pragma endregion

#pragma region 位图
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
	glRectf(-0.5f, -0.5f, 0.0f, 0.0f);	//左下方绘制一个有镂空效果的正方形
	glDisable(GL_POLYGON_STIPPLE);
	glRectf(0.0f, 0.0f, 0.5f, 0.5f);	//右上方绘制一个屋漏空效果的正方形
	glFlush();
}
*/
#pragma endregion

#pragma region 彩色
/*
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 1.0f);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush();
}*/
#pragma endregion

#pragma region 擦除
/*
void myDisplay(void)
{
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}*/
#pragma endregion

#pragma region 制定着色模型
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
	//以glut开头的都是GLUT提供的函数
	/*对GLUT进行初始化*/
	glutInit(&argc, argv);
	/*设置显示方式 RGB | 单缓冲*/
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	/*设置位置*/
	glutInitWindowPosition(100, 100);
	/*设置窗口大小*/
	glutInitWindowSize(400, 400);
	/*名字*/
	glutCreateWindow("第一个OpenGL程序");
	/*当绘图时会调用函数*/
	glutDisplayFunc(&myDisplay);
	/*消息循环*/
	glutMainLoop();
	return 0;
}