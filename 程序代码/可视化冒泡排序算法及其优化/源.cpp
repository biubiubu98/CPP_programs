#include <graphics.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

const int Size = 10;
const int Width = 30;

void drawArray(int arr[], int compareIdx1, int compareIdx2) {
	BeginBatchDraw();
	FlushBatchDraw();
	cleardevice();
	for (int i = 0; i < Size; i++) {
		if (i == compareIdx1 || i == compareIdx2) {
			setfillcolor(RED);
		}
		else {
			setfillcolor(GREEN);
		}

		fillrectangle(170 + i * Width, 480 - arr[i], 170 + (i + 1) * Width - 1, 480);
	}
	Sleep(50);
	EndBatchDraw();
}

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			drawArray(arr, j, j + 1);
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);		
			}
			Sleep(150);
			drawArray(arr, j, j + 1);
		}
	}
}

//”≈ªØ∞Ê±æ
void bubbleSort_plus(int arr[], int n) {
	bool isSorted = false;
	int lastExchangeIndex = 0;
	for (int i = 0; i < n - 1 && !isSorted; i++) {
		isSorted = true;
		for (int j = 0; j < n - i - 1; j++) {
			drawArray(arr, j, j + 1);
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				isSorted = false;
				lastExchangeIndex = j;
			}
			Sleep(300);
			drawArray(arr, j, j + 1);
		}
		if (isSorted) {
			break;
		}
		i = n - lastExchangeIndex - 2;
	}
}

int main() {
	initgraph(640, 480);
	srand(time(NULL));

	int arr[Size];
	for (int i = 0; i < Size; i++) {
		arr[i] = rand() % 480;
	}
	_getch();
	drawArray(arr, -1, -1);
	bubbleSort(arr, Size);
	//bubbleSort_plus(arr, Size);
	drawArray(arr, -1, -1);
	_getch();
	system("pause");
	closegraph();
	return 0;
}