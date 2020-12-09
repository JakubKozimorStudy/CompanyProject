#include<iostream>
#include <stdlib.h>
#include <mysql.h>
#include "Employee.h"
#include <string>
#include <algorithm>
#include <list>
#include "Role.h"
#pragma once
class DatabaseRepository
{
private:
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;

public:
	DatabaseRepository();
	~DatabaseRepository();
	std::list<Employee> getAllEmployees(MYSQL* conn);
	int getLastRecordFromEmployees(MYSQL* conn);
	void saveEmployee(Employee emp, MYSQL* conn);
	std::list<Role> getAllRoles(MYSQL* conn);
	int getLastRecordFromRoles(MYSQL* conn);
	void saveRole(Role newRole, MYSQL* conn);
	MYSQL* getConn() {
		return this->conn;
	}
};

