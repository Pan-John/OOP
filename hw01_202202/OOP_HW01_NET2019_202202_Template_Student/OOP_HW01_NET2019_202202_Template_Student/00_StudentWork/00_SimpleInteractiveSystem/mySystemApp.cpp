//
// Instructor: Sai-Keung Wong
// Email:	cswingo@nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2022/03/24
//
#include "mySystemApp.h"

using namespace std;

#define STUDENT_INFO "Name:Ching-Yang Pan   ID:109700005"

void MY_SYSTEM_APP::showMyStudentInfo( ) const
{
	cout << "*******************************" << endl;
    cout << "Date:2022/03/24" << endl;
	cout << "Student ID:109700005\t" << endl;
	cout << "Student Name:Ching-Yang Pan\t" << endl;
	cout << "Student Email:ericpan9889@gmail.com\t" << endl;
	cout << "*******************************" << endl;
}

MY_SYSTEM_APP::MY_SYSTEM_APP( )
{
	mSystemType = SYSTEM_TYPE_MONTE_CARLO_CIRCLE;
    string title = STUDENT_INFO;
		//glutSetWindowTitle(title.data( ));
	//updateMonteCarloTitle();
}

const char* MY_SYSTEM_APP::getStudentInfo() const {
	return STUDENT_INFO;
}

void MY_SYSTEM_APP::initApp( )
{
	mFlgShow_Grid = true;
}

void MY_SYSTEM_APP::update( )//iwt
{
	switch (mSystemType) {
	case SYSTEM_TYPE_MONTE_CARLO_CIRCLE:
		updateMonteCarloTitle();
		break;
	case SYSTEM_TYPE_SINECOSINE_FUNCTION:
		updateSineConsineTitle();
		break;
	case SYSTEM_TYPE_CUBIC_FUNCTION:
		updateCubicFunctionTitle();
		break;
	case SYSTEM_TYPE_STUDENT_RECORD_MANAGER:
		updateRecordManagerTitle();
		break;
	default:
		break;
	}
	//updateMonteCarloTitle();//iwt
}
// CODE: 2022/03/24. Do not delete this line.