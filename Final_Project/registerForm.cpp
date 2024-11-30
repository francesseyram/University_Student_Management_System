#include "registerForm.h"

using namespace System;
using namespace System::Windows::Forms;

void FinalProject::registerForm::RegisterUser(String^ email, String^ password, String^ firstName, String^ lastName) {
    try {
        MySqlCommand^ sqlCmd = gcnew MySqlCommand();
        sqlCmd->Connection = sqlConn;
        sqlCmd->CommandText = "INSERT INTO Users (email, password, firstName, lastName) VALUES (@Email, @Password, @FirstName, @LastName)";
        sqlCmd->Parameters->AddWithValue("@Email", email);
        sqlCmd->Parameters->AddWithValue("@Password", password);
        sqlCmd->Parameters->AddWithValue("@FirstName", firstName);
        sqlCmd->Parameters->AddWithValue("@LastName", lastName);

        sqlCmd->ExecuteNonQuery();
        MessageBox::Show("Registration Successful!");
        this->Close();  // Close the Register form
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message, "Database Error");
    }
}
