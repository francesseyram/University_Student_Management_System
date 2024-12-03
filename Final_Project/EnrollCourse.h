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

	/// <summary>
	/// Summary for EnrollCourse
	/// </summary>
	public ref class EnrollCourse : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter();

	public:
		EnrollCourse(void)
		{
			InitializeComponent();
			LoadCourses(""); // Load all courses initially
		}
		String^ userEmail = "";
	protected:
		~EnrollCourse()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(76, 121);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(700, 220);
			this->dataGridView1->TabIndex = 4;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(170, 72);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(505, 26);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &EnrollCourse::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(86, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Search:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(122, 452);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(159, 41);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Enroll";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EnrollCourse::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(503, 452);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(159, 41);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// EnrollCourse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(855, 551);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"EnrollCourse";
			this->Text = L"Enroll in a Course";
			this->Load += gcnew System::EventHandler(this, &EnrollCourse::EnrollCourse_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Method to load courses into DataGridView
		void LoadCourses(String^ searchTerm) {
			try {
				sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
				sqlConn->Open();

				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "SELECT c.CourseID, c.CourseName, c.Credits, co.Semester, " +
					"CONCAT(u.FirstName, ' ', u.LastName) AS InstructorName, " +
					"co.MaxCapacity - co.CurrentEnrollment AS RemainingSlots " +
					"FROM CourseOfferings co " +
					"JOIN Courses c ON co.CourseID = c.CourseID " +
					"JOIN Faculty f ON co.FacultyID = f.FacultyID " +
					"JOIN Users u ON f.UserID = u.UserID " +
					"WHERE co.Status = 'Open' AND co.CurrentEnrollment < co.MaxCapacity " +
					(String::IsNullOrWhiteSpace(searchTerm) ? "" : "AND c.CourseName LIKE @SearchTerm");

				sqlCmd->Parameters->Clear();
				if (!String::IsNullOrWhiteSpace(searchTerm)) {
					sqlCmd->Parameters->AddWithValue("@SearchTerm", "%" + searchTerm + "%");
				}

				MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter(sqlCmd);
				DataTable^ dt = gcnew DataTable();
				sqlDta->Fill(dt);

				dataGridView1->DataSource = dt;
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error loading courses: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
			}
		}

		// Event handler for live search
		void textBox1_TextChanged(Object^ sender, EventArgs^ e) {
			LoadCourses(textBox1->Text);
		}

		// Event handler for enrollment
		void button1_Click(Object^ sender, EventArgs^ e) {
			try {
				int studentID = GetCurrentStudentID(userEmail); // Assuming `userEmail` is available


				// Check if a course is selected
				if (dataGridView1->SelectedRows->Count == 0) {
					MessageBox::Show("Please select a course to enroll in.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				// Retrieve selected CourseID from DataGridView
				int selectedCourseID = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells["CourseID"]->Value);

				// Query database to get OfferingID dynamically based on CourseID
				sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
				sqlConn->Open();
				sqlCmd->Connection = sqlConn;

				sqlCmd->CommandText = "SELECT OfferingID FROM CourseOfferings WHERE CourseID = @CourseID AND Status = 'Open' AND CurrentEnrollment < MaxCapacity";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@CourseID", selectedCourseID);

				Object^ offeringIDObj = sqlCmd->ExecuteScalar();

				if (offeringIDObj == nullptr) {
					MessageBox::Show("No available offering found for the selected course.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				int selectedOfferingID = Convert::ToInt32(offeringIDObj);

				// Retrieve current StudentID
				if (studentID == -1) {
					MessageBox::Show("Unable to retrieve student ID.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				// Check if the course has prerequisites and if the student has met them
				sqlCmd->CommandText = "SELECT PrerequisiteCourseID FROM Courses WHERE CourseID = @CourseID AND PrerequisiteCourseID IS NOT NULL";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@CourseID", selectedCourseID);

				Object^ prereqCourseIDObj = sqlCmd->ExecuteScalar();

				if (prereqCourseIDObj != nullptr) {
					int prereqCourseID = Convert::ToInt32(prereqCourseIDObj);

					// Check if the student has passed the prerequisite course
					sqlCmd->CommandText = "SELECT Grade FROM Enrollments WHERE StudentID = @StudentID AND CourseID = @PrerequisiteCourseID AND Grade IN ('A', 'B', 'C', 'D')";
					sqlCmd->Parameters->Clear();
					sqlCmd->Parameters->AddWithValue("@StudentID", studentID);
					sqlCmd->Parameters->AddWithValue("@PrerequisiteCourseID", prereqCourseID);

					Object^ gradeObj = sqlCmd->ExecuteScalar();

					if (gradeObj == nullptr) {
						MessageBox::Show("You must pass the prerequisite course before enrolling in this course.", "Prerequisite Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}
				}

				// Enroll the student in the selected course
				sqlCmd->CommandText = "INSERT INTO Enrollments (StudentID, OfferingID, EnrollmentDate, Status) VALUES (@StudentID, @OfferingID, CURRENT_TIMESTAMP, 'Enrolled')";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@StudentID", studentID);
				sqlCmd->Parameters->AddWithValue("@OfferingID", selectedOfferingID);

				sqlCmd->ExecuteNonQuery();

				// Update the CurrentEnrollment in the CourseOfferings table
				sqlCmd->CommandText = "UPDATE CourseOfferings SET CurrentEnrollment = CurrentEnrollment + 1 WHERE OfferingID = @OfferingID";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@OfferingID", selectedOfferingID);

				sqlCmd->ExecuteNonQuery();

				MessageBox::Show("Enrollment successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
			}

		}
			// Helper method to retrieve current logged-in student ID

		public: int GetCurrentStudentID(String^ userEmail) {
			try {
				sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
				sqlConn->Open();

				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "SELECT s.StudentID FROM Students s " +
					"JOIN Users u ON s.UserID = u.UserID " +
					"WHERE u.Email = @Email";

				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@Email", userEmail);

				Object^ studentIDObj = sqlCmd->ExecuteScalar();
				if (studentIDObj != nullptr) {
					return Convert::ToInt32(studentIDObj);
				}
				else {
					return -1; // Student ID not found for the given email
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error retrieving student ID: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return -1;
			}
			finally {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
			}
		}


		private: System::Void EnrollCourse_Load(System::Object^ sender, System::EventArgs^ e) {
		}
};
}
