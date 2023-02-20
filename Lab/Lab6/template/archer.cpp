#include "archer.h"
Archer::Archer(string roleID, int roleLevel, int roleMoney, int roleHp) : Role(roleID, roleLevel, roleMoney, roleHp) {

}
void Archer::ShowRole() {
	cout << "Role " << getID() << " is Archer" << endl;
}