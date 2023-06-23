#include <graphics.h>
#include <conio.h>
#include <math.h>

const double PI = 3.1415926536;

// ����һ���ṹ�� Point���洢�������
struct Point
{
	double x;
	double y;
};

// ֱ�ߵ���ת��p1 �Ƕ��㣩
Point Rotate(Point p1, Point p2, double angle)
{
	Point r;
	r.x = p1.x + (p2.x - p1.x) * cos(angle) + (p2.y - p1.y) * sin(angle);
	r.y = p1.y + (p2.y - p1.y) * cos(angle) - (p2.x - p1.x) * sin(angle);
	return r;
}

// ֱ�ߵ����ţ�p1 �Ƕ��㣩
Point Zoom(Point p1, Point p2, double ratio)
{
	Point r;
	r.x = p1.x + (p2.x - p1.x) * ratio;
	r.y = p1.y + (p2.y - p1.y) * ratio;
	return r;
}

// ����������
void Draw(Point p1, Point p2)
{
	Point p11 = Rotate(p1, p2, 90 * PI / 180);
	Point p22 = Rotate(p2, p1, 270 * PI / 180);

	POINT pts[] = { { int(p1.x + 0.5),  int(p1.y + 0.5) },					// +0.5 ��Ϊ����������
					{ int(p2.x + 0.5),  int(p2.y + 0.5) },
					{ int(p22.x + 0.5), int(p22.y + 0.5) },
					{ int(p11.x + 0.5), int(p11.y + 0.5) } };

	static int color_H = 270;
	setfillcolor(HSVtoRGB(float(color_H), 1, 1));							// ���������ε������ɫ
	setlinecolor(HSVtoRGB(float((color_H + 80) % 360), 0.5, 0.5));			// ���������εı߿���ɫ
	color_H = (color_H + 1) % 360;
	fillpolygon(pts, 4);													// �����������ɫ

	if (((p22.x - p11.x) * (p22.x - p11.x) + (p22.y - p11.y) * (p22.y - p11.y)) > 3 * 3)	// �����εı߳� >3 ʱ�ݹ�
	{
		//double a = 60 * PI / 180;					// 60 ����ʽ
		double a = 45 * PI / 180;					// 45 ����ʽ
		Point p = Rotate(p11, p22, a);
		p = Zoom(p11, p, cos(a));

		Draw(p, p22);
		Draw(p11, p);
	}
}

// ������
int main()
{
	initgraph(640, 480);				// ��ʼ������
	setbkcolor(0xfecaeb);				// ���ñ�����ɫ
	cleardevice();

	Point p1 = { 290, 400 };
	Point p2 = { 350, 400 };
	Draw(p1, p2);

	_getch();
	closegraph();						// �رմ���
	return 0;
}
