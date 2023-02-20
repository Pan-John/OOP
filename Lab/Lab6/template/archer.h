#pragma once
#ifndef ARCHER_H
#include "role.h"
#include <string>
#include <iostream>
using namespace std;

class Archer : public Role {
public:
	Archer(string roleID, int roleLevel, int roleMoney, int roleHp);

	void ShowRole();

};
#endif