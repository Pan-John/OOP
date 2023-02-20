#include "warrior.h"
Warrior::Warrior(string roleID, int roleLevel, int roleMoney, int roleHp) : Role(roleID, roleLevel,roleMoney, roleHp){

}
void Warrior::ShowRole() {
	cout << "Role "<< getID() <<" is Warrior" << endl;
}
