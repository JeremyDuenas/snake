#include<iostream>
#include<conio.h>


using namespace std;

bool gameOver;

const int WIDTH = 20;
const int HEIGHT = 20;
const int ARRAYSIZE = 100;

int x, y, fruitX, fruitY, score, nTail;
int tailX[ARRAYSIZE];
int tailY[ARRAYSIZE];

enum direction{STOP = 0, LEFT, RIGHT,UP,DOWN};

direction dir;

void setUp();
void draw();
void input();
void logic();

int main() {
	setUp();
	while (!gameOver)
	{

		draw();
		input();
		logic();
	}
	system("pause>nul");
	return 0;
}
void setUp(){
	gameOver = false;
	dir = STOP;
	x = WIDTH / 2;
	y = HEIGHT / 2;
	fruitX = rand() % WIDTH;
	fruitY = rand() % HEIGHT;
	score = 0;
}
void draw() {
	system("CLS");
	for (int i = 0; i < WIDTH + 2; i++)
	{
		cout << "#";
	}
	cout << '\n';
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (j == 0)
			{
				cout << "#";

			}
			if (i == y && j == x)
			{
				cout << "O";
			}
			else if (j == fruitX && i == fruitY)
			{
				cout << "F";
			}
			else
			{
				bool print = false;
				for (int k= 0; k < nTail; k++)
				{

					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}

				}
				if (!print)
				{
					cout << " ";
				}

			}

			if (j == WIDTH - 1)
			{
				cout << "#";
			}

		}
		cout << endl;
	}
	for (int i = 0; i < WIDTH + 2; i++)
	{
		cout << "#";
	}
	cout << '\n';
	cout << "Your score is: " << score;
}
void input() {
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
		default:
			break;
		}
	}
}
void logic() {
	int previousX = tailX[0];
	int previousY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = previousX;
		tailY[i] = previousY;
		previousX = prev2X;
		previousY = prev2Y;
	}
	switch (dir)
	{
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

	default:
		break;
	}
	if (x > WIDTH || x < 0 || y >HEIGHT || y < 0)
	{
		gameOver = true;
	}
	if (x == fruitX && y == fruitY)
	{

		score += 10;
		fruitX = rand() % WIDTH;
		fruitY = rand() % HEIGHT;
		nTail++;
	}
}
// 
// end of program
