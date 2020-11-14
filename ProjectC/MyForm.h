#pragma once
#include "AddUser.h"
#include "EditUser.h"
#include "AddRole.h"
#include "ChangeRole.h"
#include "Stats.h"

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
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button6;
	protected:

	private:
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
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(77, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Pracownicy";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(409, 45);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Dodaj pracownika";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(409, 180);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(119, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Dodaj stanowisko";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(409, 125);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(119, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Usu� pracownika";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(409, 85);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(119, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Edytuj pracownika";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(409, 219);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(119, 23);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Zmie� stanowisko";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(282, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Sortuj";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(236, 40);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 7;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(409, 279);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(119, 23);
			this->button6->TabIndex = 8;
			this->button6->Text = L"Statystyki";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(538, 314);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Pracownicy";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	AddUser^ addUserForm = gcnew AddUser;
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
	EditUser^ editUserForm = gcnew EditUser;
	editUserForm->Show();
}
};
}