CREATE DATABASE employeedb;
USE employeedb;

CREATE TABLE emp_role(id INT UNIQUE NOT NULL, role_name VARCHAR(32) NOT NULL, PRIMARY KEY (id));
INSERT INTO emp_role (id, role_name) VALUES (1, "EMPLOYEE");
INSERT INTO emp_role (id, role_name) VALUES (2, "MANAGER");
INSERT INTO emp_role (id, role_name) VALUES (3, "CEO");


CREATE TABLE employee (
id INT UNIQUE NOT NULL,
 first_name VARCHAR(32) NOT NULL,
 last_name VARCHAR(32) NOT NULL,
 role_id INT NOT NULL,
 salary INT NOT NULL,
 start_date TIMESTAMP NOT NULL,
 PRIMARY KEY(id),
 CONSTRAINT FK_employee_emp_role FOREIGN KEY (role_id) REFERENCES emp_role(id)
 );
 
INSERT INTO employee (id, first_name, last_name, role_id, salary, start_date) VALUES (1, "Jan", "Kowalski", 1, 3000, curdate());
INSERT INTO employee (id, first_name, last_name, role_id, salary, start_date) VALUES (2, "Janina", "Kowalska", 2, 8000, curdate());
INSERT INTO employee (id, first_name, last_name, role_id, salary, start_date) VALUES (3, "Adam", "Kowal", 3, 20000, curdate());



SELECT * FROM employee;


-- 			listBox1->Items->Add("Son");
-- 			std::list<Employee> data = repo->getAllEmployees(repo->getConn());
-- 			std::list<Employee>::iterator it;
-- 			for (it = data.begin(); it != data.end(); ++it) {
-- 				String^ name = msclr::interop::marshal_as<String^>(it->getFirstName());
-- 				listBox1->Items->Add(name);
-- 			}