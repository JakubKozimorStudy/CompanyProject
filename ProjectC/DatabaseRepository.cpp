#include "DatabaseRepository.h"
#include <string>
#include <algorithm>
#include <list>
#include "Employee.h"
#include "Role.h"
#include <ctime>
#include <cstdlib>
#include <time.h>


DatabaseRepository::DatabaseRepository()
{
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "root", "admin", "employeedb", 3306, NULL, 0);
}


DatabaseRepository::~DatabaseRepository()
{

	mysql_close(conn);
}

std::list<Employee> DatabaseRepository::getAllEmployees(MYSQL* conn) {

	MYSQL_RES* res;
	MYSQL_ROW row;
	std::string query = "SELECT * FROM employee";
	const char* q = query.c_str();
	boolean qstate = mysql_query(conn, q);
	if (!qstate)
	{

		res = mysql_store_result(conn);
		std::list<Employee> empList = {};
		while (row = mysql_fetch_row(res))
		{
			std::string s_id(row[0]);
			int id = std::stoi(s_id);
			std::string firstName(row[1]);
			std::string lastName(row[2]);
			std::string s_role_id(row[3]);
			int role_id = std::stoi(s_role_id);
			std::string s_salary(row[4]);
			int salary = std::stoi(s_salary);
			std::string start_date(row[5]);
			Employee tempEmp = Employee(id, firstName, lastName, role_id, salary, start_date);

			empList.push_back(tempEmp);
			printf("ID: %s, First Name: %s, Last Name: %s, Role: %s, Salary: %s, StartDate: %s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
		}
		std::list<Employee>::iterator it;
		for (it = empList.begin(); it != empList.end(); ++it) {
			std::cout << it->getFirstName() << std::endl;
		}
		mysql_free_result(res);
		return empList;
	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
	}
	system("pause");
}


std::list<Employee> DatabaseRepository::getAllEmployeesBySort(MYSQL* conn, std::string sort) {

	MYSQL_RES* res;
	MYSQL_ROW row;
	std::string query;
	if (sort == "Pensja od najwiekszej") {
		query = "SELECT * FROM employee ORDER BY salary DESC";
	}
	if(sort == "Pensja od najmniejszej"){
		query = "SELECT * FROM employee ORDER BY salary";
	}

	if (sort == "D�ugosc pracy od najwiekszej") {
		query = "SELECT * FROM employee ORDER BY start_date DESC";
	}
	if (sort == "D�ugosc pracy od najmniejszej") {
		query = "SELECT * FROM employee ORDER BY start_date";
	}
	std::cout << query << std::endl;
	const char* q = query.c_str();
	boolean qstate = mysql_query(conn, q);
	if (!qstate)
	{

		res = mysql_store_result(conn);
		std::list<Employee> empList = {};
		while (row = mysql_fetch_row(res))
		{
			std::string s_id(row[0]);
			int id = std::stoi(s_id);
			std::string firstName(row[1]);
			std::string lastName(row[2]);
			std::string s_role_id(row[3]);
			int role_id = std::stoi(s_role_id);
			std::string s_salary(row[4]);
			int salary = std::stoi(s_salary);
			Employee tempEmp = Employee(id, firstName, lastName, role_id, salary);
			empList.push_back(tempEmp);
			printf("ID: %s, First Name: %s, Last Name: %s, Role: %s, Salary: %s\n", row[0], row[1], row[2], row[3], row[4]);
		}
		std::list<Employee>::iterator it;
		for (it = empList.begin(); it != empList.end(); ++it) {
			std::cout << it->getFirstName() << std::endl;
		}
		mysql_free_result(res);
		return empList;
	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
	}
	system("pause");
}

int DatabaseRepository::getLastRecordFromEmployees(MYSQL* conn) {
	MYSQL_RES* res;
	MYSQL_ROW row;
	std::string query = "SELECT * FROM employee ORDER BY ID DESC LIMIT 1";
	int id=-1;
	const char* q = query.c_str();
	boolean qstate = mysql_query(conn, q);
	if (!qstate)
	{

		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			std::string s_id(row[0]);
			id = std::stoi(s_id);
			return id;
		}
		return id;
	}
}

int DatabaseRepository::averageSaralry(MYSQL* conn) {
	MYSQL_RES* res;
	MYSQL_ROW row;
	std::string query = "SELECT AVG(salary) as srednie_zarobki FROM employee";
	int average = -1;
	const char* q = query.c_str();
	boolean qstate = mysql_query(conn, q);
	if (!qstate)
	{

		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			std::string s_id(row[0]);
			average = std::stoi(s_id);
			return average;
		}
		return average;
	}
}

