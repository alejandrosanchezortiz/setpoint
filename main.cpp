#include <iostream>
#include <cstring>
#include "setpoint.h"

using namespace std;

int main(int argc, char *argv[] )
{
	setpoint case1;
        
        cout << endl;
	cout << "P = photovoltaics as watts" << endl;
	cout << "C = consumption as watts" << endl;
	cout << "D = combination of photovoltaics and consumption" << endl;
	cout << "G = grid metter as watts" << endl;
	cout << "B = output/input power of battery storage as watts" << endl;
	cout << endl;

        if (argc==1) //let's show some examples
	{	
		cout << "*No parameters introduced. Let's show some examples:" << endl;
		cout << "SETUP 1(P=10 watts,C=20 watts): " << case1.calculate(10,20)<< endl;
		cout << "SETUP 3(D=10 watts): " << case1.calculate(10) << endl;
		cout << "SETUP 4(P=10 watts, G=10 watts, B=0  watts) : " << case1.calculate(10, 10,0) << endl;
		cout << "SETUP 4(P=10 watts, G=0  watts, B=10 watts): " << case1.calculate(10, 0, 10) << endl;
	}
	else
	{
		float p,c,d,g,b,setpoint;
		int setup;
		setup = atoi(argv[1]);
		
		switch(setup)
		{
			case 1:
				cout << "Setup 1:" << endl;
				cout << "Insert P: ";
				cin >> p;
				cout << "Insert C: ";
				cin >> c;
				setpoint = case1.calculate(p,c);
				cout << "SETUP 1(P="<< p <<" watts,C="<< c <<" watts): " << setpoint;
				break;
			case 2:
				cout << "Setup 3: " << endl;
				cout << "Insert D: ";
				cin >> d;
				setpoint = case1.calculate(d);
			 	cout << "SETUP 3(D=" << d << " watts): " << setpoint;
			 	break;
			case 3:
				cout << "Setup 4:" << endl;
				cout << "Insert P: ";
				cin >> p;
				cout << "Insert G: ";
				cin >> g;
				cout << "Insert B: "; 
				cin >> b;
				setpoint = case1.calculate(p, g, b);
				cout << "SETUP 4(P=" << p << " watts, G=" << g << "  watts, B= " << b << " watts): " << setpoint; 
				break;			 					
			default:
				cout << "Invalid argument " << argv[1] << ". Valid arguments:" << endl;
				cout << "1 - For setup 1" << endl;
				cout << "2 - For setup 3" << endl;
				cout << "3 - For setup 4" << endl;
				return 0;
		} 
		
		if (setpoint>0) cout << " > CHARGE" << endl;
		if (setpoint<0) cout << " > DISCHARGE" << endl;
		if (setpoint==0) cout << " > DO NOT CHARGE OR DISCHARGE" << endl;		
	}

}