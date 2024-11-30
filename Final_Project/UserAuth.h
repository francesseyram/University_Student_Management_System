#pragma once
// UserAuth.h
#pragma once
#include <mysql.h>
#include <string>
#include <vcclr.h>

namespace UniversitySystem {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Security::Cryptography;
    using namespace System::Text;

    public ref class UserAuth {
    private:
        MySqlConnection^ sqlConn;

        // Helper method to hash passwords
        String^ HashPassword(String^ password) {
            array<Byte>^ bytes = Encoding::UTF8->GetBytes(password);
            SHA256Managed^ sha256 = gcnew SHA256Managed();
            array<Byte>^ hash = sha256->ComputeHash(bytes);
            return BitConverter::ToString(hash)->Replace("-", "")->ToLower();
        }

    public:
        UserAuth() {
            sqlConn = gcnew MySqlConnection("datasource=localhost; port=3306; username=root; password=''; database=ashesi");
        }

        bool RegisterUser(String^ firstName, String^ lastName, String^ email, String^ password, String^ role, String^ dateOfBirth) {
            try {
                if (!sqlConn->State == ConnectionState::Open) {
                    sqlConn->Open();
                }

                // Check if email already exists
                MySqlCommand^ checkEmail = gcnew MySqlCommand("SELECT COUNT(*) FROM Users WHERE Email = @email", sqlConn);
                checkEmail->Parameters->AddWithValue("@email", email);
                int emailCount = Convert::ToInt32(checkEmail->ExecuteScalar());

                if (emailCount > 0) {
                    MessageBox::Show("Email already registered!");
                    return false;
                }

                // Insert new user
                String^ hashedPassword = HashPassword(password);
                MySqlCommand^ insertCmd = gcnew MySqlCommand("INSERT INTO Users (FirstName, LastName, Email, PasswordHash, Role, DateOfBirth) VALUES (@firstName, @lastName, @email, @password, @role, @dob)", sqlConn);

                insertCmd->Parameters->AddWithValue("@firstName", firstName);
                insertCmd->Parameters->AddWithValue("@lastName", lastName);
                insertCmd->Parameters->AddWithValue("@email", email);
                insertCmd->Parameters->AddWithValue("@password", hashedPassword);
                insertCmd->Parameters->AddWithValue("@role", role);
                insertCmd->Parameters->AddWithValue("@dob", dateOfBirth);

                insertCmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                MessageBox::Show("Registration Error: " + ex->Message);
                return false;
            }
            finally {
                sqlConn->Close();
            }
        }

        int LoginUser(String^ email, String^ password) {
            try {
                if (!sqlConn->State == ConnectionState::Open) {
                    sqlConn->Open();
                }

                String^ hashedPassword = HashPassword(password);
                MySqlCommand^ loginCmd = gcnew MySqlCommand("SELECT UserID, Role FROM Users WHERE Email = @email AND PasswordHash = @password", sqlConn);

                loginCmd->Parameters->AddWithValue("@email", email);
                loginCmd->Parameters->AddWithValue("@password", hashedPassword);

                MySqlDataReader^ reader = loginCmd->ExecuteReader();

                if (reader->Read()) {
                    int userID = reader->GetInt32(0);
                    String^ role = reader->GetString(1);

                    // Update last login time
                    reader->Close();
                    MySqlCommand^ updateLogin = gcnew MySqlCommand("UPDATE Users SET LastLogin = CURRENT_TIMESTAMP WHERE UserID = @userID", sqlConn);
                    updateLogin->Parameters->AddWithValue("@userID", userID);
                    updateLogin->ExecuteNonQuery();

                    return userID;
                }
                return -1; // Login failed
            }
            catch (Exception^ ex) {
                MessageBox::Show("Login Error: " + ex->Message);
                return -1;
            }
            finally {
                sqlConn->Close();
            }
        }
    };
}

// Registration Form Implementation
public ref class RegisterForm : public System::Windows::Forms::Form {
private:
    TextBox^ txtFirstName;
    TextBox^ txtLastName;
    TextBox^ txtEmail;
    TextBox^ txtPassword;
    ComboBox^ cmbRole;
    DateTimePicker^ dtpDateOfBirth;
    Button^ btnRegister;
    UserAuth^ auth;

public:
    RegisterForm() {
        InitializeComponent();
        auth = gcnew UserAuth();
    }

protected:
    void InitializeComponent() {
        // Initialize your form controls here
        // Add appropriate sizing and positioning
        txtFirstName = gcnew TextBox();
        txtLastName = gcnew TextBox();
        txtEmail = gcnew TextBox();
        txtPassword = gcnew TextBox();
        cmbRole = gcnew ComboBox();
        dtpDateOfBirth = gcnew DateTimePicker();
        btnRegister = gcnew Button();

        // Set up the role combo box
        cmbRole->Items->AddRange(gcnew array<String^> { "Student", "Faculty", "Admin" });

        // Add event handler for register button
        btnRegister->Click += gcnew EventHandler(this, &RegisterForm::btnRegister_Click);
    }

    void btnRegister_Click(Object^ sender, EventArgs^ e) {
        if (auth->RegisterUser(
            txtFirstName->Text,
            txtLastName->Text,
            txtEmail->Text,
            txtPassword->Text,
            cmbRole->SelectedItem->ToString(),
            dtpDateOfBirth->Value.ToString("yyyy-MM-dd")))
        {
            MessageBox::Show("Registration successful!");
            this->Close();
        }
    }
};

// Login Form Implementation
public ref class LoginForm : public System::Windows::Forms::Form {
private:
    TextBox^ txtEmail;
    TextBox^ txtPassword;
    Button^ btnLogin;
    Button^ btnRegister;
    UserAuth^ auth;

public:
    LoginForm() {
        InitializeComponent();
        auth = gcnew UserAuth();
    }

protected:
    void InitializeComponent() {
        // Initialize your form controls here
        txtEmail = gcnew TextBox();
        txtPassword = gcnew TextBox();
        btnLogin = gcnew Button();
        btnRegister = gcnew Button();

        // Set password character
        txtPassword->PasswordChar = '*';

        // Add event handlers
        btnLogin->Click += gcnew EventHandler(this, &LoginForm::btnLogin_Click);
        btnRegister->Click += gcnew EventHandler(this, &LoginForm::btnRegister_Click);
    }

    void btnLogin_Click(Object^ sender, EventArgs^ e) {
        int userID = auth->LoginUser(txtEmail->Text, txtPassword->Text);
        if (userID != -1) {
            MessageBox::Show("Login successful!");
            // Store the userID for the session
            // Open your MDI form here
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->Close();
        }
        else {
            MessageBox::Show("Invalid email or password!");
        }
    }

    void btnRegister_Click(Object^ sender, EventArgs^ e) {
        RegisterForm^ registerForm = gcnew RegisterForm();
        registerForm->ShowDialog();
    }
};