int DatabaseRepository::countEmployee(MYSQL* conn, std::string sort) {
	MYSQL_RES* res;
	MYSQL_ROW row;
	std::string query = "SELECT COUNT(*) AS ilosc FROM employee WHERE role_id IN (SELECT id FROM emp_role WHERE role_name ='" +  sort + "');";
	std::cout << query << std::endl;
	int count = -1;
	const char* q = query.c_str();
	boolean qstate = mysql_query(conn, q);
	if (!qstate)
	{

		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			std::string s_id(row[0]);
			count = std::stoi(s_id);
			return count;
		}
		return count;
	}
}

void DatabaseRepository::saveEmployee(Employee newEmp, MYSQL* conn) {

	MYSQL_RES* res;
	MYSQL_ROW row;
	int lastId = getLastRecordFromEmployees(conn);
	std::cout << lastId << std::endl;

	 time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);

	std::string insert_query = "INSERT INTO employee (id, first_name, last_name, role_id, salary, start_date) VALUES (' " + std::to_string(lastId + 1) + "', '" + newEmp.getFirstName() + "', '"
		+ newEmp.getLastName() + "', '" + std::to_string(newEmp.getRole()) + "', '" + std::to_string(newEmp.getSalary()) + "',  + curdate()" + " )";
	std::cout << insert_query << std::endl;
	boolean qstate = mysql_query(conn, insert_query.c_str());
	if (qstate != 0)
	{
		std::cout << mysql_error(conn) << std::endl;
	}

}


void DatabaseRepository::updateEmployee(const int &id, Employee* newEmp, MYSQL* conn) {

	MYSQL_RES* res;
	MYSQL_ROW row;

	std::cout << id <<std::endl;

	std::string update_query = "UPDATE employee SET id = '" + std::to_string(id) + "', first_name = '" + newEmp -> getFirstName() + "', last_name = '" + newEmp ->getLastName() + "', role_id = '"
		+ std::to_string(newEmp -> getRole()) + "', salary = '" + std::to_string(newEmp -> getSalary()) +"' WHERE id =  '" + std::to_string(id) + "'";

	std::cout <<update_query << std::endl;
	boolean qstate = mysql_query(conn, update_query.c_str());
	if (qstate != 0)
	{
		std::cout << mysql_error(conn) << std::endl;
	}

}


void DatabaseRepository::removeUser(MYSQL* conn, int userId) {

	MYSQL_RES* res;
	MYSQL_ROW row;
	std::string remove_query = "DELETE FROM employee WHERE id =" + std::to_string(userId);
	std::cout << remove_query << std::endl;
	boolean qstate = mysql_query(conn, remove_query.c_str());
	if (qstate != 0)
	{
		std::cout << mysql_error(conn) << std::endl;
	}

}


 std::list<Role> DatabaseRepository::getAllRoles(MYSQL* conn) {
	 MYSQL_RES* res;
	 MYSQL_ROW row;
	 std::string query = "SELECT * FROM emp_role";
	 const char* q = query.c_str();
	 boolean qstate = mysql_query(conn, q);
	 if (!qstate)
	 {

		 res = mysql_store_result(conn);
		 std::list<Role> roleList = {};
		 while (row = mysql_fetch_row(res))
		 {
			 std::string s_id(row[0]);
			 int id = std::stoi(s_id);
			 std::string roleName(row[1]);
			 Role role = Role(id, roleName);
			 roleList.push_back(role);
			 
		 }
		 mysql_free_result(res);
		 return roleList;
	 }
	 else
	 {
		 std::cout << "Query failed: " << mysql_error(conn) << std::endl;
	 }
	 system("pause");
}

 int DatabaseRepository::getLastRecordFromRoles(MYSQL* conn) {
	 MYSQL_RES* res;
	 MYSQL_ROW row;
	 std::string query = "SELECT * FROM emp_role ORDER BY ID DESC LIMIT 1";
	 int id;
	 const char* q = query.c_str();
	 boolean qstate = mysql_query(conn, q);
	 if (!qstate)
	 {

		 res = mysql_store_result(conn);
		 while (row = mysql_fetch_row(res))
		 {
			 std::string s_id(row[0]);
			 id = std::stoi(s_id);
			 return id;
		 }
	 }
 }


 void DatabaseRepository::saveRole(Role newRole, MYSQL* conn) {

	 MYSQL_RES* res;
	 MYSQL_ROW row;
	 int lastId = getLastRecordFromRoles(conn);
	 std::cout << lastId << std::endl;
	 std::string insert_query = "INSERT INTO emp_role (id, role_name) VALUES (' " + std::to_string(lastId + 1) + "', '" + newRole.getRoleName() + "')";
	 boolean qstate = mysql_query(conn, insert_query.c_str());
	 if (qstate != 0)
	 {
		 std::cout << mysql_error(conn) << std::endl;
	 }

 }
