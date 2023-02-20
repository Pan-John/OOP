//
// Instructor: Sai-Keung Wong
// Email:	cswingo@nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2022/03/24
//
#include "mySystem_SineCosineFunction.h"
#include <iostream>

using namespace std;

namespace {
//minimum number of sample points
#define MIN_NUM_SAMPLES 2

//maximum number of sample points
#define MAX_NUM_SAMPLES 100

//default number of sample points
#define DFT_NUM_SAMPLES 50  

#define X_MIN -10.0
#define X_MAX 10.0

#define DFT_A	1.0		// the default value of a
#define DFT_B	2.0		// the default value of b
};

SINECOSINE_FUNCTION::SINECOSINE_FUNCTION( )
{
	reset();
}

void SINECOSINE_FUNCTION::increaseA(double increasedAmount)
{
    a += increasedAmount;

}

   void SINECOSINE_FUNCTION::decreaseA(double decreasedAmount)
{
    a -= decreasedAmount;

}

    void SINECOSINE_FUNCTION::increaseB(double increasedAmount)
{
    b += increasedAmount;

}

void SINECOSINE_FUNCTION::decreaseB(double decreasedAmount)
{
	b -= decreasedAmount;
}

void SINECOSINE_FUNCTION::increaseSampleNum(int increasedAmount )
{
    mNumSamples += increasedAmount;
	if (mNumSamples >= MAX_NUM_SAMPLES) mNumSamples = MAX_NUM_SAMPLES;

}

void SINECOSINE_FUNCTION::decreaseSampleNum(int decreasedAmount)
   {
    mNumSamples -= decreasedAmount;
    if (mNumSamples <= MIN_NUM_SAMPLES) mNumSamples = MIN_NUM_SAMPLES;

    }

//
// reset
void SINECOSINE_FUNCTION::reset()
{
	x0 = X_MIN;
	x1 = X_MAX;
	mNumSamples = DFT_NUM_SAMPLES;
	a = DFT_A;
	b = DFT_B;
}

//
//Show the system name
//Ask to input a, b
//Ask to input the range of x in [-10, 10]
//Ask to input the number of sample points
//
void SINECOSINE_FUNCTION::askForInput( )
{
	cout << "SINECOSINE_FUNCTION" << endl;
	cout << "Input the coeffients, a and b: a cos(b*x)" << endl;
	cin >> a >> b;
	cout << "Input the range of x in [-10, 10]:" << endl;
	cin >> x0 >> x1;
	cout << "Input the number of sample points:" << endl;
	cin >> mNumSamples;
}
//
// Get the interval of x
// by-reference
// (x0, x1) formal parameters
// x0: minimum x 
// x1: maximum x
//
void SINECOSINE_FUNCTION::getXInterval( double &x0, double &x1 ) const
{
	//x0 = 1;
	x0 = this->x0;
	x1 = this->x1;
}

//
// Return the number of samples for drawing the curve
//
int SINECOSINE_FUNCTION::getNumOfSamples( ) const
{
	return mNumSamples;
}

//
// Get the function value for x
//
double SINECOSINE_FUNCTION::getFunctionValue( double x ) const
{
	return a *cos(b * x);
	//return b*sin(a*x)+a;
}
// CODE: 2019/02/25. Do not delete this line.