#include "role.h"
#include <string>
#include <iostream>
using namespace std;

Role::Role(string roleID, int roleLevel, int roleMoney, int roleHp): ID(roleID), level(roleLevel), money(roleMoney), hp(roleHp){

}
string Role::getID() {
	// TODO : refer to spec
	return ID;
}
void Role::printAllInfo() {
	// TODO : refer to spec
	cout << "ID is: " << ID << endl;
	cout << "Level is: " << level << endl;
	cout << "Money is: " << money << endl;
	cout << "Hp is: " << hp << endl;
}