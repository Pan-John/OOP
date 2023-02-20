#ifndef INTEGER_H
#define INTEGER_H 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Integer
{
private:
	vector<int> num;  //store the number
	string number;
public:
	//constructor
	Integer() {};
	Integer(string number);	//default constructor

	//get number
	char getnum() {
		int a = num.back();
		num.pop_back();
		return a;
	};
	int getNumSize() { return num.size(); };

	//operation overload 
	Integer operator +(const Integer& b);
	Integer operator -(const Integer& b);

	//output overload
	// friend ostream& operator << (ostream& out, const Integer& i);
};
#endif