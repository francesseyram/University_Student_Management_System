#pragma once
#include "addUsr.h"
namespace FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class facultyCourse : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter();

		String^ facultyEmail; // To track the logged-in faculty

	public:
		facultyCourse(String^ loggedInEmail)
		{
			facultyEmail = loggedInEmail; // Initialize the faculty email
			InitializeComponent();
		}

	protected:
		~facultyCourse()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;
		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Button^ approveButton;
		System::Windows::Forms::Button^ denyButton;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->approveButton = (gcnew System::Windows::Forms::Button());
			this->denyButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();

			// DataGridView
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(76, 121);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(700, 220);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;

			// Search TextBox
			this->textBox1->Location = System::Drawing::Point(170, 72);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(505, 26);
			this->textBox1->TabIndex = 3;
			//this->textBox1->TextChanged += gcnew System::EventHandler(this, &facultyCourse::textBox1_TextChanged);

			// Label
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(86, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Search:";

			// Approve Button
			this->approveButton->Location = System::Drawing::Point(122, 452);
			this->approveButton->Name = L"approveButton";
			this->approveButton->Size = System::Drawing::Size(159, 41);
			this->approveButton->TabIndex = 1;
			this->approveButton->Text = L"Approve";
			this->approveButton->UseVisualStyleBackColor = true;
			this->approveButton->Click += gcnew System::EventHandler(this, &facultyCourse::approveButton_Click);

			// Deny Button
			this->denyButton->Location = System::Drawing::Point(503, 452);
			this->denyButton->Name = L"denyButton";
			this->denyButton->Size = System::Drawing::Size(159, 41);
			this->denyButton->TabIndex = 0;
			this->denyButton->Text = L"Deny";
			this->denyButton->UseVisualStyleBackColor = true;
			this->denyButton->Click += gcnew System::EventHandler(this, &facultyCourse::denyButton_Click);

			// facultyCourse
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(855, 551);
			this->Controls->Add(this->denyButton);
			this->Controls->Add(this->approveButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"facultyCourse";
			this->Text = L"Approve Enrollments";
			this->Load += gcnew System::EventHandler(this, &facultyCourse::facultyCourse_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		// Helper to retrieve faculty ID from email
		int GetFacultyID() {
			try {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
				sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
				sqlConn->Open();

				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "SELECT f.FacultyID FROM Faculty f JOIN Users u ON f.UserID = u.UserID WHERE u.Email = @Email";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@Email", facultyEmail);

				Object^ facultyIDObj = sqlCmd->ExecuteScalar();
				return (facultyIDObj != nullptr) ? Convert::ToInt32(facultyIDObj) : -1;
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error retrieving faculty ID: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return -1;
			}
			finally {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
			}
		}
		//void textBox1_TextChanged(Object^ sender, EventArgs^ e) {
		//	LoadPendingEnrollments();
		//}


		// Load pending enrollments
		void LoadPendingEnrollments() {
			int facultyID = GetFacultyID();
			if (facultyID == -1) return;

			try {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
				sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
				sqlConn->Open();

				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText =
					"SELECT e.EnrollmentID, CONCAT(u.FirstName, ' ', u.LastName) AS StudentName, c.CourseName, " +
					"e.Status, e.EnrollmentDate " +
					"FROM Enrollments e " +
					"JOIN CourseOfferings co ON e.OfferingID = co.OfferingID " +
					"JOIN Courses c ON co.CourseID = c.CourseID " +
					"JOIN Students s ON e.StudentID = s.StudentID " +
					"JOIN Users u ON s.UserID = u.UserID " +
					"WHERE co.FacultyID = @FacultyID AND e.Status = 'Pending'";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@FacultyID", facultyID);

				MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter(sqlCmd);
				DataTable^ dt = gcnew DataTable();
				sqlDta->Fill(dt);

				dataGridView1->DataSource = dt;
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error loading pending enrollments: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
			}
		}

		// Approve Enrollment
		void approveButton_Click(Object^ sender, EventArgs^ e) {
			if (dataGridView1->SelectedRows->Count == 0) {
				MessageBox::Show("Please select a student enrollment to approve.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			int enrollmentID = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["EnrollmentID"]->Value);

			try {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
				sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
				sqlConn->Open();

				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "UPDATE Enrollments SET Status = 'Enrolled' WHERE EnrollmentID = @EnrollmentID";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@EnrollmentID", enrollmentID);

				sqlCmd->ExecuteNonQuery();

				MessageBox::Show("Enrollment approved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

				// Refresh the pending enrollments
				LoadPendingEnrollments();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error approving enrollment: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
			}
		}

		// Deny Enrollment
		void denyButton_Click(Object^ sender, EventArgs^ e) {
			if (dataGridView1->SelectedRows->Count == 0) {
				MessageBox::Show("Please select an enrollment to deny.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			int enrollmentID = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["EnrollmentID"]->Value);

			try {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
				sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
				sqlConn->Open();

				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "UPDATE Enrollments SET Status = 'Denied' WHERE EnrollmentID = @EnrollmentID";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@EnrollmentID", enrollmentID);

				sqlCmd->ExecuteNonQuery();

				MessageBox::Show("Enrollment denied successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

				// Refresh the pending enrollments
				LoadPendingEnrollments();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error denying enrollment: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
			}
		}

		// Load the form
	private: System::Void facultyCourse_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadPendingEnrollments();
	}
};

}