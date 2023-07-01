#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

class BALL {
	public:
		int R = 30;
		float x;
		float y;
		float vx;
		float vy;
};
BALL ball;

int main() {
	initgraph(800, 600);
	ball.x = 300;
	ball.y = 200;
	ball.vx = 0;
	ball.vy = 0;

	MOUSEMSG m = GetMouseMsg();

	BeginBatchDraw();
	while (1) {
		while (MouseHit()) m = GetMouseMsg();

		float fx = m.x - ball.x;
		float fy = m.y - ball.y + 100;
		ball.vx += (fx / 100);
		ball.vy += (fy / 100);
		ball.vx *= 0.98;
		ball.vy *= 0.98;
		ball.x += ball.vx;		 
		ball.y += ball.vy;

		cleardevice();
		setfillcolor(RED);
		solidcircle((int)ball.x, (int)ball.y, ball.R); // »­Çò
		line((int)ball.x, (int)ball.y, m.x, m.y); // »­Ïß
		FlushBatchDraw();
		Sleep(20);
	}

	EndBatchDraw();
	closegraph();
	return 0;
}