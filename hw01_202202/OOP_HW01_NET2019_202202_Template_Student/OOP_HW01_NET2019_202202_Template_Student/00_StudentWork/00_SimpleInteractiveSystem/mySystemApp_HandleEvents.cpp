//
// Instructor: Sai-Keung Wong
// Email:	cswingo@nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2022/03/24
//
#include <sstream>
#include "mySystemApp.h"

using namespace std;






void MY_SYSTEM_APP::handle_key05()
{
	switch (mSystemType) {
	case SYSTEM_TYPE_MONTE_CARLO_CIRCLE:
		break;
	case SYSTEM_TYPE_SINECOSINE_FUNCTION:
		mSineCosineFunction.decreaseA();
		updateSineConsineTitle();

		break;
	case SYSTEM_TYPE_CUBIC_FUNCTION:
		break;
	case SYSTEM_TYPE_STUDENT_RECORD_MANAGER:
		break;
	}
}

void MY_SYSTEM_APP::handle_key06()
{
	switch (mSystemType) {
	case SYSTEM_TYPE_MONTE_CARLO_CIRCLE:
		break;
	case SYSTEM_TYPE_SINECOSINE_FUNCTION:
		mSineCosineFunction.increaseA();
		updateSineConsineTitle();

		break;
	case SYSTEM_TYPE_CUBIC_FUNCTION:
		break;
	case SYSTEM_TYPE_STUDENT_RECORD_MANAGER:
		break;
	}
}

void MY_SYSTEM_APP::handle_key07()
{
	switch (mSystemType) {
	case SYSTEM_TYPE_MONTE_CARLO_CIRCLE:
		break;
	case SYSTEM_TYPE_SINECOSINE_FUNCTION:
		mSineCosineFunction.decreaseB();//increased
		updateSineConsineTitle();

		break;
	case SYSTEM_TYPE_CUBIC_FUNCTION:
		break;
	case SYSTEM_TYPE_STUDENT_RECORD_MANAGER:
		break;
	}
}

void MY_SYSTEM_APP::handle_key08()
{
	switch (mSystemType) {
	case SYSTEM_TYPE_MONTE_CARLO_CIRCLE:
		break;
	case SYSTEM_TYPE_SINECOSINE_FUNCTION:
		mSineCosineFunction.increaseB();//decreased
		updateSineConsineTitle();

		break;
	case SYSTEM_TYPE_CUBIC_FUNCTION:
		break;
	case SYSTEM_TYPE_STUDENT_RECORD_MANAGER:
		break;
	}

}

void MY_SYSTEM_APP::handle_key09()
{
	switch (mSystemType) {
	case SYSTEM_TYPE_MONTE_CARLO_CIRCLE:
		mMonteCarloSystem.decreaseSampleNum();
		updateMonteCarloTitle();
		break;
	case SYSTEM_TYPE_SINECOSINE_FUNCTION:
		mSineCosineFunction.decreaseSampleNum();
		updateSineConsineTitle();

		break;
	case SYSTEM_TYPE_CUBIC_FUNCTION:
		break;
	case SYSTEM_TYPE_STUDENT_RECORD_MANAGER:
		break;
	}
}

void MY_SYSTEM_APP::handle_key00()
{
	switch (mSystemType) {
	case SYSTEM_TYPE_MONTE_CARLO_CIRCLE:
		mMonteCarloSystem.increaseSampleNum();
		updateMonteCarloTitle();
		break;
	case SYSTEM_TYPE_SINECOSINE_FUNCTION:
		mSineCosineFunction.increaseSampleNum();
		updateSineConsineTitle();

		break;
	case SYSTEM_TYPE_CUBIC_FUNCTION:
		break;
	case SYSTEM_TYPE_STUDENT_RECORD_MANAGER:
		break;
	}

}

