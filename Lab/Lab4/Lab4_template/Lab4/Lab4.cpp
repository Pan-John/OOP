#include <iostream>
#include "DateCalculator.h"
using namespace std;


int main() {
	DateCalculator calculator;
	calculator.readFile("input1.txt");
/*	ifstream input;
	char data[18];
	input.open("input1.txt");
	if (!input) {
		cout << "error!";
		system("pause");
		return 0;
	}
	while (!input.eof()) {
		input.getline(data, sizeof(data), '\n');
		cout << data << endl;
	}
*/
	//calculator.readFile("input2.txt");
	system("pause");
	return 0;
}