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
	std::string start_date;

public:
	Employee(int newId, std::string newFirstName, std::string newLastName, int  newRole, int newSalary);

	void setEmployee(int newId, std::string newFirstName, std::string newLastName, int newRole, int newSalary);

	Employee(int newId, std::string newFirstName, std::string newLastName, int  newRole, int newSalary, std::string start_date);

	void setEmployee(int newId, std::string newFirstName, std::string newLastName, int newRole, int newSalary, std::string start_Date);

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

	std::string getStartDate() {
		return this->start_date;
	}

	void setId(int newId) {
		this->id = newId;
	}

	void setFirstName(std::string newFirstName) {
		this->firstName = newFirstName;
	}


};

