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
	/// Summary for addUser
	/// </summary>
	public ref class addUsr : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter();
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;

	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::ComboBox^ comboBox4;

	public:
		String^ userRole;

		addUsr(String^ userRole)
		{
			InitializeComponent();
			this->userRole = userRole;

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~addUsr()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	public: bool isEditMode = false; // Add this property to the form
	public: int editingIndexNumber = -1; // To store the ID of the student being edited

	public:
		void LoadStudentData(int indexNumber) {
			try {
				sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
				sqlConn->Open();

				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "SELECT * FROM Students INNER JOIN Users ON Students.UserID = Users.UserID " +
					"WHERE Students.IndexNumber = @IndexNumber";
				sqlCmd->Parameters->AddWithValue("@IndexNumber", indexNumber);

				MySqlDataReader^ reader = sqlCmd->ExecuteReader();
				if (reader->Read()) {
					// Populate the form fields with student data
					textBox1->Text = reader["FirstName"]->ToString();
					textBox2->Text = reader["LastName"]->ToString();
					textBox3->Text = reader["Email"]->ToString();
					textBox5->Text = reader["PasswordHash"]->ToString(); // Replace with actual password logic
					dateTimePicker1->Value = DateTime::Parse(reader["DateOfBirth"]->ToString());
					comboBox1->Text = reader["Major"]->ToString();
					comboBox4->Text = reader["Status"]->ToString();

					// Load image into pictureBox
					if (!Convert::IsDBNull(reader["ProfilePicture"])) {
						array<Byte>^ pictureData = (array<Byte>^)reader["ProfilePicture"];
						MemoryStream^ ms = gcnew MemoryStream(pictureData);
						pictureBox1->Image = Image::FromStream(ms);
					}
				}
				reader->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error loading student data: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
			}
		}

		void LoadFacultyData(String^ email) {
			try {
				sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
				sqlConn->Open();

				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "SELECT * FROM Faculty INNER JOIN Users ON Faculty.UserID = Users.UserID " +
					"WHERE Users.Email = @Email";
				sqlCmd->Parameters->AddWithValue("@Email", email);

				MySqlDataReader^ reader = sqlCmd->ExecuteReader();
				if (reader->Read()) {
					// Populate the form fields with faculty data
					textBox1->Text = reader["FirstName"]->ToString();
					textBox2->Text = reader["LastName"]->ToString();
					textBox3->Text = reader["Email"]->ToString();
					textBox5->Text = reader["PasswordHash"]->ToString(); // Replace with actual password logic
					dateTimePicker2->Value = DateTime::Parse(reader["DateOfAppointment"]->ToString());
					comboBox2->Text = reader["Status"]->ToString();
					textBox4->Text = reader["Department"]->ToString();

					// Load image into pictureBox
					if (!Convert::IsDBNull(reader["ProfilePicture"])) {
						array<Byte>^ pictureData = (array<Byte>^)reader["ProfilePicture"];
						MemoryStream^ ms = gcnew MemoryStream(pictureData);
						pictureBox1->Image = Image::FromStream(ms);
					}
				}
				reader->Close();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error loading faculty data: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
			}
		}


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
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(52, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"First Name:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(52, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Last Name:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(52, 157);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Email:";
			this->label3->Click += gcnew System::EventHandler(this, &addUsr::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(52, 208);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(103, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Date of Birth:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(52, 470);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(82, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Password:";
			this->label5->Click += gcnew System::EventHandler(this, &addUsr::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(52, 506);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(141, 20);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Confirm Password:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(247, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(241, 26);
			this->textBox1->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(247, 98);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(241, 26);
			this->textBox2->TabIndex = 7;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(247, 154);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(241, 26);
			this->textBox3->TabIndex = 8;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(247, 464);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(241, 26);
			this->textBox5->TabIndex = 10;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(247, 503);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(241, 26);
			this->textBox6->TabIndex = 11;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(590, 25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(191, 152);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(638, 201);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(92, 35);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Upload";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &addUsr::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(247, 593);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(101, 31);
			this->button2->TabIndex = 14;
			this->button2->Text = L"Add";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &addUsr::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(457, 593);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(105, 31);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Cancel";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &addUsr::button3_Click);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(247, 203);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(190, 26);
			this->dateTimePicker1->TabIndex = 16;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(52, 262);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(52, 20);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Major:";
			this->label7->Click += gcnew System::EventHandler(this, &addUsr::label7_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Business Administration", L"Management Information Systems",
					L"Computer Science", L"Economics"
			});
			this->comboBox1->Location = System::Drawing::Point(247, 254);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(190, 28);
			this->comboBox1->TabIndex = 19;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &addUsr::comboBox1_SelectedIndexChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(52, 348);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(161, 20);
			this->label8->TabIndex = 20;
			this->label8->Text = L"Date of Appointment:";
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(247, 342);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(190, 26);
			this->dateTimePicker2->TabIndex = 21;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(52, 390);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(98, 20);
			this->label9->TabIndex = 22;
			this->label9->Text = L"Department:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(247, 384);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(241, 26);
			this->textBox4->TabIndex = 23;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(52, 307);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(115, 20);
			this->label10->TabIndex = 24;
			this->label10->Text = L"Faculty Status:";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Active", L"Inactive" });
			this->comboBox2->Location = System::Drawing::Point(247, 299);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(190, 28);
			this->comboBox2->TabIndex = 25;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(52, 432);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(109, 20);
			this->label11->TabIndex = 26;
			this->label11->Text = L"Admin Status:";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Super", L"Basic" });
			this->comboBox3->Location = System::Drawing::Point(247, 424);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(190, 28);
			this->comboBox3->TabIndex = 27;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(52, 545);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(121, 20);
			this->label12->TabIndex = 28;
			this->label12->Text = L"Student Status:";
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Active", L"Inactive", L"Graduated" });
			this->comboBox4->Location = System::Drawing::Point(247, 542);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(190, 28);
			this->comboBox4->TabIndex = 29;
			// 
			// addUsr
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(813, 645);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"addUsr";
			this->Text = L"addUsr";
			this->Load += gcnew System::EventHandler(this, &addUsr::addUsr_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addUsr_Load(System::Object^ sender, System::EventArgs^ e) {
		// Hide all role-specific fields initially
		label7->Visible = false; // Major
		comboBox1->Visible = false;
		label12->Visible = false; // Student Status
		comboBox4->Visible = false;

		label10->Visible = false; // Faculty Status
		comboBox2->Visible = false;
		label8->Visible = false; // Date of Appointment
		dateTimePicker2->Visible = false;
		label9->Visible = false; // Department
		textBox4->Visible = false;

		label11->Visible = false; // Admin Status
		comboBox3->Visible = false;

		// Display fields based on the userRole
		if (userRole == "Student") {
			label7->Visible = true; // Major
			comboBox1->Visible = true;
			label12->Visible = true; // Student Status
			comboBox4->Visible = true;
		}
		else if (userRole == "Faculty") {
			label10->Visible = true; // Faculty Status
			comboBox2->Visible = true;
			label8->Visible = true; // Date of Appointment
			dateTimePicker2->Visible = true;
			label9->Visible = true; // Department
			textBox4->Visible = true;
		}
		else if (userRole == "Admin") {
			label11->Visible = true; // Admin Status
			comboBox3->Visible = true;
		}
	}


	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ firstName = textBox1->Text;
		String^ lastName = textBox2->Text;
		String^ email = textBox3->Text;
		String^ dob = dateTimePicker1->Value.ToString("yyyy-MM-dd");
		String^ password = textBox5->Text;
		String^ confirmPassword = textBox6->Text;
		String^ major = comboBox1->Text;
		String^ studentStatus = comboBox4->Text;
		String^ facultyStatus = comboBox2->Text;
		String^ appointmentDate = dateTimePicker2->Value.ToString("yyyy-MM-dd");
		String^ department = textBox4->Text;
		String^ adminStatus = comboBox3->Text;
		array<Byte>^ pictureData = nullptr; // Placeholder for the picture data


		// Check if passwords match
		if (password != confirmPassword) {
			MessageBox::Show("Passwords do not match.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		try {
			// Ensure sqlConn is properly initialized and the connection string is valid
			sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";

			// Check if the connection is already open, if not, open it
			if (sqlConn->State != ConnectionState::Open) {
				sqlConn->Open();
				//MessageBox::Show("Database connection opened successfully.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

			// Explicitly associate the command with the connection
			sqlCmd->Connection = sqlConn;  // Make sure the command uses the open connection

			if (isEditMode) {
				if (userRole == "Student") {
					// Existing student update logic
				// Update existing student record
				sqlCmd->CommandText = "UPDATE Users INNER JOIN Students ON Users.UserID = Students.UserID " +
					"SET Users.FirstName = @FirstName, Users.LastName = @LastName, Users.Email = @Email, " +
					"Users.PasswordHash = @PasswordHash, Users.DateOfBirth = @DateOfBirth, " +
					"Students.Major = @Major, Students.Status = @Status, Users.ProfilePicture = @ProfilePicture " +
					"WHERE Students.IndexNumber = @IndexNumber";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@IndexNumber", editingIndexNumber);
				sqlCmd->Parameters->AddWithValue("@FirstName", firstName);
				sqlCmd->Parameters->AddWithValue("@LastName", lastName);
				sqlCmd->Parameters->AddWithValue("@Email", email);
				sqlCmd->Parameters->AddWithValue("@PasswordHash", password); // Password hashing should be applied
				sqlCmd->Parameters->AddWithValue("@DateOfBirth", dob);
				sqlCmd->Parameters->AddWithValue("@Major", major);
				sqlCmd->Parameters->AddWithValue("@Status", studentStatus);

				// Convert the image to a byte array if present
				if (pictureBox1->Image != nullptr) {
					MemoryStream^ ms = gcnew MemoryStream();
					pictureBox1->Image->Save(ms, pictureBox1->Image->RawFormat);
					pictureData = ms->ToArray();
				}
				if (pictureData != nullptr) {
					sqlCmd->Parameters->AddWithValue("@ProfilePicture", pictureData);
				}
				else {
					sqlCmd->Parameters->AddWithValue("@ProfilePicture", DBNull::Value);
				}

				sqlCmd->ExecuteNonQuery();
				MessageBox::Show("Student information updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();


			
				}
				else if (userRole == "Faculty") {
					// Update existing faculty record
					sqlCmd->CommandText = "UPDATE Users INNER JOIN Faculty ON Users.UserID = Faculty.UserID " +
						"SET Users.FirstName = @FirstName, Users.LastName = @LastName, Users.Email = @Email, " +
						"Users.PasswordHash = @PasswordHash, Users.ProfilePicture = @ProfilePicture, " +
						"Faculty.DateOfAppointment = @DateOfAppointment, Faculty.Department = @Department, Faculty.Status = @Status " +
						"WHERE Users.Email = @Email";
					sqlCmd->Parameters->Clear();
					sqlCmd->Parameters->AddWithValue("@Email", email);
					sqlCmd->Parameters->AddWithValue("@FirstName", firstName);
					sqlCmd->Parameters->AddWithValue("@LastName", lastName);
					sqlCmd->Parameters->AddWithValue("@PasswordHash", password); // Password hashing should be applied
					sqlCmd->Parameters->AddWithValue("@DateOfAppointment", appointmentDate);
					sqlCmd->Parameters->AddWithValue("@Department", department);
					sqlCmd->Parameters->AddWithValue("@Status", facultyStatus);

					// Convert the image to a byte array if present
					if (pictureBox1->Image != nullptr) {
						MemoryStream^ ms = gcnew MemoryStream();
						pictureBox1->Image->Save(ms, pictureBox1->Image->RawFormat);
						pictureData = ms->ToArray();
					}
					if (pictureData != nullptr) {
						sqlCmd->Parameters->AddWithValue("@ProfilePicture", pictureData);
					}
					else {
						sqlCmd->Parameters->AddWithValue("@ProfilePicture", DBNull::Value);
					}

					sqlCmd->ExecuteNonQuery();
					MessageBox::Show("Faculty information updated successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			else {
				// Ensure uniqueness of IndexNumber
				Random^ rand = gcnew Random();
				int indexNumber = 0;
				bool unique = false;

				while (!unique) {
					indexNumber = rand->Next(100000, 999999); // Generate a random 6-digit index number
					sqlCmd->CommandText = "SELECT COUNT(*) FROM Students WHERE IndexNumber = @IndexNumber";
					sqlCmd->Parameters->Clear();
					sqlCmd->Parameters->AddWithValue("@IndexNumber", indexNumber);

					int count = Convert::ToInt32(sqlCmd->ExecuteScalar());
					if (count == 0) {
						unique = true; // IndexNumber is unique
					}
				}

				// Convert the profile picture to a byte array (if provided)
				if (pictureBox1->Image != nullptr) {
					MemoryStream^ ms = gcnew MemoryStream();
					pictureBox1->Image->Save(ms, pictureBox1->Image->RawFormat);
					pictureData = ms->ToArray();
				}

				// Insert general user data into the Users table
				sqlCmd->CommandText = "INSERT INTO Users (FirstName, LastName, Email, PasswordHash, DateOfBirth, Role, ProfilePicture) " +
					"VALUES (@FirstName, @LastName, @Email, @PasswordHash, @DateOfBirth, @Role, @ProfilePicture)";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@FirstName", firstName);
				sqlCmd->Parameters->AddWithValue("@LastName", lastName);
				sqlCmd->Parameters->AddWithValue("@Email", email);
				sqlCmd->Parameters->AddWithValue("@PasswordHash", password); // Hash the password if necessary
				sqlCmd->Parameters->AddWithValue("@DateOfBirth", dob);
				sqlCmd->Parameters->AddWithValue("@Role", userRole);
				if (pictureData != nullptr) {
					sqlCmd->Parameters->AddWithValue("@ProfilePicture", pictureData);
				}
				else {
					sqlCmd->Parameters->AddWithValue("@ProfilePicture", DBNull::Value);
				}

				sqlCmd->ExecuteNonQuery();

				// Retrieve the UserID of the newly inserted user
				int userID = Convert::ToInt32(sqlCmd->LastInsertedId);

				// Insert role-specific data
				if (userRole == "Student") {
					sqlCmd->CommandText = "INSERT INTO Students (UserID, Major, EnrollmentDate, Status, IndexNumber) " +
						"VALUES (@UserID, @Major, CURRENT_DATE, @Status, @IndexNumber)";
					sqlCmd->Parameters->Clear();
					sqlCmd->Parameters->AddWithValue("@UserID", userID);
					sqlCmd->Parameters->AddWithValue("@Major", major);
					sqlCmd->Parameters->AddWithValue("@Status", studentStatus);
					sqlCmd->Parameters->AddWithValue("@IndexNumber", indexNumber);
				}
				else if (userRole == "Faculty") {
					sqlCmd->CommandText = "INSERT INTO Faculty (UserID, DateOfAppointment, Department, Status) " +
						"VALUES (@UserID, @DateOfAppointment, @Department, @Status)";
					sqlCmd->Parameters->Clear();
					sqlCmd->Parameters->AddWithValue("@UserID", userID);
					sqlCmd->Parameters->AddWithValue("@DateOfAppointment", appointmentDate);
					sqlCmd->Parameters->AddWithValue("@Department", department);
					sqlCmd->Parameters->AddWithValue("@Status", facultyStatus);
				}
				else if (userRole == "Admin") {
					sqlCmd->CommandText = "INSERT INTO Administrators (UserID, AccessLevel) " +
						"VALUES (@UserID, @AccessLevel)";
					sqlCmd->Parameters->Clear();
					sqlCmd->Parameters->AddWithValue("@UserID", userID);
					sqlCmd->Parameters->AddWithValue("@AccessLevel", adminStatus);
				}

				sqlCmd->ExecuteNonQuery();

				MessageBox::Show("User added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();
			}
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


private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->InitialDirectory = "c:\\";
		ofd->Filter = "PNG Files (*.png)|*.png|JPG Files (*.jpg)|*.jpg|All Files (*.*)|*.*";
		ofd->FilterIndex = 3;
		ofd->RestoreDirectory = true;

		if (ofd->ShowDialog() == Windows::Forms::DialogResult::OK) {
			if (File::Exists(ofd->FileName)) {
				if (ofd->FileName->EndsWith(".png") || ofd->FileName->EndsWith(".jpg") || ofd->FileName->EndsWith(".jpeg")) {
					pictureBox1->ImageLocation = ofd->FileName;
				}
				else {
					MessageBox::Show("Please select a valid image file.",
						"Invalid File", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			else {
				MessageBox::Show("The selected file does not exist.",
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("An error occurred while loading the image: " + ex->Message,
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	// Close the current form
	this->Close();
}
};
}


