//
// Instructor: Sai-Keung Wong
// Email:	cswingo@nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2022/03/24
//
#ifndef __MY_SYSTEM_MONTE_CARLO_H_
#define __MY_SYSTEM_MONTE_CARLO_H_
#include "../headers.h"
#include <string>
#include "../primitives/vector3d.h"
#include <vector>
using std::vector;
class MONTE_CARLO_SYSTEM
{
protected:
	double mRadius;
	int mNumSamples;   
	vector<float> mX;
	vector<float> mY;
	double mPI;
	//
	void generateUniformSamples( );
public:
	void decreaseSampleNum(int decreasedAmount = 2000);
    void increaseSampleNum(int increasedAmount = 2000);
   
    void increaseRadius( );
    void decreaseRadius( );
	void update(  bool flg_timer = false ) { }
	void clickAt( int x, int y, const vector3 &color ) { }
	void computePI();
public:
	MONTE_CARLO_SYSTEM( );
	void askForInput( );
    void reset();
	double getPI() const;
    
	double getRadius( ) const;
	int getNumSamples( ) const;
	bool getSample(int sampleIndex, float &x, float &y) const;
};
#endif
// CODE: 2019/02/25. Do not delete this line.