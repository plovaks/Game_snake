#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
// Поле
const int width = 20;
const int height = 20;
// Координаты змейки и фруктов
int x, y, fruitx, fruity,score;
int tailx[100], taily[100];
int nTail;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
// Настройка параметров
void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2-1;
	y = height / 2-1;
	fruitx = rand() % width;
	fruity = rand() % height;
	score = 0;
}
// Рисование карты
void Draw() {
	system("cls");// очищает экран консоли
	for (int i = 0; i < width+1;i++) 
		cout << "#";
	cout << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1)
				cout << "#";
			if (i == y && j == x)
				cout << "0";
			else if (i == fruity && j == fruitx)
				cout << "F";
			else
				bool print = false;
			for (int k = 0; k < nTail; k++) {
				if (tailx[k] == j && taily[k] == i) {
					print = true;
					cout << "o";
				}
			}
			if (!print) {
				cout << " ";
			}
		}
		}
		cout << endl;
	}
	for (int i = 0; i < width+1; i++)
		cout << "#";
	cout << endl;
	cout << "score " << score << endl;
}
// Отслежование нажатий клавиш пользователем
void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
	Sleep(100);
}
// Логика игры
void Logic() {
	int prevX = tailx[0];
	int prevY = taily[0];
	int prev2x, prev2y;
	tailx[0] = x;
	taily[0] = y;
	for (int i = 1; i < nTail; i++) {
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevX;
		taily[i] = prevY;
		prevX = prev2x;
		prevY = prev2y;
	}
	switch (dir) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	//if (x > width || x < 0||y>height||y<0) 
		//gameOver = true;
	if (x >= width-1) {
		x = 0;}
	else if (x < 0) {
		x = width - 2;
	}
	if (y >= height) {
		y = 0;
	}
	else if (y < 0) {
		y = height - 1;
	}
		for (int i=0;i<nTail;i++){
			if (tailx[i] == x && taily [i] == y) {
				gameover = true;
			}
	
	if (x == fruitx && y == fruity) {
		score += 10;
		fruitx = rand() % width;
		fruity = rand() % height;
		nTail++;
	}
}
int main()
{
	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
		Sleep(200);
	}
	return 0;
}

