#include "role.h"
#include "magician.h"
#include "warrior.h"
#include "archer.h"
#include "staff.h"
#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <sstream>
#include <vector>


int main() {
	
	// TODO : Read the file
	// 1. Read the input file to get the imformation
///*
	ifstream input;
	input.open("input2.txt");
	stringstream ss;
	string lines;
	int line;
	getline(input, lines);
	ss << lines;
	ss >> line;

	vector<string> name;
	vector<bool> tf;
	Staff* staff = new Staff("flame");

	for (size_t i = 0; i < line; i++) {
		string player, playerRole, Level, Money, Hp;
		getline(input, player, ',');
		getline(input, playerRole, ',');
		getline(input, Level, ',');
		getline(input, Money, ',');
		getline(input, Hp, '\n');
		
		if (playerRole == " Warrior") {
			Role* warrior = new Warrior(player, stoi(Level), stoi(Money), stoi(Hp));
			warrior->printAllInfo();
			warrior->ShowRole();
			cout << endl;
			name.push_back(player);
			tf.push_back(staff->equipable(warrior));
		}
		else if (playerRole == " Archer") {
			Role* archer = new Archer(player, stoi(Level), stoi(Money), stoi(Hp));
			archer->printAllInfo();
			archer->ShowRole();
			cout << endl;
			name.push_back(player);
			tf.push_back(staff->equipable(archer));

		}
		else {
			Role* magician = new Magician(player, stoi(Level), stoi(Money), stoi(Hp));
			magician->printAllInfo();
			magician->ShowRole();
			cout << endl;
			name.push_back(player);
			tf.push_back(staff->equipable(magician));
		}

	}

	cout << "Checking whether the role can equip a staff.." << endl;
	for (size_t i = 0; i < tf.size(); i++) {
		if (tf[i] == true) {
			cout<<name[i]<< " can equip staff_flame." << endl;
		}
		else {
			cout << "error bad_cast" << endl;
		}
	}

//*/
/*
	// TODO : Create the Role according to the input file
	// 1. Create the role
	// 2. Print this role's Infomation
	// 3. Show Role ( refer to spec )
	// Example :
	// -------------------------------------------------------
	Role* warrior = new Warrior("Steve", 1, 1987, 200);
	warrior->printAllInfo();
	warrior->ShowRole();
	cout << endl;
	// 
	Role* archer = new Archer("Legolas", 99, 99999, 6000);
	archer->printAllInfo();
	archer->ShowRole();
	cout << endl;
	// 
	Role* magician = new Magician("Rose", 30, 234, 668);
	magician->printAllInfo();
	magician->ShowRole();
	cout << endl;
	// -------------------------------------------------------
	// HINT : Not necessarily just three roles


	Staff* staff = new Staff("flame");
	cout << "Checking whether the role can equip a staff.." << endl;

	//
	// TODO : Check wheather all characters can get staff or not
	// Example :
	// -------------------------------------------------------
	staff->equipable(warrior);
	staff->equipable(archer);
	staff->equipable(magician);
	//staff->equipable(magician);

	// -------------------------------------------------------
	// HINT : Not necessarily just three roles
	cout << endl;

*/

	input.close();
	system("PAUSE");
	return 0;
}