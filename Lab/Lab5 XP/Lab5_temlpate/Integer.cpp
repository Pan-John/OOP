#include "Integer.h"

Integer::Integer(string number)
{
	//TODO: read the string and construct the huge integer
	this->number = number;
}

Integer Integer::operator +(const Integer& b) {
	//TODO: perform + opearion overloading
	string str1 = this->number;
	string str2 = b.number;
	num.push_back(0);
	for (int i = 0; i < max(str1.size(), str2.size()); i++) {
		string strA, strB;
		strA.assign(&str1[i]);
		strB.assign(&str2[i]);
		int sum = stoi(strA, nullptr, 16) + stoi(strB, nullptr, 16) + num.back();
		num.pop_back();
		num.push_back(sum % 16);
		num.push_back(sum / 16);
	}
}
Integer Integer::operator -(const Integer& b) {
	//TODO: perform - opearion overloading
	return b;
}

ostream& operator << (ostream& out, const Integer& i) {
	//TODO: perform output overloading
}

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------


