#include "MyForm.h"
#include <mysql.h>
#include <iostream>


using namespace System;
using namespace System::Windows::Forms;
int qstate;

[STAThread]

void main() {
	/*
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);

	conn = mysql_real_connect(conn, "localhost", "root", "root", "testdb", 3306, NULL, 0);

	if (conn) {
		puts("Po³¹czono");

		std::string query = "SELECT * from test";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate) {
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res)) {
				printf("id: %s, Name: %s\n", row[0], row[1]);
			}
		}
		else {
			std::cout << "Nieudane zapytanie" << mysql_error(conn) << std::endl;
		}
	}
	else {
		puts("Nieudane polaczenie");
	}
	*/
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ProjectC::MyForm form;
	Application::Run(% form);
	
}