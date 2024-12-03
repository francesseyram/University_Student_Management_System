#pragma once


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
	/// Summary for Add_Course
	/// </summary>
	public ref class Add_Course : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter();
	public:
		Add_Course(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	public: bool isEditMode = false; // Add this property to the form
		  void LoadCourseData(int CourseID) {
			  try {
				  // Open database connection
				  sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
				  sqlConn->Open();

				  // Query to fetch course data
				  sqlCmd->Connection = sqlConn;
				  sqlCmd->CommandText = "SELECT CourseName, Credits, Description FROM Courses WHERE CourseID = @CourseID";
				  sqlCmd->Parameters->Clear();
				  sqlCmd->Parameters->AddWithValue("@CourseID", CourseID);

				  // Execute reader
				  MySqlDataReader^ reader = sqlCmd->ExecuteReader();
				  if (reader->Read()) {
					  // Prefill form fields
					  textBox1->Text = reader["CourseName"]->ToString();
					  textBox2->Text = reader["Credits"]->ToString();
					  textBox3->Text = reader["Description"]->ToString();
				  }
				  else {
					  MessageBox::Show("Course not found.",
						  "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				  }
				  reader->Close();
			  }
			  catch (Exception^ ex) {
				  MessageBox::Show("Error loading course data: " + ex->Message,
					  "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			  }
			  finally {
				  if (sqlConn->State == ConnectionState::Open) {
					  sqlConn->Close();
				  }
			  }
		  }



	public: int editingCourseID = -1;



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Add_Course()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(60, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Course Name:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(60, 111);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Credits:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(60, 177);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Description:";
			this->label3->Click += gcnew System::EventHandler(this, &Add_Course::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(60, 312);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(110, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Pre-requisites:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(247, 51);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(211, 26);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(247, 111);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(211, 26);
			this->textBox2->TabIndex = 5;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(247, 177);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(211, 26);
			this->textBox3->TabIndex = 6;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(247, 306);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(211, 26);
			this->textBox4->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(60, 237);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(94, 20);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Department";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Computer Science", L"Business Administration",
					L"Management Information Sytems", L"Economics"
			});
			this->comboBox1->Location = System::Drawing::Point(247, 229);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 28);
			this->comboBox1->TabIndex = 9;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(107, 390);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 36);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Add_Course::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(365, 390);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 36);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Add_Course::button2_Click);
			// 
			// Add_Course
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(729, 463);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Add_Course";
			this->Text = L"Add_Course";
			this->Load += gcnew System::EventHandler(this, &Add_Course::Add_Course_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Open database connection
			sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
			sqlConn->Open();

			// Retrieve inputs from the form
			String^ courseName = textBox1->Text->Trim();
			String^ credits = textBox2->Text->Trim();
			String^ description = textBox3->Text->Trim();
			String^ departmentName = comboBox1->SelectedItem != nullptr
				? comboBox1->SelectedItem->ToString()
				: nullptr;
			String^ prerequisites = textBox4->Text->Trim();

			// Validate mandatory fields
			if (String::IsNullOrWhiteSpace(courseName) || String::IsNullOrWhiteSpace(credits) || String::IsNullOrWhiteSpace(departmentName)) {
				MessageBox::Show("Please fill in all mandatory fields.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// Step 1: Retrieve the DepartmentID using the DepartmentName
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT DepartmentID FROM Departments WHERE DepartmentName = @DepartmentName";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@DepartmentName", departmentName);

			Object^ departmentIDObj = sqlCmd->ExecuteScalar();

			if (departmentIDObj == nullptr) {
				MessageBox::Show("The selected department does not exist.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			int departmentID = Convert::ToInt32(departmentIDObj);

			// Step 2: If we're in Edit mode, update the course; otherwise, insert a new course
			if (isEditMode) {
				// Ensure `editingCourseID` is valid
				if (editingCourseID == 0 || editingCourseID <= 0) {
					MessageBox::Show("Invalid or missing Course ID for editing.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				int courseIDInt = editingCourseID; // Dereference the pointer to get the actual value

				// Validate the credits input
				int creditsInt;
				if (!int::TryParse(credits, creditsInt)) {
					MessageBox::Show("Invalid credits format. Please enter a valid number.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				// Ensure DepartmentID is valid
				if (departmentID <= 0) {
					MessageBox::Show("Invalid Department selected.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				// Update the course in the database
				sqlCmd->CommandText = "UPDATE Courses SET CourseName = @CourseName, Credits = @Credits, Description = @Description, DepartmentID = @DepartmentID WHERE CourseID = @CourseID";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@CourseName", courseName);
				sqlCmd->Parameters->AddWithValue("@Credits", creditsInt);
				sqlCmd->Parameters->AddWithValue("@Description", description);
				sqlCmd->Parameters->AddWithValue("@DepartmentID", departmentID);
				sqlCmd->Parameters->AddWithValue("@CourseID", courseIDInt);

				sqlCmd->ExecuteNonQuery();
				MessageBox::Show("Course updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				// Step 2: Insert the course into the Courses table
				sqlCmd->CommandText = "INSERT INTO Courses (CourseName, Credits, Description, DepartmentID) VALUES (@CourseName, @Credits, @Description, @DepartmentID)";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@CourseName", courseName);
				sqlCmd->Parameters->AddWithValue("@Credits", Convert::ToInt32(credits));
				sqlCmd->Parameters->AddWithValue("@Description", description);
				sqlCmd->Parameters->AddWithValue("@DepartmentID", departmentID);

				sqlCmd->ExecuteNonQuery();

				// Retrieve the new CourseID after insertion
				sqlCmd->CommandText = "SELECT LAST_INSERT_ID()";
				int newCourseID = Convert::ToInt32(sqlCmd->ExecuteScalar());

				// Step 3: Handle prerequisites
				if (!String::IsNullOrWhiteSpace(prerequisites)) {
					array<String^>^ prereqList = prerequisites->Split(',');

					for each (String ^ prereq in prereqList) {
						prereq = prereq->Trim();

						// Check if the prerequisite course exists
						sqlCmd->CommandText = "SELECT CourseID FROM Courses WHERE CourseName = @PrereqName";
						sqlCmd->Parameters->Clear();
						sqlCmd->Parameters->AddWithValue("@PrereqName", prereq);

						Object^ prereqCourseIDObj = sqlCmd->ExecuteScalar();

						if (prereqCourseIDObj != nullptr) {
							int prereqCourseID = Convert::ToInt32(prereqCourseIDObj);

							// Insert prerequisite relationship
							sqlCmd->CommandText = "INSERT INTO CoursePrerequisites (CourseID, PrerequisiteCourseID) VALUES (@CourseID, @PrereqCourseID)";
							sqlCmd->Parameters->Clear();
							sqlCmd->Parameters->AddWithValue("@CourseID", newCourseID);
							sqlCmd->Parameters->AddWithValue("@PrereqCourseID", prereqCourseID);

							sqlCmd->ExecuteNonQuery();
						}
						else {
							MessageBox::Show("Prerequisite course '" + prereq + "' not found. Skipping.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						}
					}
				}

				// Display success message for adding course
				MessageBox::Show("Course added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

			// Step 4: Reset the form after success
			textBox1->Clear();
			textBox2->Clear();
			textBox3->Clear();
			comboBox1->SelectedIndex = -1;
			textBox4->Clear();
			this->Close();
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

private: System::Void Add_Course_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
