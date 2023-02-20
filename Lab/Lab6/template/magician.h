#pragma once
#ifndef MAGICIAN_H
#include "role.h"
#include <string>
#include <iostream>
using namespace std;

class Magician : public Role {
public:
	Magician(string roleID, int roleLevel, int roleMoney, int roleHp);

	void ShowRole();

};
#endif