void MY_SYSTEM_APP::handle_key_n()
{
	switch (mSystemType) {
	case SYSTEM_TYPE_MONTE_CARLO_CIRCLE:
		mMonteCarloSystem.decreaseRadius();
		updateMonteCarloTitle();
		break;
	case SYSTEM_TYPE_SINECOSINE_FUNCTION:

		break;
	case SYSTEM_TYPE_CUBIC_FUNCTION:
		mCubicFunction.decreaseB();
		updateCubicFunctionTitle();
		break;
	case SYSTEM_TYPE_STUDENT_RECORD_MANAGER:
		break;
	}
}

void MY_SYSTEM_APP::handle_key_m()
{
	switch (mSystemType) {
	case SYSTEM_TYPE_MONTE_CARLO_CIRCLE:
		mMonteCarloSystem.increaseRadius();
		updateMonteCarloTitle();
		break;
	case SYSTEM_TYPE_SINECOSINE_FUNCTION:

		break;
	case SYSTEM_TYPE_CUBIC_FUNCTION:
		mCubicFunction.increaseB();
		updateCubicFunctionTitle();
		break;
	case SYSTEM_TYPE_STUDENT_RECORD_MANAGER:
		break;
	}
}

void MY_SYSTEM_APP::handle_left_arrow()
{
	switch (mSystemType) {
	case SYSTEM_TYPE_MONTE_CARLO_CIRCLE:
		break;
	case SYSTEM_TYPE_SINECOSINE_FUNCTION:
		mSineCosineFunction.decreaseA();
		updateSineConsineTitle();
		break;
	case SYSTEM_TYPE_CUBIC_FUNCTION:
		mCubicFunction.decreaseC();
		updateCubicFunctionTitle();

		break;
	case SYSTEM_TYPE_STUDENT_RECORD_MANAGER:
		break;
	}
}

void MY_SYSTEM_APP::handle_right_arrow()
{
	switch (mSystemType) {
	case SYSTEM_TYPE_MONTE_CARLO_CIRCLE:
		break;
	case SYSTEM_TYPE_SINECOSINE_FUNCTION:
		mSineCosineFunction.increaseA();
		updateSineConsineTitle();
		break;
	case SYSTEM_TYPE_CUBIC_FUNCTION:
		mCubicFunction.increaseC();
		updateCubicFunctionTitle();

		break;
	case SYSTEM_TYPE_STUDENT_RECORD_MANAGER:
		break;
	}
}

void MY_SYSTEM_APP::handle_key_r()
{
	switch (mSystemType) {
	case SYSTEM_TYPE_MONTE_CARLO_CIRCLE:
		mMonteCarloSystem.reset();
		updateMonteCarloTitle();
		break;
	case SYSTEM_TYPE_SINECOSINE_FUNCTION:
		mSineCosineFunction.reset();
		updateSineConsineTitle();

		break;
	case SYSTEM_TYPE_CUBIC_FUNCTION:
		mCubicFunction.reset();
		updateCubicFunctionTitle();
		break;
	case SYSTEM_TYPE_STUDENT_RECORD_MANAGER:
		mStudentRecordManager.generateRandomSamples();
		
		break;
	}
}

void MY_SYSTEM_APP::askForInput( )
{
	switch( mSystemType ) {
		case SYSTEM_TYPE_MONTE_CARLO_CIRCLE:
			mMonteCarloSystem.askForInput( );
			break;
		case SYSTEM_TYPE_SINECOSINE_FUNCTION:
			mSineCosineFunction.askForInput( );
			break;
		case SYSTEM_TYPE_CUBIC_FUNCTION:
			mCubicFunction.askForInput( );
            updateCubicFunctionTitle();
			break;
		case SYSTEM_TYPE_STUDENT_RECORD_MANAGER:
			mStudentRecordManager.askForInput( );
			break;
	}
}

