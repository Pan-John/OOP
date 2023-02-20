#include <iostream>
#include <fstream>
#include "Integer.h"

using namespace std;

//read the data from the file
void readFile(const char* fileName);

int main()
{
	readFile("input1.txt");
	return 0;
}

void readFile(const char* fileName) {
	ifstream input;

	//TODO: Read the input file here.
	int lines;

	input.open(fileName);
	input >> lines;

	for (size_t i = 0; i < lines; i++)
	{
		Integer a, b, answer;

		//TODO: Implement your add or minus
		
		//answer = a + b;
		//answer = a - b;
		
		cout << i + 1 << endl;
		cout << "num1: " << a << endl;
		cout << "num2: " << b << endl;
		cout << "result: " << answer << endl << endl;
	}

	input.close();
}