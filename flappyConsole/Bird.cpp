#include "pch.h"
#include "bird.h"
#include "chrono"

Bird::Bird(int p) {
	input = false;
	position = p;
	velocity = 0;
	oldTime = std::chrono::system_clock::now();
}

Bird::~Bird() {
}

void Bird::update() {
	std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();
	std::chrono::duration<double> deltaT = currentTime - oldTime;
	oldTime = currentTime;

	double accel = -15;
	if (input) {
		accel = 15;
	}

	if (input) {
		velocity = 2.5;
	}

	position += velocity * deltaT.count();
	velocity += accel * deltaT.count();

	if (position < 0) {
		position = 0;
	}
}

double Bird::getPosition() {
	return position;
}

void Bird::setFlap(bool f) {
	input = f;
}
