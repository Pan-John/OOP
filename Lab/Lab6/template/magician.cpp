#include "magician.h"
Magician::Magician(string roleID, int roleLevel, int roleMoney, int roleHp) : Role(roleID, roleLevel, roleMoney, roleHp) {

}
void Magician::ShowRole() {
	cout << "Role " << getID() << " is Magician" << endl;
}