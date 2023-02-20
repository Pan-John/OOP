#pragma once
#ifndef WARRIOR_H
#include "role.h"
#include <string>
#include <iostream>
using namespace std;

class Warrior : public Role {
public:
	Warrior(string roleID, int roleLevel, int roleMoney, int roleHp);
	
	void ShowRole();
		
};
#endif