void MY_SYSTEM_APP::updateMonteCarloTitle( )
{
    string title;
    string result;
    ostringstream strs;
    ostringstream strs_int;
	ostringstream strs_float;

    double pi;
    int numSamples;
    title = "SYSTEM_TYPE_MONTE_CARLO_SIMULATION";

	//
	getStudentInfo();
	title = title + ":" + getStudentInfo() + "   ";
	//
    //mMonteCarloSystem.reset( ); this is wrong 
    pi = mMonteCarloSystem.getPI( );
    strs << pi;
    title = title + "  pi:";
    title = title + strs.str();
    numSamples = mMonteCarloSystem.getNumSamples();
    strs_int << numSamples;
    title = title + "  #Samples:";
    title = title + strs_int.str();
	//
	double radius = mMonteCarloSystem.getRadius();
	strs_float << radius;
	title = title + "  Radius:";
	title = title + strs_float.str();
	//

    glutSetWindowTitle(title.data());
}

void MY_SYSTEM_APP::updateSineConsineTitle( )
{
    string title;
    string result;
    ostringstream strs;
    ostringstream strs_d;

    title = "SYSTEM_TYPE_SINECOSINE_FUNCTION (a*cos(b*x))  ";

	//
	getStudentInfo();
	title = title + ":" + getStudentInfo() + "   ";

    //mSineCosineFunction.reset( );

    {
    int numSamples = mSineCosineFunction.getNumOfSamples();
    strs_d.str("");
    strs_d.clear();
    
    strs_d << numSamples;
    title = title + "  #Samples:";
    title = title + strs_d.str();
    }

    {
    double a = mSineCosineFunction.getA();
    strs_d.str("");
    strs_d.clear();
    strs_d.precision(5);
    strs_d << a;
    title = title + "  a:";
    title = title + strs_d.str();
    }

    {
    double b = mSineCosineFunction.getB();
    strs_d.str("");
    strs_d.clear();
    strs_d.precision(5);
    strs_d << b;
    title = title + "  b:";
    title = title + strs_d.str();
    }

    //
    glutSetWindowTitle(title.data());
}

void MY_SYSTEM_APP::updateCubicFunctionTitle()
{
    string title;
    string result;
    ostringstream strs;
    ostringstream strs_d;

    title = "SYSTEM_TYPE_CUBIC_FUNCTION  ";

	//
	getStudentInfo();
	title = title + ":" + getStudentInfo() + "   ";

    {
    double a = mCubicFunction.getA();
    strs_d.str("");
    strs_d.clear();
    strs_d.precision(5);
    strs_d << a;
    title = title + "  a:";
    title = title + strs_d.str();
    }

    {
    double b = mCubicFunction.getB();
    strs_d.str("");
    strs_d.clear();
    strs_d.precision(5);
    strs_d << b;
    title = title + "  b:";
    title = title + strs_d.str();
    }

    {
    double c = mCubicFunction.getC();
    strs_d.str("");
    strs_d.clear();
    strs_d.precision(5);
    strs_d << c;
    title = title + "  c:";
    title = title + strs_d.str();
    }

    {
    double d = mCubicFunction.getD();
    strs_d.str("");
    strs_d.clear();
    strs_d.precision(5);
    strs_d << d;
    title = title + "  d:";
    title = title + strs_d.str();
    }
    //
    glutSetWindowTitle(title.data());
}

void MY_SYSTEM_APP::updateRecordManagerTitle()
{
	string title;

	title = "SYSTEM_TYPE_STUDENT_RECORD_MANAGER  ";

	//
	getStudentInfo();
	title = title + ":" + getStudentInfo() + "   ";
	glutSetWindowTitle(title.data());
}

