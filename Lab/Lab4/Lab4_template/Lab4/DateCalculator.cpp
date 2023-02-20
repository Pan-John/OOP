#include "DateCalculator.h"

using namespace std;

DateCalculator::DateCalculator():year(2000),month(1),day(1), changeDays(0){}

const int month_day[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31} };

void DateCalculator::readFile(const char *fileName) {
	//TODO:
	//Read the data from the txt file.
	//The file is in the Lab4_template/Lab4.
	// 
	//Hint: You can use get() to get a character in ifstream.
	//      You can use getline() to get one line in the txt file.
	//      You can use atoi() or stoi() to change variable type from string to int
	ifstream input;
	input.open(fileName);
	if (!input) {
		cout << "error! file isn't opened." << endl;
	}
	else {
		char data[20];
		char oper;
		while (!input.eof()) {
			input.getline(data, sizeof(data), '\n');
			oper = data[0];
			year = 1000 * data[2] + 100 * data[3] + 10 * data[4] + data[5] - 1111 * '0';
			month = 10 * data[7] + data[8] - 11 * '0';
			day = 10 * data[10] + data[11] - 11 * '0';
			if (strlen(data) == 14)
				changeDays = data[13] - '0';
			else if (strlen(data) == 15)
				changeDays = 10 * data[13] + data[14] - 11 * '0';
			else if (strlen(data) == 16)
				changeDays = 100 * data[13] + 10 * data[14] + data[15] - 111 * '0';
			else
				changeDays = 1000 * data[13] + 100 * data[14] + 10 * data[15] + data[16] - 1111 * '0';

			if (oper == '+')
				add();
			else
				minus();

			showDay();
			//cout << oper << " " << year << " " << month << " " << day << " " << changeDays << endl;
		}
		input.close();
	}
	
}

void DateCalculator::add() {
	//TODO:
	//Calculate the date add the changeDays.
	for (int i = 0; i <= month - 2; i++) {//change month to day. eg: 3/15 ==> 31(Jan) + 28(Feb) + 15 = 74
		day += month_day[isLeapYear(year)][i];
	}
	changeDays += day; //sum all the changedays so that we can count from XXXX/01/01
	while (changeDays > 365 + isLeapYear(year)) {//add
		changeDays -= (365 + isLeapYear(year));
		year++;
	}
	while (changeDays <= 0) {//minus
		year--;
		changeDays += (365 + isLeapYear(year));
	}

	month = 1;//year is certain here, adjust month
	while (changeDays - month_day[isLeapYear(year)][month - 1] > 0) {
		changeDays -= month_day[isLeapYear(year)][month - 1];
		month++;
	}
	day = changeDays;
}

void DateCalculator::minus() {
	//TODO:
	//Calculate the date minus the changeDays.
	changeDays *= (-1);
	add();
}

int DateCalculator::isLeapYear(int year_) {
	//TODO: 
	//Determine whether year_ is a leap year.
	if (year_ % 4 == 0 && year_ % 100 != 0)
		return 1;
	else if (year_ % 400 == 0)
		return 1;
	else
		return 0;
}

void DateCalculator::showDay() {
	//TODO: 
	//The function output the date on the screen.
	//Hint: You can use setw() to set the length of the number.
	//      You can use setfill('c') to fill 'c' to the empty space.
	//      Two functions of above is in iomanip header file.

	cout << year << "/" << setw(2) << setfill('0') << month << "/" << setw(2) << setfill('0') << day << endl;
}