#include "DatabaseRepository.h"
#include <string>
#include <algorithm>
#include <list>
#include "Employee.h"
#include "Role.h"


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


std::list<Employee> DatabaseRepository::getAllEmployeesBySort(MYSQL* conn, std::string sort) {

	MYSQL_RES* res;
	MYSQL_ROW row;
	std::string query = "SELECT * FROM employee";
	if (sort == "Pensja od najwi�kszej") {
		std::string query = "SELECT * FROM employee ORDER BY salary DESC";
	}
	else if(sort == "Pensja od najmniejszej"){
		std::string query = "SELECT * FROM employee ORDER BY salary";
	}

	// Podmieni� zarobki na date
	else if (sort == "D�ugosc pracy od najwi�kszej") {
		std::string query = "SELECT * FROM employee ORDER BY salary DESC";
	}
	else if (sort == "D�ugosc pracy od najmniejszej") {
		std::string query = "SELECT * FROM employee ORDER BY salary";
	}

	
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

void DatabaseRepository::saveEmployee(Employee newEmp, MYSQL* conn) {

	MYSQL_RES* res;
	MYSQL_ROW row;
	int lastId = getLastRecordFromEmployees(conn);
	std::cout << lastId << std::endl;
	std::string insert_query = "INSERT INTO employee (id, first_name, last_name, role_id, salary, start_date) VALUES (' " + std::to_string(lastId + 1) + "', '" + newEmp.getFirstName() + "', '"
		+ newEmp.getLastName() + "', '" + std::to_string(newEmp.getRole()) + "', '" + std::to_string(newEmp.getSalary()) + "', curdate()" + " )";
	std::cout << insert_query << std::endl;
	boolean qstate = mysql_query(conn, insert_query.c_str());
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