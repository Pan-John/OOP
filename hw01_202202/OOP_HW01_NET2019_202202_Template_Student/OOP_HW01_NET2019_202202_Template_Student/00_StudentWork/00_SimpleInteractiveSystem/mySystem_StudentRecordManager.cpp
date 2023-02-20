//
// Instructor: Sai-Keung Wong
// Email:	cswingo@nycu.edu.tw
//			wingo.wong@gmail.com
//
// National Yang Ming Chiao Tung University, Taiwan
// Computer Science
// Date: 2022/03/24
//
#include "mySystem_StudentRecordManager.h"
#include <iostream>

using namespace std;

STUDENT_RECORD_MANAGER::STUDENT_RECORD_MANAGER( )
{
	mNumStudents = 0;
}

void STUDENT_RECORD_MANAGER::askForInput( )
{
	//Show the system title
	//Ask to input the number of students
	//Ask to input the score of each student
	//Show the average
	//Show the standard deviation
	//Show the scores in an ascending order
	//
	cout << "STUDENT_RECORD_MANAGER" << endl;
	while ( true ) {
		cout << "Input the number of students [2, 100]:" << endl;

		cin >> mNumStudents;
		if ( mNumStudents >= 2 && mNumStudents <=100 ) break;
	}
	cout << "Input the scores" << endl;
	mScore.clear( );
	for ( int i = 0; i < mNumStudents; ++i ) {
		int a;
		cin >> a;
		mScore.push_back( a );
	}

	
	sortScores( );
	showSortedScores( );

	computeAverage();
	computeStandardDeviation();

	cout << "mNumStudents:" << mNumStudents << endl;
	cout << "Average:" << mAverageScore << endl;
	cout << "Standard Deviation:" << mStandardDeviation << endl;
	cout << "Score Range:" << mSortedScore[0] << " " << mSortedScore[mNumStudents - 1] << endl;
}

void STUDENT_RECORD_MANAGER::generateRandomSamples()
{
	mNumStudents =20;//20
	mScore.clear();
	for (int i = 0; i < mNumStudents; ++i) {
		//int a = rand() % 10 + 1;
		int a = rand() % 100 + 1;
		mScore.push_back(a);
	}
	
	sortScores();
	showSortedScores();

	computeAverage();
	computeStandardDeviation();
	cout << "mNumStudents:" << mNumStudents << endl;
	cout << "Average:" << mAverageScore << endl;
	cout << "Standard Deviation:" << mStandardDeviation << endl;
	cout << "Score Range:" << mSortedScore[0] << " " << mSortedScore[mNumStudents-1] << endl;
}

double STUDENT_RECORD_MANAGER::computeAverage( )
{
	//Compute the average
	int totalScore = 0.0;
	for ( int i = 0; i < mNumStudents; ++i ) {
		totalScore += mScore[i];
	}
	mAverageScore = (double)totalScore/mNumStudents;	// integer division?
	return mAverageScore;
}

double STUDENT_RECORD_MANAGER::computeStandardDeviation( )
{
	//Compute the standard deviation==>s=sqrt( (sum of xi-xbar)^2/(n-1) )

	double sum = 0.0;
	for ( int i = 0; i < mNumStudents; ++i ) {
		double b = mScore[i]-mAverageScore;
		sum += b*b;
	}

	mStandardDeviation = sqrt( sum/(mNumStudents-1) );
	return mStandardDeviation;
}

void STUDENT_RECORD_MANAGER::sortScores( )
{
	//Sorting in an ascending order
	for (int i = 0; i < mNumStudents; ++i) {
		mSortedScore = mScore;
	}
	for ( int i = 0; i < mNumStudents - 1; ++i ) {
		for ( int j = i + 1; j < mNumStudents; ++j ) {
			//int a = mSortedScore[ i ];
			if ( mSortedScore[i] > mSortedScore[ j ] ) {
				int tmp = mSortedScore[j];
				mSortedScore[j] = mSortedScore[i];
				mSortedScore[i] = tmp;
			}
		}
	}

}

void STUDENT_RECORD_MANAGER::showSortedScores( ) const
{
	//Show the scores in an ascending order

	cout << "Sorted scores:" << endl;
	for ( int i = 0; i < mNumStudents; ++i ) {
		cout << mSortedScore[ i ] << endl;
	}
}

int STUDENT_RECORD_MANAGER::getNumOfStudentsInScoreInterval(int s0, int s1) const
{
	//
	//Return the number of students whose score is inside the interval [s0, s1]. 
	//s0 and s1 are included.
	// 
	int num = 0;
	for ( int i = 0; i < mNumStudents; ++i ) {
		// Check if mScore[ i ] in [s0, s1]
		if( s0<=mScore[i] && mScore[i]<=s1 ) {
			++num;
		}
	}
	return num;
}

// CODE: 2019/02/25. Do not delete this line.
// CODE: 2022/03/24. Do not delete this line.