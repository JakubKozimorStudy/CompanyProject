#include "Role.h"

Role::Role(int newId, std::string newRoleName) {
	setRole(newId, newRoleName);
}

Role::Role(std::string newRoleName) {
	setRole(newRoleName);
}

void Role::setRole(int newId, std::string newRoleName) {
	id = newId;
	roleName = newRoleName;
}

void Role::setRole(std::string newRoleName) {
	roleName = newRoleName;
}

Role::~Role(){
}