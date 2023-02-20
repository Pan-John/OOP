//
// Instructor: Sai-Keung Wong
// Email:	cswingo@nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2022/03/24
//
#ifndef __MY_SINECOSINE_FUNCTION_H_
#define __MY_SINECOSINE_FUNCTION_H_
#include "../headers.h"
#include <string>
#include "../primitives/vector3d.h"
#include <vector>
using std::vector;





class SINECOSINE_FUNCTION
{
protected:
	double a, b;
	double x0, x1;
	int mNumSamples;
protected:
public:
	SINECOSINE_FUNCTION( );
    void reset();
    void increaseA(double increasedAmount = 0.05);
    void decreaseA(double decreasedAmount = 0.05);
    void increaseB(double increasedAmount = 1);      
    void decreaseB(double decreasedAmount = 1);
    void increaseSampleNum(int increasedAmount = 2);
    void decreaseSampleNum(int decreasedAmount = 2);
    double getA() const { return a;}
    double getB() const { return b;}

    void askForInput( );
	void getXInterval( double &x0, double &x1 ) const;
	int getNumOfSamples( ) const;
	double getFunctionValue( double x ) const;

};
#endif
// CODE: 2019/02/25. Do not delete this line.