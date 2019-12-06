// flappyConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "bird.h"
#include <iostream>
#include <windows.h>

using namespace std;

void setup() {

}

void draw(double position) {
	system("cls");

	for (int i = 29; i >= 0; i--) {
		if (i == (int) position) {
			cout << "O";
		}
		if (i != 0) {
			cout << endl;
		}
	}
}

void getInput() {

}

void updateModel(Bird* bird) {
	bird->update();
}

void updateDisplay(char pixel[30][120]) {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 120; j++) {
			cout << pixel[i][j];
		}
	}
}

int main() {
	// TODO: Define console size as 30, 120... Maybe set it somehow

	Bird bird = Bird(30);

	bool done = false;

	setup();

	while (!done) {
		draw(bird.getPosition());
		getInput();
		updateModel(&bird);
		Sleep(50);
	}

	// Find console dimensions
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	cout << "columns: " << columns << endl;
	cout << "rows: " << rows << endl;

	// Clear console
	system("CLS");

	char pixel[30][120];

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i == j / 4) {
				pixel[i][j] = ' ';
			}
			else {
				pixel[i][j] = 'X';
			}
		}
	}

	updateDisplay(pixel);

	Sleep(10000);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
