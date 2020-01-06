#pragma once
class setpoint
{
private:
	float p; // Grid 
	float c; // Consumption

public:
	setpoint();
	~setpoint();
	float calculate(float p, float c);			// setup 1
	float calculate(float d);					// setup 3
	float calculate(float p, float g, float b); // setup 4
};

