//
// Instructor: Sai-Keung Wong
// Email:	cswingo@nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2022/03/24
//
#include "mySystem_CubicFunction.h"
#include <iostream>

using namespace std;

namespace {

#define MIN_X	-100
#define MAX_X	100
#define DFT_A 0.02
#define DFT_B -0.3
#define DFT_C 0.5
#define DFT_D 0.5

#define DFT_NUM_SAMPLES 250
}

CUBIC_FUNCTION::CUBIC_FUNCTION( )
{
	reset();
}


void CUBIC_FUNCTION::reset()
{
	/*
	Modify if you want
	*/
	x0 = MIN_X;
	x1 = MAX_X;
	mNumSamples = DFT_NUM_SAMPLES;

	a = DFT_A;
	b = DFT_B;
	c = DFT_C;
	d = DFT_D;
}

void CUBIC_FUNCTION::increaseB(double dv)
{
	/*
	Modify if you want
	*/
    b += dv;
}

    void CUBIC_FUNCTION::decreaseB(double dv)
    {
	/*
	Modify if you want
	*/
    b -= dv;

    }

	void CUBIC_FUNCTION::increaseC(double dv)
	{
	/*
	Modify if you want
	*/
		c += dv;
	}

	void CUBIC_FUNCTION::decreaseC(double dv)
	{
	/*
	Modify if you want
	*/
		c -= dv;

	}

void CUBIC_FUNCTION::askForInput( )
{
	//
	//ax^3 + bx^2 + cx + d
	//Show the system name
	//Ask to input a, b, c, d
	//Ask to input the range of x in [-100, 100]
	//Ask to input the number of sample points
	//
	cout << "CUBIC_FUNCTION" << endl;
	
	cout << "Cubic equation: ax^3 + bx^2 + cx + d" << endl;
	cout << "input a:";
	cin >> a;
	cout << "input b:";
	cin >> b;
    cout << "input c:";
    cin >> c;
    cout << "input d:";
    cin >> d;
    //
	cout << "Input the range of x in [-100, 100]:" << endl;
	cin >> x0 >> x1;
	cout << "Input the number of sample points:" << endl;
	cin >> mNumSamples;
}

void CUBIC_FUNCTION::getXInterval( double &x0, double &x1 ) const
{
	//Return the range of x in x0 and x1.
	x0 = this->x0;
	x1 = this->x1;
}

int CUBIC_FUNCTION::getNumOfSamples( ) const
{
	//Return the number of samples
	//return mNumSamples;
	return mNumSamples;
}

double CUBIC_FUNCTION::getFunctionValue( double x ) const
{
	//Compute ax^3 + bx^2 + cx + d
	//i.e., compute the value a*x*x*x + b*x*x + c*x + d
	//return a*x*x*x + b*x*x + c*x + d;//too naive!
	return ((a * x + b) * x + c) * x + d;//horner form
}
// CODE: 2022/03/24. Do not delete this line.