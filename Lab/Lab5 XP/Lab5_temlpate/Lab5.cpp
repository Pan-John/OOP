#include <iostream>
#include <fstream>
#include "Integer.h"
#include <istream>
#include <string>
#include <sstream>

using namespace std;

//read the data from the file
void readFile(const char* fileName);


int main()
{
	readFile("input1.txt");
	system("pause");
	return 0;
}

void readFile(const char* fileName) {

	//TODO: Read the input file here.
	//int lines = ...
	ifstream inputFile;
	inputFile.open(fileName);
	string line;
	getline(inputFile, line);
	size_t lines = stoi(line, nullptr, 10);

	for (size_t i = 0; i < lines; i++)
	{

		// Integer a, b, answer;
		getline(inputFile, line);
		stringstream ss;
		string stra, strb, oper;
		ss << line;
		ss >> stra;
		ss >> oper;
		ss >> strb;

		//cout << "stra: " << stra << ", strb: " << strb <<", oper " <<oper<< endl;

		//TODO: Implement your add or minus

		Integer a(stra);
		Integer b(strb);
		Integer answer;
		//answer = a + b;
		//answer = a - b;

		cout << i + 1 << endl;
		cout << "num1: " << stra << endl;
		cout << "num2: " << strb << endl;
		// ------------------------------------------
		if (oper == "+") {
			answer = a + b;
		}
		if (oper == "-") {
			answer = a - b;
		}
		// cout << answer;
		for (int i = 0; i < answer.getNumSize(); i++) {
			cout << hex << answer.getnum();
		}
		// ------------------------------------------
		// cout << "result: " << answer << endl << endl;

	}
	// if(oper == '+'){
	// 	answer == a + b;
	// }
	// if(oper == '-'){
	// 	answer == a - b;
	// }
	// cout << answer;
	inputFile.close();
}