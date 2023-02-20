#include<iostream>
#include<fstream>
#include<string>
#include"QueueList.h"
#include"StackList.h"

using namespace std;

int main() {
	ifstream File;
	File.open("input2.txt");

	if (!File.is_open()) {
		cout << "Can't open txt file" << endl;
		system("pause");
		return 0;
	}

	int TestCase = 0;
	File >> TestCase;

	while (TestCase) {
		QueueList Q;
		StackList S;
		char type;
		File >> type;
		int num_op;
		switch (type) {
			case 'S':

				File >> num_op;
				for (int i = 0; i < num_op; i++) {
					string s;
					File >> s;
					if (s == "push") {
						int value;
						File >> value;
						S.push(value);
					}
					else if (s == "pop") {
						S.pop();
					}
					else if (s == "print") {
						S.print();
					}
				}
				break;
			case 'Q':
				File >> num_op;
				for (int i = 0; i < num_op; i++) {
					string s;
					File >> s;
					if (s == "en") {
						int value;
						File >> value;
						Q.enqueue(value);
					}
					else if (s == "de") {
						Q.dequeue();
					}
					else if (s == "print") {
						Q.print();
					}
				}
				break;
			default:
				break;
		}
			
		cout << endl;
		TestCase--;
	}

	system("pause");
	return 0;
}