#include "setpoint.h"

setpoint::setpoint()
{
}

setpoint::~setpoint()
{
}

float setpoint::calculate(float p, float c)  // setup 1
{
	return p - c;
}

float setpoint::calculate(float d) // setup 3
{
	return d; // d is already p - c
}

float setpoint::calculate(float p, float g, float b) //setup 4
{
	float c = p + b + g; // if b > 0 then g = 0, and the other way, if g > 0 then b = 0
	if (g > 0) // buying from the grid, then the battery must be empty
		return 0; // don't charge or discharge battery
	return p - c;
}