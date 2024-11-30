#pragma once

#include "mdiForm.h"

namespace FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace System::IO;

	/// <summary>
	/// Summary for Login_Form
	/// </summary>
	public ref class Login_Form : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter();

	public:
		MySqlDataReader^ sqlRd;
		Login_Form(MySqlConnection^ connection)
		{
			InitializeComponent();
			sqlConn = connection;
			//
			//TODO: Add the constructor code here
			//
		}
		void ValidateLogin(String^ email, String^ Password);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(260, 144);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(292, 26);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(158, 150);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Username:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(163, 210);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Password:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(260, 210);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(292, 26);
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(231, 313);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 40);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Login_Form::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(411, 313);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 40);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Login_Form::button2_Click);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(246, 265);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(218, 20);
			this->linkLabel1->TabIndex = 6;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Request For Password Reset";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Login_Form::linkLabel1_LinkClicked);
			// 
			// Login_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(691, 479);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Login_Form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login_Form";
			this->Load += gcnew System::EventHandler(this, &Login_Form::Login_Form_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ email = textBox1->Text;
	String^ password = textBox2->Text;

	try {
		// Prepare query
		sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password="";database=usrmdb";
		sqlConn->Open();

		sqlCmd->Connection = sqlConn;
		sqlCmd->CommandText = "SELECT PasswordHash FROM users WHERE email = @Email";
		sqlCmd->Parameters->AddWithValue("@Email", email);

		// Execute query
		sqlRd = sqlCmd->ExecuteReader();
		if (sqlRd->Read()) {
			String^ storedHash = sqlRd->GetString(0); // Fetch hashed password
			sqlRd->Close();

			if (storedHash == password) { // In production, compare hashes securely
				MessageBox::Show("Login Successful!");

				mdiForm^ mdi = gcnew mdiForm();
				mdi->Show();
				this->Hide();
			}
			else {
				MessageBox::Show("Invalid password.", "Login Error");
			}
		}
		else {
			MessageBox::Show("Email not found.", "Login Error");
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message, "Database Error");
	}
}

private: System::Void Login_Form_Load(System::Object^ sender, System::EventArgs^ e) {
	
	

}
private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
}
};;
};;


