#pragma once
#include "Employee.h"
#include "Role.h"
#include "DatabaseRepository.h"
#include <msclr\marshal_cppstd.h>
#include "Role.h"
#include <algorithm>
#include <list>
#include <mysql.h>
#include <iostream>
#include <string>


namespace ProjectC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddUser
	/// </summary>
	public ref class AddUser : public System::Windows::Forms::Form
	{
	private: DataGridView^ gridView1;
	public:
		AddUser(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		AddUser(DataGridView^ dataGridView1)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->gridView1 = dataGridView1;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddUser()
		{repo->~DatabaseRepository();
			if (components)
			{
				
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labal1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;



	protected:

	protected:

	private: DatabaseRepository* repo = new DatabaseRepository();
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labal1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labal1
			// 
			this->labal1->AutoSize = true;
			this->labal1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->labal1->Location = System::Drawing::Point(47, 9);
			this->labal1->Name = L"labal1";
			this->labal1->Size = System::Drawing::Size(183, 25);
			this->labal1->TabIndex = 0;
			this->labal1->Text = L"Dodaj pracownika";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(79, 65);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(116, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Imie";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(104, 114);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Nazwisko";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(99, 179);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Stanowisko";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(79, 130);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 5;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(79, 195);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(100, 21);
			this->comboBox1->TabIndex = 6;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(79, 316);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Dodaj";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddUser::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(102, 246);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Zarobki (z³)";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(79, 262);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 9;
			
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(66, 88);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 13);
			this->label5->TabIndex = 10;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::Color::Red;
			this->label6->Location = System::Drawing::Point(66, 153);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 13);
			this->label6->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ForeColor = System::Drawing::Color::Red;
			this->label7->Location = System::Drawing::Point(66, 219);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 13);
			this->label7->TabIndex = 12;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->ForeColor = System::Drawing::Color::Red;
			this->label8->Location = System::Drawing::Point(66, 285);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 13);
			this->label8->TabIndex = 13;
			// 
			// AddUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(273, 389);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->labal1);
			this->Name = L"AddUser";
			this->Text = L"Dodaj pracownika";

			this->ResumeLayout(false);
			this->PerformLayout();

			std::list<Role> data = repo->getAllRoles(repo->getConn());

			std::list<Role>::iterator it;
			for (it = data.begin(); it != data.end(); ++it) {
				String^ s_name = msclr::interop::marshal_as<System::String^>(it->getRoleName());
				comboBox1->Items->Add(s_name);
			}


		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String ^ firstName = textBox1->Text;
	String ^ lastName = textBox2->Text;
	String ^ salary = textBox3->Text;
	String^ role = comboBox1->Text;

	if (String::IsNullOrEmpty(firstName) || String::IsNullOrEmpty(lastName) || String::IsNullOrEmpty(salary) || String::IsNullOrEmpty(role)) {

		if (String::IsNullOrEmpty(firstName)) {
			label5->Text = "Pole nie mo¿e byæ puste";
		}
		else {
			label5->Text = "";
		}

		if (String::IsNullOrEmpty(lastName)) {
			label6->Text = "Pole nie mo¿e byæ puste";
		}
		else {
			label6->Text = "";
		}

		if (String::IsNullOrEmpty(role)) {
			label7->Text = "Pole nie mo¿e byæ puste";
		}
		else {
			label7->Text = "";
		}

		if (String::IsNullOrEmpty(salary)) {
			label8->Text = "Pole nie mo¿e byæ puste";
		}
		else {
			label8->Text = "";
		}
	}
	else {
		int intSalary = System::Convert::ToInt16(salary);
		int roleID = 1;
		std::list<Role> data = repo->getAllRoles(repo->getConn());

		std::list<Role>::iterator it;
		for (it = data.begin(); it != data.end(); ++it) {
			String^ s_name = msclr::interop::marshal_as<System::String^>(it->getRoleName());
			if (s_name == role) {
				roleID = it->getId();
			}
		}

		Employee* emp = new Employee(msclr::interop::marshal_as<std::string>(firstName), msclr::interop::marshal_as<std::string>(lastName), roleID, intSalary);
		repo->saveEmployee(*emp, repo->getConn());
		textBox1->ResetText();
		textBox2->ResetText();
		textBox3->ResetText();
		comboBox1->ResetText();
		gridView1->Rows->Clear();
		std::list<Employee> data2 = repo->getAllEmployees(repo->getConn());
		std::list<Employee>::iterator it2;
		for (it2 = data2.begin(); it2 != data2.end(); ++it2) {
			int s_id = it2->getId();
			String^ s_first_name = msclr::interop::marshal_as<System::String^>(it2->getFirstName());
			String^ s_last_name = msclr::interop::marshal_as<System::String^>(it2->getLastName());
			String^ s_start_date = msclr::interop::marshal_as<System::String^>(it2->getStartDate());
			int s_salary = it2->getSalary();

			int roleID = it2->getRole();
			String^ s_role = "";


			std::list<Role> data = repo->getAllRoles(repo->getConn());

			std::list<Role>::iterator it;
			for (it = data.begin(); it != data.end(); ++it) {
				int tempRoleId = it->getId();
				if (tempRoleId == roleID) {
					s_role = msclr::interop::marshal_as<System::String^>(it->getRoleName());
				}
			}

			gridView1->Rows->Add(s_id, s_first_name, s_last_name, s_salary, s_role, s_start_date);

			label5->Text = "";
			label6->Text = "";
			label7->Text = "";
			label8->Text = "";
	}

	

	}




}	

};
}
