////////////////////////////////////////////
// 程序：easyx版本 2048
// 作者：鲨鱼编程 
// 公众号：鲨鱼编程


#include <iostream>;
#include <graphics.h>
#include <conio.h>

using namespace std;

const int Size = 4;

int board[4][4] = { 0 };
int score = 0;

void newnumber();
void drawboard();
bool moveBoard(int x, int y);
bool checkGameOver();

int main() {
	initgraph(400, 400);
	srand((unsigned)time(NULL));

	newnumber();
	newnumber();
	drawboard();

	while (!_kbhit()) {
		char ch = _getch();
		bool moved = false;
		if (ch == 'w' || ch == 'W') {
			moved = moveBoard(-1, 0);
		}
		else if (ch == 's' || ch == 'S') {
			moved = moveBoard(1, 0);
		}
		else if (ch == 'a' || ch == 'A') {
			moved = moveBoard(0, -1);
		}
		else if (ch == 'd' || ch == 'D') {
			moved = moveBoard(0, 1);
		}
		if (moved == true) {
			newnumber();
			drawboard();
			if (checkGameOver()) {
				MessageBox(GetHWnd(), _T("Game Over!"), _T("2048"), MB_OK);
				break;
			}
		}
	}

	closegraph();
	return 0;
}

void newnumber() {
	int empty = 0;
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (board[i][j] == 0) {
				empty++;
			}
		}
	}
	if (empty != 0) {
		int a = rand() % empty;
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				if (board[i][j] == 0) {
					if (a == 0) {
						board[i][j] = 2 * (rand() % 2 + 1);
						return;
					}
					a--;
				}
			}
		}
	}
	
}

void drawboard() {
	setbkcolor(WHITE);
	cleardevice();
	settextcolor(BLACK);
	settextstyle(20, 0, _T("宋体"));
	TCHAR scoreStr[64];
	_stprintf_s(scoreStr, _T("分数: %d"), score);
	outtextxy(10, 10, scoreStr);

	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			TCHAR numStr[8];
			_stprintf_s(numStr, _T("%d"), board[i][j]);
			outtextxy(j * 100 + 50, i * 100 + 50, numStr);
		}
	}
}

bool moveBoard(int x, int y) {
	bool moved = false;
	if (x == 0 && y == -1) {
		for (int i1 = 0; i1 < Size; i1++) {
			for (int j1 = 0; j1 < Size-1; j1++) {
				for (int j2 = j1 -y; j2 < Size; j2++) {
					if (board[i1][j2] == 0) continue;
					else if (board[i1][j1] == board[i1][j2] || board[i1][j1] == 0) {
						if (board[i1][j1] == board[i1][j2]) score += 2 * board[i1][j1];
						board[i1][j1] += board[i1][j2];
						board[i1][j2] = 0;
					}
					else if (board[i1][j2] != board[i1][j1] && board[i1][j1] != 0) {
						break;
					}
				}
			}
		}
		moved = true;
	}
	if (x == 0 && y == 1) {
		for (int i1 = 0; i1 < Size; i1++) {
			for (int j1 = Size-1; j1 >0; --j1) {
				for (int j2 = j1 -y; j2 >= 0; --j2) {
					if (board[i1][j2] == 0) continue;
					else if (board[i1][j1] == board[i1][j2] || board[i1][j1] == 0) {
						if (board[i1][j1] == board[i1][j2]) score += 2 * board[i1][j1];
						board[i1][j1] += board[i1][j2];
						board[i1][j2] = 0;
					}
					else if (board[i1][j2] != board[i1][j1] && board[i1][j1] != 0) {
						break;
					}
				}
			}
		}
		moved = true;
	}
	if (x == -1 && y == 0) {
		for (int j1 = 0; j1 < Size; j1++) {
			for (int i1 = 0; i1 < Size - 1; i1++) {
				for (int i2 = i1 - x; i2 < Size; i2++) {
					if (board[i2][j1] == 0) continue;
					else if (board[i1][j1] == board[i2][j1] || board[i1][j1] == 0) {
						if (board[i1][j1] == board[i2][j1]) score += 2 * board[i1][j1];
						board[i1][j1] += board[i2][j1];
						board[i2][j1] = 0;
					}
					else if (board[i2][j1] != board[i1][j1] && board[i1][j1] != 0) {
						break;
					}
				}
			}
		}
		moved = true;
	}
	if (x == 1 && y == 0) {
		for (int j1 = 0; j1 < Size; ++j1) {
			for (int i1 = Size - 1; i1 > 0; --i1) {
				for (int i2 = i1 - x; i2 >= 0; --i2) {
					if (board[i2][j1] == 0) continue;
					else if (board[i1][j1] == board[i2][j1] || board[i1][j1] == 0) {
						if (board[i1][j1] == board[i2][j1]) score += 2 * board[i1][j1];
						board[i1][j1] += board[i2][j1];
						board[i2][j1] = 0;
					}
					else if (board[i2][j1] != board[i1][j1] && board[i1][j1] != 0) {
						break;
					}
				}
			}
		}
		moved = true;
	}
	return moved;
}

bool checkGameOver() {
	for (int i = 0; i < Size; ++i) {
		for (int j = 0; j < Size; ++j) {
			if (board[i][j] == 0) {
				return false;
			}
			if (i < Size - 1 && board[i][j] == board[i + 1][j]) {
				return false;
			}
			if (j < Size - 1 && board[i][j] == board[i][j + 1]) {
				return false;
			}
		}
	}
	return true;
}