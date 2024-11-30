#pragma once
#include "mdiForm.h";
#include "Login_Form.h"

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
	/// Summary for registerForm
	/// </summary>
	public ref class registerForm : public System::Windows::Forms::Form
	{ 
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
	public:
		registerForm(MySqlConnection^ connection)
		{
			InitializeComponent();
			sqlConn = connection;
			//
			//TODO: Add the constructor code here
			//
		}
		void RegisterUser(String^ email, String^ password, String^ firstName, String^ lastName);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~registerForm()
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
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;

	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Button^ Register;
	private: System::Windows::Forms::Button^ Cancel;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ upload_btn;




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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->Register = (gcnew System::Windows::Forms::Button());
			this->Cancel = (gcnew System::Windows::Forms::Button());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->upload_btn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(196, 53);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(284, 26);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(94, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"First Name: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(30, 99);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Last Name:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(38, 147);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Email";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(30, 263);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 20);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Password";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(25, 321);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(137, 20);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Confirm Password";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(25, 208);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(99, 20);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Date of Birth";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(196, 99);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(284, 26);
			this->textBox2->TabIndex = 7;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(196, 147);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(284, 26);
			this->textBox3->TabIndex = 8;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(196, 263);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(284, 26);
			this->textBox5->TabIndex = 10;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(196, 321);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(284, 26);
			this->textBox6->TabIndex = 11;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(196, 208);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 26);
			this->dateTimePicker1->TabIndex = 12;
			// 
			// Register
			// 
			this->Register->Location = System::Drawing::Point(196, 389);
			this->Register->Name = L"Register";
			this->Register->Size = System::Drawing::Size(107, 36);
			this->Register->TabIndex = 13;
			this->Register->Text = L"Register";
			this->Register->UseVisualStyleBackColor = true;
			this->Register->Click += gcnew System::EventHandler(this, &registerForm::Register_Click);
			// 
			// Cancel
			// 
			this->Cancel->Location = System::Drawing::Point(395, 389);
			this->Cancel->Name = L"Cancel";
			this->Cancel->Size = System::Drawing::Size(111, 36);
			this->Cancel->TabIndex = 14;
			this->Cancel->Text = L"Cancel";
			this->Cancel->UseVisualStyleBackColor = true;
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(235, 454);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(217, 20);
			this->linkLabel1->TabIndex = 15;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Have an account\? Login here";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &registerForm::linkLabel1_LinkClicked);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(566, 39);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(194, 134);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 16;
			this->pictureBox1->TabStop = false;
			// 
			// upload_btn
			// 
			this->upload_btn->Location = System::Drawing::Point(616, 188);
			this->upload_btn->Name = L"upload_btn";
			this->upload_btn->Size = System::Drawing::Size(88, 31);
			this->upload_btn->TabIndex = 17;
			this->upload_btn->Text = L"Upload";
			this->upload_btn->UseVisualStyleBackColor = true;
			// 
			// registerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(799, 531);
			this->Controls->Add(this->upload_btn);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->Cancel);
			this->Controls->Add(this->Register);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"registerForm";
			this->Text = L"registerForm";
			this->Load += gcnew System::EventHandler(this, &registerForm::registerForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
private: System::Void Register_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ firstName = textBox1->Text;
	String^ lastName = textBox2->Text;
	String^ email = textBox3->Text;
	String^ password = textBox5->Text;
	String^ confirmPassword = textBox6->Text;

	if (password != confirmPassword) {
		MessageBox::Show("Passwords do not match.", "Registration Error");
		return;
	}

	try {
		// Check if email exists
		MySqlCommand^ checkCmd = gcnew MySqlCommand("SELECT COUNT(*) FROM users WHERE email = @Email", sqlConn);
		checkCmd->Parameters->AddWithValue("@Email", email);

		int count = Convert::ToInt32(checkCmd->ExecuteScalar());
		if (count > 0) {
			MessageBox::Show("Email already registered. Please use a different email.", "Registration Error");
			return;
		}

		// Insert user
		MySqlCommand^ sqlCmd = gcnew MySqlCommand("INSERT INTO users (FirstName, LastName, Email, PasswordHash, DateOfBirth) VALUES (@FirstName, @LastName, @Email, @Password, @DOB)", sqlConn);
		sqlCmd->Parameters->AddWithValue("@FirstName", firstName);
		sqlCmd->Parameters->AddWithValue("@LastName", lastName);
		sqlCmd->Parameters->AddWithValue("@Email", email);
		sqlCmd->Parameters->AddWithValue("@Password", password); // Replace with hashed password
		sqlCmd->Parameters->AddWithValue("@DOB", dateTimePicker1->Value.Date);

		sqlCmd->ExecuteNonQuery();
		MessageBox::Show("Registration Successful!");
		this->Close();
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message, "Database Error");
	}
}

private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	/*Login_Form^ loginForm = gcnew Login_Form(sqlConn);
	loginForm->Show();*/
}
private: System::Void registerForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}

