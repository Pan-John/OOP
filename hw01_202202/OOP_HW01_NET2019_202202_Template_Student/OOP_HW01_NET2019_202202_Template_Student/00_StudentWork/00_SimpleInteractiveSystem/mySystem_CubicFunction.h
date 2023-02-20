//
// Instructor: Sai-Keung Wong
// Email:	cswingo@nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2022/03/24
//
#ifndef __MY_CUBIC_FUNCTION_H_
#define __MY_CUBIC_FUNCTION_H_
#include "../../headers.h"
#include <string>
#include "../../primitives/vector3d.h"
#include <vector>
using std::vector;
class CUBIC_FUNCTION
{
protected:
	// ax^3 + bx^2 + cx +d 
	double a, b, c, d;
	double x0, x1;
	int mNumSamples;
public:
	CUBIC_FUNCTION( );
	void askForInput( );
	void getXInterval( double &x0, double &x1 ) const;
	int getNumOfSamples( ) const;
	double getFunctionValue( double x ) const;
	void reset();
	void decreaseB(double dv = 0.01);
	void increaseB(double dv = 0.01);
 
	void decreaseC(double dv = 0.1);
	void increaseC(double dv = 0.1);
	
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
    double getD() const { return d; }
};
#endif
// CODE: 2019/02/25. Do not delete this line.