bool MY_SYSTEM_APP::specialFunc(int key, int x, int y)
{
    string title;
	//cout << "special key:" << key << endl;

	switch( key ) {
	case GLUT_KEY_F1:
		mSystemType = SYSTEM_TYPE_MONTE_CARLO_CIRCLE;
		updateMonteCarloTitle();
        cout << "mSystemType = SYSTEM_TYPE_MONTE_CARLO_CIRCLE" << endl;
		break;
	case GLUT_KEY_F2:
		mSystemType = SYSTEM_TYPE_SINECOSINE_FUNCTION;
		updateSineConsineTitle();
        cout << "mSystemType = SYSTEM_TYPE_SINECOSINE_FUNCTION" << endl;
		break;
	case GLUT_KEY_F3:
		mSystemType = SYSTEM_TYPE_CUBIC_FUNCTION;
        //title = "SYSTEM_TYPE_CUBIC_FUNCTION";
        //glutSetWindowTitle(title.data( ));
		cout << "mSystemType = SYSTEM_TYPE_CUBIC_FUNCTION" << endl;
        updateCubicFunctionTitle();
		break;
    case GLUT_KEY_F4:
		mSystemType = SYSTEM_TYPE_STUDENT_RECORD_MANAGER;
		title = "SYSTEM_TYPE_STUDENT_RECORD_MANAGER";
        //glutSetWindowTitle(title.data( ));
        cout << "mSystemType = SYSTEM_TYPE_STUDENT_RECORD_MANAGER" << endl;
		updateRecordManagerTitle();
		break;
	}
	return true;
}

bool MY_SYSTEM_APP::handleKeyEvent( unsigned char key )
{
	bool flgHandled = false;
	switch ( key ) {
		case 's':
		case 'S': //fall through
			showMyStudentInfo( );
			break;
		case 'i':
		case 'I':
			askForInput( );
			break;
		case 'g':
		case 'G':
			mFlgShow_Grid = !mFlgShow_Grid;
			break;
    
        case '>':
			handle_right_arrow();
            break;
        case '<':
			handle_left_arrow();
            break;
		case '5':
			handle_key05();
			break;
		case '6':
			handle_key06();
			break;
		case '7':
			handle_key07();
			break;
            case '8':
                handle_key08();
                break;
            
                case '9':
                handle_key09();
                break;
            case '0':
                handle_key00();
                break;
			case 'r':
				handle_key_r();
				break;
			case 'n':
				handle_key_n();
				break;
			case 'm':
				handle_key_m();
				break;
	}
	return flgHandled;
}

bool MY_SYSTEM_APP::mouseMotionFunc( int mx, int my )
{
	static vector3 color( 1.0, 0.0, 0.0 );
	if ( mMouseButton == GLUT_LEFT_BUTTON ) {
		//cout << "mouseMotionFunc GLUT_LEFT_BUTTON" << endl;
		float x, y, z;
		mCamera->getCoordinates( x, y, z, (float) mx, (float) my );

		float rf = (rand()%1000)/1000.0f*0.5f;
		color += vector3(0.1f, 0.07f, 0.11f*rf);
		//clickAt( (int) x, (int) z, color );

	} else {
		//if ( mPickedObj == 0 ) {
		return FREE_CANVAS_2D::mouseMotionFunc( mx, my );
		//}
	}

	//cout << "here 5" << endl;

	//float x, y, z;
	//mCamera->getCoordinates( x, y, z, mx, my );
	//cout << "Set Position XZ:" << x << "\t" << z << endl;
	return true;
}

bool MY_SYSTEM_APP::mouseFunc( int button, int state, int mx, int my )
{
	//cout << "button:" << button << endl;
	//if ( mPickedObj == 0 || button == GLUT_MIDDLE_BUTTON ) {
	//if ( button == 3 || button == 4 ) {

	float x, y, z;
	mCamera->getCoordinates( x, y, z, (float) mx, (float) my );

	vector3 color( 1.0, 0.0, 0.0 );
	mMouseButton = button;
	if ( button == GLUT_LEFT_BUTTON ) {
		//clickAt( (int) x, (int) z, color );
	} else {
		return FREE_CANVAS_2D::mouseFunc( button, state, mx, my );
	}
	return true;
}


bool MY_SYSTEM_APP::passiveMouseFunc( int mx, int my )
{
	float x, y, z;
	mCamera->getCoordinates( x, y, z, (float) mx, (float) my );
	return true;
}
// CODE: 2019/02/25. Do not delete this line.