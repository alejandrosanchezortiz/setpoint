#include <iostream>
#include "setpoint.h"

using namespace std;

void main(void)
{
	setpoint case1;

	cout << "P = photovoltaics as watts" << endl;
	cout << "C = consumption as watts" << endl;
	cout << "D = combination of photovoltaics and consumption." << endl;
	cout << "B = output/input power of battery storage as watts" << endl;

		
	cout << "SETUP 1(P=10 watts,C=20 watts): " << case1.calculate(10,20)<< endl;
	cout << "SETUP 2(D=10 watts): " << case1.calculate(10) << endl;
	cout << "SETUP 3(P=10 watts, G=10 watts, B=0  watts) : " << case1.calculate(10, 10,0) << endl;
	cout << "SETUP 3(P=10 watts, G=0  watts, B=10 watts): " << case1.calculate(10, 0, 10) << endl;
}