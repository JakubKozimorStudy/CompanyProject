#include<iostream>
#include<string.h>
#pragma once
class Role
{
private:
	int id;
	std::string roleName;


public:
	Role(int newId, std::string newRoleName);

	void setRole(int newId, std::string newRoleName);

	Role(std::string newRoleName);

	void setRole(std::string newRole);

	~Role();

	int getId() {
		return this->id;
	}

	std::string getRoleName() {
		return this->roleName;
	}

	void setId(int newId) {
		this->id = newId;
	}

	void setRoleName(std::string newRoleName) {
		this->roleName = newRoleName;
	}

};

