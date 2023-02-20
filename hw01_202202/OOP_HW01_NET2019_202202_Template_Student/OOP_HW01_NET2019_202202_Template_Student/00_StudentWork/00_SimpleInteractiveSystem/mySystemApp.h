//********************************************
// Student Name			:Ching_Yang Pan
// Student ID			:109700005
// Student Email Address:ericpan9889@gmail.com
//********************************************
//
//
// Instructor: Sai-Keung Wong
// Email:	cswingo@nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2022/03/24
//
#ifndef __MY_SYSTEM_APP_APP_H_
#define __MY_SYSTEM_APP_APP_H_
/////////////////////////////////////////////
#include "../headers.h"
#include <string>
#include "../openGLbasic/opengl_stuff.h"
#include "../freeCanvas2D/freeCanvas2D.h"
#include "../textureManager/texture.h"
/////////////////////////////////////////////
#include "mySystem_MonteCarlo.h"
#include "mySystem_SineCosineFunction.h"
#include "mySystem_CubicFunction.h"
#include "mySystem_StudentRecordManager.h"

#define SYSTEM_TYPE_MONTE_CARLO_CIRCLE		1
#define SYSTEM_TYPE_SINECOSINE_FUNCTION		2
#define SYSTEM_TYPE_CUBIC_FUNCTION			3
#define SYSTEM_TYPE_STUDENT_RECORD_MANAGER	4

/////////////////////////////////////////////

using namespace ns_opengl;
class MY_SYSTEM_APP : public FREE_CANVAS_2D
{
protected:
	bool mFlgShow_Grid;
	int mMouseButton;
	//
    void updateMonteCarloTitle();
    void updateSineConsineTitle( );
        void updateCubicFunctionTitle();
		void updateRecordManagerTitle();
		
    //
	void drawOrigin( ) const;
	void draw_MonteCarlo_Circle( ) const;
	void draw_System_Content( ) const;
	void draw_SineCosineFunction( ) const;
	void draw_CubicFunction( ) const;
	void draw_StudentRecordManager( ) const;
	void askForInput( );
	
	void handle_key05();
	void handle_key06();
	void handle_key07();
	void handle_key08();
	void handle_key09();
	void handle_key00();
	void handle_key_r();

	void handle_key_n();
	void handle_key_m();

	void handle_left_arrow();
	void handle_right_arrow();

	//
	void showMyStudentInfo( ) const;
	//
	const char* getStudentInfo() const;
public:
	MY_SYSTEM_APP( );
	virtual void update( );
	virtual void draw( ) const;
	virtual void initApp( );
	//
	bool specialFunc(int key, int x, int y);
	bool handleKeyEvent( unsigned char key );
	bool passiveMouseFunc( int mx, int my );
	bool mouseMotionFunc( int x, int y );
	bool mouseFunc( int button, int state, int x, int y );
	//////////////////////////////////////////////////
protected:
	int mSystemType;
	MONTE_CARLO_SYSTEM mMonteCarloSystem;
	SINECOSINE_FUNCTION mSineCosineFunction;
	CUBIC_FUNCTION mCubicFunction;
	STUDENT_RECORD_MANAGER mStudentRecordManager;
};

#endif
// CODE: 2019/02/25. Do not delete this line.