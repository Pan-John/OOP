#pragma once
#ifndef STAFF_H
#include "role.h"
#include "magician.h"
#include <string>
using namespace std;

class Staff {
public:
	Staff(string staffName) :name(staffName), damage(10) {

	}
	bool equipable(Role* role) { //void--->bool
		// TODO : refer to spec
		return isMagician(role);
	}

private:
	string name;
	int damage;
	bool isMagician(Role* role) {
		// TODO : refer to spec
		Magician* mag = dynamic_cast<Magician*>(role);
		if (mag == NULL) {
			//cout << "error bad_cast" << endl;
			return false;
		}
		else {
			//cout << role->getID() << " can equip staff_flame." << endl;
			return true;
		}
	}
};
#endif
