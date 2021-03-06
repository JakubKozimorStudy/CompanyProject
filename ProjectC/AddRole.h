#pragma once
#include "Role.h"
#include "DatabaseRepository.h"
#include "string.h"
#include <msclr\marshal_cppstd.h>


namespace ProjectC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddRole
	/// </summary>
	public ref class AddRole : public System::Windows::Forms::Form
	{
	public:
		AddRole(void)
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
		~AddRole()
		{
			repo -> ~DatabaseRepository();
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;

	private: DatabaseRepository* repo = new DatabaseRepository();
	private: System::Windows::Forms::Label^ label3;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(63, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(181, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Dodaj stanowisko";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(102, 63);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(106, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Nazwa stanowiska";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(102, 109);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Dodaj";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddRole::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(90, 86);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 4;
			// 
			// AddRole
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(302, 144);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"AddRole";
			this->Text = L"Dodaj stanowisko";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ newRoleName = textBox1->Text;
		if (String::IsNullOrEmpty(newRoleName)) {
			label3->Text = "Pole nie mo�e by� puste";
		}
		else {
			std::string s_roleName = msclr::interop::marshal_as<std::string>(newRoleName);
			Role newRole = Role(s_roleName);
			repo->saveRole(newRole, repo->getConn());
			textBox1->ResetText();
			label3->Text = "";
		}
	}
};
}
