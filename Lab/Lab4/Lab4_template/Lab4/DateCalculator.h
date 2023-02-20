#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class DateCalculator {
private:
	int year;
	int month;
	int day;
	int changeDays;
	//You can add any variable if you need.
public:
	DateCalculator();
	void readFile(const char *filename);
	void add();
	void minus();
	int isLeapYear(int year_);
	void showDay();
	//You can add any function if you need.
};