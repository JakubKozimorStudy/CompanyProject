#include<iostream>
#include<string.h>
#pragma once
class Employee
{
private:
	int id;
	std::string firstName;
	std::string lastName;
	int role;
	int salary;

public:
	Employee(int newId, std::string newFirstName, std::string newLastName, int  newRole, int newSalary);

	void setEmployee(int newId, std::string newFirstName, std::string newLastName, int newRole, int newSalary);

	Employee(std::string newFirstName, std::string newLastName, int  newRole, int newSalary);

	void setEmployee(std::string newFirstName, std::string newLastName, int newRole, int newSalary);

	~Employee();

	int getId() {
		return this->id;
	}

	std::string getFirstName() {
		return this->firstName;
	}
	std::string getLastName() {
		return this->lastName;
	}
	int getSalary() {
		return this->salary;
	}

	int getRole() {
		return this->role;
	}

	void setId(int newId) {
		this->id = newId;
	}

	void setFirstName(std::string newFirstName) {
		this->firstName = newFirstName;
	}

};

