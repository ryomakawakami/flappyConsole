#include "pch.h"
#include "bird.h"
#include "chrono"

Bird::Bird(int p) {
	flap = false;
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

	double accel = -2;
	if (flap) {
		accel = 2;
	}

	position += velocity * deltaT.count();
	velocity += accel * deltaT.count();
}

double Bird::getPosition() {
	return position;
}

void Bird::setFlap(bool f) {
	flap = f;
}
