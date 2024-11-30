#include "Login_Form.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

void FinalProject::Login_Form::ValidateLogin(String^ email, String^ password) {

    try {
        MySqlCommand^ sqlCmd = gcnew MySqlCommand();
        sqlCmd->Connection = sqlConn;
        sqlCmd->CommandText = "SELECT COUNT(*) FROM Users WHERE email = @Email AND password = @Password";
        sqlCmd->Parameters->AddWithValue("@Email", email);
        sqlCmd->Parameters->AddWithValue("@Password", password);

        int userCount = Convert::ToInt32(sqlCmd->ExecuteScalar());
        if (userCount > 0) {
            MessageBox::Show("Login Successful!");
            this->Close();  // Close the Login form and proceed
        }
        else {
            MessageBox::Show("Invalid email or password.", "Login Error");
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message, "Database Error");
    }
}
int main(array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    MySqlConnection^ sqlConn = gcnew MySqlConnection("Server=localhost;Database=usrmdb;Uid=root;Pwd='';");
    FinalProject::Login_Form loginForm(sqlConn);
    Application::Run(% loginForm);
}

