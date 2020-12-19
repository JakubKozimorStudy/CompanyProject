
#include "AddUser.h"
#include "EditUser.h"
#include "AddRole.h"
#include "ChangeRole.h"
#include "Stats.h"
#include <mysql.h>
#include <iostream>
#include "DatabaseRepository.h"
#include <algorithm>
#include <list>
#include "Role.h"
#include "AddRole.h"

#pragma once
namespace ProjectC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			repo->~DatabaseRepository();
			if (components)
			{
				
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;



	private: System::Windows::Forms::Button^ button6;



	protected:

	private: DatabaseRepository* repo = new DatabaseRepository();
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Imie;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nazwisko;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Zarobki;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Rola;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Data_rozpoczecia;





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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Imie = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nazwisko = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Zarobki = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Rola = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Data_rozpoczecia = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(257, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Pracownicy";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(653, 40);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Dodaj pracownika";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(653, 175);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(119, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Dodaj stanowisko";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(653, 120);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(119, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Usuń pracownika";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(653, 80);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(119, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Edytuj pracownika";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(653, 274);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(119, 23);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Statystyki";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Id, this->Imie,
					this->Nazwisko, this->Zarobki, this->Rola, this->Data_rozpoczecia
			});
			this->dataGridView1->Location = System::Drawing::Point(2, 100);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(645, 197);
			this->dataGridView1->TabIndex = 12;
			// 
			// Id
			// 
			this->Id->HeaderText = L"Id";
			this->Id->Name = L"Id";
			// 
			// Imie
			// 
			this->Imie->HeaderText = L"Imie";
			this->Imie->Name = L"Imie";
			// 
			// Nazwisko
			// 
			this->Nazwisko->HeaderText = L"Nazwisko";
			this->Nazwisko->Name = L"Nazwisko";
			// 
			// Zarobki
			// 
			this->Zarobki->HeaderText = L"Zarobki";
			this->Zarobki->Name = L"Zarobki";
			// 
			// Rola
			// 
			this->Rola->HeaderText = L"Rola";
			this->Rola->Name = L"Rola";
			this->Rola->ReadOnly = true;
			this->Rola->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// Data_rozpoczecia
			// 
			this->Data_rozpoczecia->HeaderText = L"Data_rozpoczecia";
			this->Data_rozpoczecia->Name = L"Data_rozpoczecia";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 315);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Pracownicy";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();


			std::list<Employee> data = repo->getAllEmployees(repo->getConn());
			std::list<Employee>::iterator it;
			for (it = data.begin(); it != data.end(); ++it) {
				int s_id = it->getId();
				String^ s_first_name = msclr::interop::marshal_as<System::String^>(it->getFirstName());
				String^ s_last_name = msclr::interop::marshal_as<System::String^>(it->getLastName());
				String^ s_start_date = msclr::interop::marshal_as<System::String^>(it->getStartDate());
				int s_salary = it->getSalary();

				int roleID = it->getRole();
				String^ s_role = "";


				std::list<Role> data = repo->getAllRoles(repo->getConn());

				std::list<Role>::iterator it;
				for (it = data.begin(); it != data.end(); ++it) {
					int tempRoleId = it->getId();
					if (tempRoleId == roleID) {
						s_role = msclr::interop::marshal_as<System::String^>(it->getRoleName());
					}
				}

				dataGridView1->Rows->Add(s_id, s_first_name, s_last_name, s_salary, s_role, s_start_date);

			}

		}

#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		AddUser^ addUserForm = gcnew AddUser(this->dataGridView1);
		addUserForm->Show();
	}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	AddRole^ addRoleForm = gcnew AddRole;
	addRoleForm->Show();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	ChangeRole^ changeRoleForm = gcnew ChangeRole;
	changeRoleForm->Show();

}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	Stats^ statsForm = gcnew Stats;
	statsForm->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	
	int rowIndex = dataGridView1->CurrentCell->RowIndex;
	int userId = Convert::ToInt64(dataGridView1->Rows[rowIndex]->Cells[0]->Value);
	std::list<Employee> data = repo->getAllEmployees(repo->getConn());
	std::list<Employee>::iterator it;
	for (it = data.begin(); it != data.end(); ++it) {
		if (it->getId() == userId) {

	EditUser^ editUserForm = gcnew EditUser(Employee(userId, it->getFirstName(), it->getLastName(), it->getRole(), it->getSalary()), this->dataGridView1);
	editUserForm->Show();
		}
	}

}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {

}


private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	int rowIndex = dataGridView1->CurrentCell->RowIndex;
	int userId = Convert::ToInt32(dataGridView1->Rows[rowIndex]->Cells[0]->Value);

	repo->removeUser(repo->getConn(), userId);
		dataGridView1->Rows->RemoveAt(rowIndex);
	
}
};
}
