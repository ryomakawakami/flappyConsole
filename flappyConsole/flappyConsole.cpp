// flappyConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "bird.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

bool press;
bool done;
Bird bird = Bird(30);

void setup() {
	press = false;
	done = false;
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
	if (_kbhit()) {
		if (_getch() == 'a') {
			press = true;
		}
	}
}

void updateModel() {
	bird.setFlap(press);
	press = false;
	bird.update();
}

int main() {
	// TODO: Define console size as 30, 120... Maybe set it somehow

	setup();

	while (!done) {
		draw(bird.getPosition());
		getInput();
		updateModel();
		Sleep(50);
	}
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
