//********************************************
// Student Name			:
// Student ID			:
// Student Email Address:
//********************************************
//
// Prof. Sai-Keung Wong
// Email:	cswingo@nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2022/04/25
//
#include "mySystem_2048.h"
#include <iostream>

using namespace std;

static unsigned char specialKeys[] = {
    GLUT_KEY_UP,
    GLUT_KEY_DOWN,
    GLUT_KEY_LEFT,
    GLUT_KEY_RIGHT
};

int numSpecialKeys = sizeof(specialKeys)/sizeof(unsigned char);

MY_2048::MY_2048( )
{
    mNX = 4;
    mNZ = 4;
    reset( );

    mPositionX = 0;
    mPositionZ = 0;
    mFlgFocus = true;
    //
    flg_AutoPlay = false;
}

MY_2048::MY_2048( int nx, int nz )
{

    mNX = nx;// # col
    mNZ = nz;// # row
    reset();

    mPositionX = 0;
    mPositionZ = 0;
    mFlgFocus = true;
    //
    flg_AutoPlay = false;
}

int MY_2048::getRand(int x0, int x1)
{
    return rand() % (x1 - x0 + 1) + x0;
}

void MY_2048::setDimension(int nx, int nz)
{
    mFlgFocus = true;
    
    //
    // Implement your own stuff
    //
    mNX = nx;
    mNZ = nz;
    reset();
}

void MY_2048::setFocus( bool flg )
{
    mFlgFocus = flg;
}

void MY_2048::setPosition( int x, int z )
{
    mPositionX = x;
    mPositionZ = z;
}

//
// Copy the m's previous board 
// to the object's mBoard.
//
void MY_2048::copyPrevious( const BASE_SYSTEM *m )
{
    for ( int j = 0; j < mNZ; ++j ) {
        for ( int i = 0; i < mNX; ++i ) {
            mBoard[j][i] = ((MY_2048*)m)->mPreviousBoard[ j ][ i ];
        }
    }
}

void MY_2048::copy(int src[][MAX_2048_NX], int tgt[][MAX_2048_NX])
{
    for (int j = 0; j < mNZ; ++j) {
        for (int i = 0; i < mNX; ++i) {
            tgt[j][i] = src[j][i];
        }
    }
}

//
//reset the game board
//
void MY_2048::reset( )
{
    mEvent = 0;
    ///////////////////////////////////////
    //
    // Implement your own stuff
    //
    for (int i = 0; i < mNX; i++) {
        for (int j = 0; j < mNZ; j++) {
            mBoard[j][i] = 0;// [row][col]
            //mPreviousBoard[j][i] = 0;
        }
    }
    copy(mBoard, mPreviousBoard);
}

//
// show messages and ask for input (if any)
//
void MY_2048::askForInput()
{
    cout << "MY_2048" << endl;
    cout << "Key usage:" << endl;
    cout << "1: generate randomly the numbers 2 and 4 for all the cells" << endl;
    cout << "2: generate randomly the numbers 2, 4 and 8 for all the cells" << endl;
    cout << "3: generate randomly the numbers for all the cells" << endl;
    cout << "r: clear all the cells" << endl;
    cout << " " << endl;
    cout << "UP, DOWN, LEFT, RIGHT: move the numbers to the respective side" << endl;
}

//
// randomly generate a new number
//
void MY_2048::generateNumber( )
{
    //
    // Implement your own stuff
    //
    int freespace = 0;
    for (int j = 0; j < mNZ; ++j) {
        for (int i = 0; i < mNX; ++i) {
            if (mBoard[j][i] == 0) {
                freespace = 1;
                break;
            }
        }
    }
    if (freespace == 0)return;

    int xcoord = getRand(0, mNX - 1), ycoord = getRand(0, mNZ - 1);
    while (mBoard[ycoord][xcoord] != 0) {
        xcoord = getRand(0, mNX - 1);
        ycoord = getRand(0, mNZ - 1);
    }
    mBoard[ycoord][xcoord] = getRand(1, 2) * 2;
}

