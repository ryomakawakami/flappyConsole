#pragma once
#include "chrono"

class Bird
{
public:
	Bird(int p);
	~Bird();
	void update();
	double getPosition();
	void setFlap(bool f);

private:
	bool flap;
	double position;
	double velocity;
	std::chrono::system_clock::time_point oldTime;
};
