//
// Instructor: Sai-Keung Wong
// Email:	cswingo@nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2022/03/24
//
#include "mySystem_MonteCarlo.h"
#include <iostream>

using namespace std;

#define MIN_NUM_SAMPLES 2
#define MAX_NUM_SAMPLES 1000000
#define DFT_NUM_SAMPLES 10000		// default

#define MIN_RADIUS		1.f		
#define MAX_RADIUS		10.f	
#define DFT_RADIUS		5.f			// default

MONTE_CARLO_SYSTEM::MONTE_CARLO_SYSTEM( )
{
	cout.precision(8);
	reset();
}

void MONTE_CARLO_SYSTEM::reset()
{
	mRadius = DFT_RADIUS;
	mNumSamples = DFT_NUM_SAMPLES;
	//mPI = 0.0;
    generateUniformSamples( );
    computePI();
	cout << "Estimated pi: " << mPI << endl;
}

//increase the radius of the circle
void MONTE_CARLO_SYSTEM::increaseRadius( )
{
    mRadius += 1;
    if ( mRadius >= MAX_RADIUS) mRadius = MAX_RADIUS;
    cout << "Radius: " << mRadius << endl;
	cout << "Estimated pi: " << mPI << endl;
    generateUniformSamples( );
    computePI();
}

//decrease the number of sample points
void MONTE_CARLO_SYSTEM::decreaseRadius( )
{
    mRadius -= 1;
    if ( mRadius <= MIN_RADIUS) mRadius = MIN_RADIUS;
    cout << "Radius: " << mRadius << endl;
	cout << "Estimated pi: " << mPI << endl;
    generateUniformSamples( );
    computePI();
}

//increase the number of sample points
void MONTE_CARLO_SYSTEM::increaseSampleNum(int increasedAmount)
{
    mNumSamples += increasedAmount;
    if ( mNumSamples > MAX_NUM_SAMPLES) mNumSamples = MAX_NUM_SAMPLES;
    generateUniformSamples( );
    computePI();
}

//decrease the number of sample points
void MONTE_CARLO_SYSTEM::decreaseSampleNum(int decreasedAmount)
{
    mNumSamples -= decreasedAmount;
    if ( mNumSamples < MIN_NUM_SAMPLES ) mNumSamples = MIN_NUM_SAMPLES;
    generateUniformSamples( );
    computePI();
}

//
//Show the system name
//Ask to input the radius of the circle
//Ask to input the number of sample points
//Call computeSamples( ) to compute the sample points and pi
//
void MONTE_CARLO_SYSTEM::askForInput( )
{
	
	cout << "This is a Monte Carlo Simulation." << endl;

    while (true) {
	    cout << "Please input the radius of the circle ["
			<< MIN_RADIUS 
			<< "," 
			<< MAX_RADIUS << "]:" << endl;
	    cin >> mRadius;
        if ( mRadius >= MIN_RADIUS && mRadius <= MAX_RADIUS) break;
    }
    
	//
	while ( true ) {
		cout << "Please input the number of samples [1," << MAX_NUM_SAMPLES << "]:" << endl;
		cin >> mNumSamples;
		if ( mNumSamples > 0 &&  mNumSamples <= MAX_NUM_SAMPLES ) break;
	}
	generateUniformSamples();//iwt
	computePI( );
}

//
// Compute the coordinates of the sample points uniformly.
// There are mNumSamples samples.
//
void MONTE_CARLO_SYSTEM::generateUniformSamples( )
{
	mX.clear( );
	mY.clear( );

	for ( int i = 0; i < mNumSamples; ++i ) {
		double x, y;
		double fx = (rand()) / (double)(RAND_MAX);
		//double fy=1;
		double fy = (rand()) / (double)(RAND_MAX);
        x = 2*fx*mRadius - mRadius;
		y = 2*fy*mRadius - mRadius;
		//y = 0.1;

		mX.push_back( x );		// Do you know why push_back is used?
		mY.push_back( y );		// Do you know why push_back is used?
	}

}

// 
// Compute PI and output it to the console window.
//
void MONTE_CARLO_SYSTEM::computePI()
{
    	int counter = 0;
	for ( int i = 0; i < mNumSamples; ++i ) {
		bool flgInside = false;
		double x = mX[ i ];
		double y = mY[ i ];
		if ( x*x + y*y <= mRadius*mRadius ) {
			flgInside = true;
			++counter;
		}

	}
	mPI =4*counter/(double)mNumSamples;
	//cout << "estimated pi="<<mPI << endl;
}


//
//Return the radius of the circle
//
double MONTE_CARLO_SYSTEM::getRadius( ) const
{
	return mRadius;
}

//Return the number of sample points
int MONTE_CARLO_SYSTEM::getNumSamples( ) const
{
	
	return mNumSamples;
}

double MONTE_CARLO_SYSTEM::getPI() const
{
	return mPI;
}

//
// Input: sampleIndex is the index of the sample. The index starts from 0.
// Return the sample coordinates in (x, y).
// Return the boolean value indicating whether the sample lying inside the circle.
//
bool MONTE_CARLO_SYSTEM::getSample(int sampleIndex, float &x, float &y) const
{
	bool flgInside = false;
	x = mX[ sampleIndex ];
	y = mY[ sampleIndex ];
	if ( x*x +y*y <= mRadius*mRadius ) {
		flgInside = true;
	}//iwt
	/*if (x <= mRadius) {
		flgInside = true;
	}*/

	return flgInside;
}
//
// CODE: 2019/02/25. Do not delete this line.
//