void MY_2048::rotate() {
    for (int j = 0; j < mNZ; ++j) {
        for (int i = 0; i < mNX; ++i) {
            int jx;
            int ix;
            ix = j;
            jx = mNX - i - 1;
            mTmpBoard[jx][ix] = mBoard[j][i];
        }
    }
    copy(mTmpBoard, mBoard);
}
void MY_2048::moveDown( )
{
    //
    // Implement your own stuff
    //    
    for (int i = 0; i < mNZ - 1; i++) {// this for loop check if the adjacent (up and down) block can merge
        for (int j = 0; j < mNX; j++) {//for every column
            int  row = i + 1;//search up from the 2nd floor 
            while (row < mNZ && mBoard[row][j] == 0) {
                row++;
            }
            if (row != mNZ && mBoard[i][j] == mBoard[row][j]) {//merge
                mBoard[i][j] *= 2;
                mBoard[row][j] = 0;
            }
        }
    }

    for (int i = 0; i < mNX; i++) {// and this one do the move after all is merge
        int count = 0;
        for (int j = 0; j < mNZ; j++) {
            if (mBoard[j][i] == 0)continue;
            int temp;
            temp = mBoard[count][i];
            mBoard[count][i] = mBoard[j][i];
            mBoard[j][i] = temp;
            count++;
        }
    }
}
void MY_2048::moveUp( )
{
    //
    // Implement your own stuff
    //
    rotate();
    rotate();
    moveDown();
    rotate();
    rotate();
}
void MY_2048::moveLeft( )
{
    //
    // Implement your own stuff
    //
    rotate();
    rotate();
    rotate();
    moveDown();
    rotate();

}
void MY_2048::moveRight( )
{
    //
    // Implement your own stuff
    //
    rotate();
    moveDown();
    rotate();
    rotate();
    rotate();
}

void MY_2048::generateNumbers_All_2to4( )
{
    //
    // Implement your own stuff
    //
    reset();
    for (int j = 0; j < mNZ; j++) {
        for (int i = 0; i < mNX; i++) {

            int value = 1 + rand() % 2;// 1 or 2
            int number = 1;
            number = number << value;
            // "a << b" means to shift a's binary b space ( plus a 0 ) aka multiply by 2
            // e.g. 1<<4 gets us 16
            // here we have 1<<1 or 1<<2, which gets us 2 or 4
            mBoard[j][i] = number;// [row][col]
        }
    }

}
void MY_2048::generateNumbers_All_2to8( )
{
    //
    // Implement your own stuff
    //
    reset();
    for (int j = 0; j < mNZ; j++) {
        for (int i = 0; i < mNX; i++) {

            int value = 1 + rand() % 3;// 123
            int number = 1;
            number = number << value;
            mBoard[j][i] = number;
        }
    }
}
void MY_2048::generateNumbers_All( )
{
    //
    // Implement your own stuff
    //
    reset();
    for (int j = 0; j < mNZ; j++) {
        for (int i = 0; i < mNX; i++) {

            int value = 1 + rand() % 11;// 1~11
            int number = 1;
            number = number << value;
            mBoard[j][i] = number;
        }
    }
}

void MY_2048::handleKeyPressedEvent( unsigned char key )
{
    switch( key ) {
    case 'r':
    case 'R':
        reset( );
        break;
    case '1':
        generateNumbers_All_2to4( );
        break;
    case '2':
        generateNumbers_All_2to8( );
        break;
    case '3':
        generateNumbers_All( );
        break;

    case 'a':
    case 'A':
        //flg_AutoPlay
        //for one step
        flg_AutoPlay = true;
        update();
        flg_AutoPlay = false;
        break;
    case ' ':
        flg_AutoPlay = !flg_AutoPlay;
        break;
    }
}

