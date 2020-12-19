#include "Employee.h"



Employee::Employee(int newId, std::string newFirstName, std::string newLastName, int newRole, int newSalary)
{
	setEmployee(newId, newFirstName, newLastName, newRole, newSalary);
}

void Employee::setEmployee(int newId, std::string newFirstName, std::string newLastName, int newRole, int newSalary) {
	id = newId;
	firstName = newFirstName;
	lastName = newLastName;
	role = newRole;
	salary = newSalary;
}

Employee::Employee(int newId, std::string newFirstName, std::string newLastName, int newRole, int newSalary, std::string new_start_date)
{
	setEmployee(newId, newFirstName, newLastName, newRole, newSalary, new_start_date);
}

void Employee::setEmployee(int newId, std::string newFirstName, std::string newLastName, int newRole, int newSalary, std::string new_start_date) {
	id = newId;
	firstName = newFirstName;
	lastName = newLastName;
	role = newRole;
	salary = newSalary;
	start_date = new_start_date;
}


Employee::Employee(std::string newFirstName, std::string newLastName, int newRole, int newSalary)
{
	setEmployee(newFirstName, newLastName, newRole, newSalary);
}

void Employee::setEmployee(std::string newFirstName, std::string newLastName, int newRole, int newSalary) {

	firstName = newFirstName;
	lastName = newLastName;
	role = newRole;
	salary = newSalary;
}




Employee::~Employee()
{
}