bool MY_2048::performAction( unsigned char key ) {
    
    bool flgDone = false;

    switch( key ) {
    case GLUT_KEY_UP:
        flgDone = true;
        moveUp( );
        mEvent = GLUT_KEY_UP;
        break;
    case GLUT_KEY_DOWN:
        flgDone = true;
        moveDown( );
        mEvent = GLUT_KEY_DOWN;

        break;
    case GLUT_KEY_LEFT:
        flgDone = true;
        moveLeft( );
        mEvent = GLUT_KEY_LEFT;

        break;
    case GLUT_KEY_RIGHT:
        flgDone = true;
        moveRight( );
        mEvent = GLUT_KEY_RIGHT;

        break;

    }

    if ( flgDone ) {
        generateNumber( );
    }
    return flgDone;
}

void MY_2048::handleSpecialKeyPressedEvent( unsigned char key )
{
    //
    // It takes a long time to show a message!
    //
    //cout << "MY_2048::handleSpecialKeyPressedEvent:" << key << endl;
    //performAction( key );

    int initBoard[MAX_2048_NZ][MAX_2048_NX];
    copy(mBoard, initBoard);
    bool flg_action = performAction(key);
    if (flg_action) {
        copy(initBoard, mPreviousBoard);
    }
}



//
// The update( ) function is called every frame.
//
// Design an algorithm to automatically perform
// one step.
//
double MY_2048::getLargestValue() {
    //double largest=0.0;
    //for (int i = 0; i < mNZ; i++) {
    //    for (int j = 0; j < mNX; j++) {
    //        if (mBoard[j][i] > largest) {
    //            largest = mBoard[j][i];
    //        }
    //    }
    //}
    //return largest;
    
    double score = 0.0;
    for (int j = 0; j < mNZ; ++j) {
        for (int i = 0; i < mNX; ++i) {
            double s = mBoard[j][i];
            score += s * pow(s, 0.35);
        }
    }
    return score;
}

double MY_2048::play_Smart_Recursive(
    int numSteps,
    unsigned char action_key,
    int board[][MAX_2048_NX]
    ) {

    double tScore = 0;
    if (numSteps <= 0) {
        tScore = getLargestValue();
        return tScore;
    }

    copy(board, mBoard);
    handleSpecialKeyPressedEvent(action_key);

    int initBoard[MAX_2048_NZ][MAX_2048_NX];
    copy(mBoard, initBoard);
    double score = 0.0;

    for (int i = 0; i < numSpecialKeys; ++i) {
        score = score* pow(0.85,numSteps)+ play_Smart_Recursive(numSteps - 1, specialKeys[i], initBoard);
    }


    return score;

}

double MY_2048::play_Smart(
    int numForwardMoves,
    unsigned char action_index) {//the first iteration, there are four new boards
    double score = 0;
    int initBoard[MAX_2048_NZ][MAX_2048_NX];

    copy(mBoard, initBoard);
    double fScore = play_Smart_Recursive(numForwardMoves,action_index,initBoard);
    copy(initBoard, mBoard);

    score = fScore;
    return score;

}

void MY_2048::play_Smart(int numForwardMoves) {//the OG Board
    vector<double> score(numSpecialKeys, 0);//numSPecialKeys=4
    for (int i = 0; i < numSpecialKeys; i++) {
        score[i] = play_Smart(numForwardMoves, specialKeys[i]);
    }

    double best_score = score[0];// set bestscore as the first one...
    int best_action_index = 0;
    for (int i = 1; i < numSpecialKeys; i++) {// ...and compare from the second one
        if (score[i] > best_score) {
            best_score = score[i];
            best_action_index = i;
        }
    }
    handleSpecialKeyPressedEvent(specialKeys[best_action_index]);
}

void MY_2048::update( )
{
    //
    // It takes a long time to show a message!
    //
    if (!flg_AutoPlay) return;

    cout << "MY_2048::update( )" << endl;
    //cout << "MY_2048::flg_AutoPlay:\t" << flg_AutoPlay << endl;

    //
    // Implement your own stuff
    //
    int numForwardMoves = 7;
    play_Smart(numForwardMoves);
}
bool MY_2048::isAutoPlay() const
{
    return flg_AutoPlay;
}