#include "addUser.h"
#pragma once
using namespace System::Windows::Forms;


namespace FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for mdiForm
	/// </summary>
	public ref class mdiForm : public System::Windows::Forms::Form
	{
	private: System::String^ UserRole;

	public:
		mdiForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//


		}
		void SetUserRole(System::String^ role) {
			this->UserRole = role;  // Set role after login
			ConfigureUIBasedOnRole();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mdiForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ menuStrip2;




	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton3;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ logoutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ studentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ enrollInCourseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewGradesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewScheduleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ profileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ facultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageCoursesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ enterGradesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewRosterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ profileToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ administratorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageStudentsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageFacultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageCoursesToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ generateReportsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ manageFinancialsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton4;



	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton6;
	private: System::Windows::Forms::ToolStripMenuItem^ addStudentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ removeStudentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editStudentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addFacultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ removeFacultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editStudentToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ addCourseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ removeCourseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ editCourseToolStripMenuItem;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

	private:
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(mdiForm::typeid));
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->logoutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->studentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enrollInCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewScheduleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->profileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->facultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageCoursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enterGradesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewRosterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->profileToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administratorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageStudentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageFacultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageCoursesToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->generateReportsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageFinancialsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->addStudentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeStudentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addFacultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeFacultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editStudentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editStudentToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip2->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip2
			// 
			this->menuStrip2->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->studentToolStripMenuItem, this->facultyToolStripMenuItem, this->administratorToolStripMenuItem
			});
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(905, 33);
			this->menuStrip2->TabIndex = 3;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->logoutToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(54, 29);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// logoutToolStripMenuItem
			// 
			this->logoutToolStripMenuItem->Name = L"logoutToolStripMenuItem";
			this->logoutToolStripMenuItem->Size = System::Drawing::Size(171, 34);
			this->logoutToolStripMenuItem->Text = L"Logout";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(171, 34);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// studentToolStripMenuItem
			// 
			this->studentToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->enrollInCourseToolStripMenuItem,
					this->viewGradesToolStripMenuItem, this->viewScheduleToolStripMenuItem, this->profileToolStripMenuItem
			});
			this->studentToolStripMenuItem->Name = L"studentToolStripMenuItem";
			this->studentToolStripMenuItem->Size = System::Drawing::Size(89, 29);
			this->studentToolStripMenuItem->Text = L"Student";
			// 
			// enrollInCourseToolStripMenuItem
			// 
			this->enrollInCourseToolStripMenuItem->Name = L"enrollInCourseToolStripMenuItem";
			this->enrollInCourseToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->enrollInCourseToolStripMenuItem->Text = L"Enroll in Course";
			// 
			// viewGradesToolStripMenuItem
			// 
			this->viewGradesToolStripMenuItem->Name = L"viewGradesToolStripMenuItem";
			this->viewGradesToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->viewGradesToolStripMenuItem->Text = L"View Grades";
			// 
			// viewScheduleToolStripMenuItem
			// 
			this->viewScheduleToolStripMenuItem->Name = L"viewScheduleToolStripMenuItem";
			this->viewScheduleToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->viewScheduleToolStripMenuItem->Text = L"View Schedule";
			// 
			// profileToolStripMenuItem
			// 
			this->profileToolStripMenuItem->Name = L"profileToolStripMenuItem";
			this->profileToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->profileToolStripMenuItem->Text = L"Profile";
			// 
			// facultyToolStripMenuItem
			// 
			this->facultyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->manageCoursesToolStripMenuItem,
					this->enterGradesToolStripMenuItem, this->viewRosterToolStripMenuItem, this->profileToolStripMenuItem1
			});
			this->facultyToolStripMenuItem->Name = L"facultyToolStripMenuItem";
			this->facultyToolStripMenuItem->Size = System::Drawing::Size(82, 29);
			this->facultyToolStripMenuItem->Text = L"Faculty";
			// 
			// manageCoursesToolStripMenuItem
			// 
			this->manageCoursesToolStripMenuItem->Name = L"manageCoursesToolStripMenuItem";
			this->manageCoursesToolStripMenuItem->Size = System::Drawing::Size(246, 34);
			this->manageCoursesToolStripMenuItem->Text = L"Manage Courses";
			// 
			// enterGradesToolStripMenuItem
			// 
			this->enterGradesToolStripMenuItem->Name = L"enterGradesToolStripMenuItem";
			this->enterGradesToolStripMenuItem->Size = System::Drawing::Size(246, 34);
			this->enterGradesToolStripMenuItem->Text = L"Enter Grades";
			// 
			// viewRosterToolStripMenuItem
			// 
			this->viewRosterToolStripMenuItem->Name = L"viewRosterToolStripMenuItem";
			this->viewRosterToolStripMenuItem->Size = System::Drawing::Size(246, 34);
			this->viewRosterToolStripMenuItem->Text = L"View Roster";
			// 
			// profileToolStripMenuItem1
			// 
			this->profileToolStripMenuItem1->Name = L"profileToolStripMenuItem1";
			this->profileToolStripMenuItem1->Size = System::Drawing::Size(246, 34);
			this->profileToolStripMenuItem1->Text = L"Profile";
			// 
			// administratorToolStripMenuItem
			// 
			this->administratorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->manageStudentsToolStripMenuItem,
					this->manageFacultyToolStripMenuItem, this->manageCoursesToolStripMenuItem1, this->generateReportsToolStripMenuItem, this->manageFinancialsToolStripMenuItem
			});
			this->administratorToolStripMenuItem->Name = L"administratorToolStripMenuItem";
			this->administratorToolStripMenuItem->Size = System::Drawing::Size(137, 29);
			this->administratorToolStripMenuItem->Text = L"Administrator";
			// 
			// manageStudentsToolStripMenuItem
			// 
			this->manageStudentsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addStudentToolStripMenuItem,
					this->removeStudentToolStripMenuItem, this->editStudentToolStripMenuItem
			});
			this->manageStudentsToolStripMenuItem->Name = L"manageStudentsToolStripMenuItem";
			this->manageStudentsToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->manageStudentsToolStripMenuItem->Text = L"Manage Students";
			// 
			// manageFacultyToolStripMenuItem
			// 
			this->manageFacultyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addFacultyToolStripMenuItem,
					this->removeFacultyToolStripMenuItem, this->editStudentToolStripMenuItem1
			});
			this->manageFacultyToolStripMenuItem->Name = L"manageFacultyToolStripMenuItem";
			this->manageFacultyToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->manageFacultyToolStripMenuItem->Text = L"Manage Faculty";
			// 
			// manageCoursesToolStripMenuItem1
			// 
			this->manageCoursesToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addCourseToolStripMenuItem,
					this->removeCourseToolStripMenuItem, this->editCourseToolStripMenuItem
			});
			this->manageCoursesToolStripMenuItem1->Name = L"manageCoursesToolStripMenuItem1";
			this->manageCoursesToolStripMenuItem1->Size = System::Drawing::Size(270, 34);
			this->manageCoursesToolStripMenuItem1->Text = L"Manage Courses";
			// 
			// generateReportsToolStripMenuItem
			// 
			this->generateReportsToolStripMenuItem->Name = L"generateReportsToolStripMenuItem";
			this->generateReportsToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->generateReportsToolStripMenuItem->Text = L"Generate Reports ";
			// 
			// manageFinancialsToolStripMenuItem
			// 
			this->manageFinancialsToolStripMenuItem->Name = L"manageFinancialsToolStripMenuItem";
			this->manageFinancialsToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->manageFinancialsToolStripMenuItem->Text = L"Manage Financials";
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->toolStripButton1,
					this->toolStripButton2, this->toolStripButton3, this->toolStripButton4, this->toolStripButton6
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 33);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(905, 33);
			this->toolStrip1->TabIndex = 4;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(34, 28);
			this->toolStripButton1->Text = L"Add Student";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &mdiForm::toolStripButton1_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(34, 28);
			this->toolStripButton2->Text = L"Add Faculty";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &mdiForm::toolStripButton2_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(34, 28);
			this->toolStripButton3->Text = L"Add Admin";
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(34, 28);
			this->toolStripButton4->Text = L"Profile";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &mdiForm::toolStripButton4_Click);
			// 
			// toolStripButton6
			// 
			this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton6.Image")));
			this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton6->Name = L"toolStripButton6";
			this->toolStripButton6->Size = System::Drawing::Size(34, 28);
			this->toolStripButton6->Text = L"toolStripButton6";
			this->toolStripButton6->Click += gcnew System::EventHandler(this, &mdiForm::toolStripButton6_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripStatusLabel1,
					this->toolStripStatusLabel2
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 362);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(905, 32);
			this->statusStrip1->TabIndex = 5;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(0, 25);
			// 
			// toolStripStatusLabel2
			// 
			this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
			this->toolStripStatusLabel2->Size = System::Drawing::Size(53, 25);
			this->toolStripStatusLabel2->Text = L"Date:";
			// 
			// addStudentToolStripMenuItem
			// 
			this->addStudentToolStripMenuItem->Name = L"addStudentToolStripMenuItem";
			this->addStudentToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->addStudentToolStripMenuItem->Text = L"Add Student";
			this->addStudentToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::addStudentToolStripMenuItem_Click);
			// 
			// removeStudentToolStripMenuItem
			// 
			this->removeStudentToolStripMenuItem->Name = L"removeStudentToolStripMenuItem";
			this->removeStudentToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->removeStudentToolStripMenuItem->Text = L"Remove Student";
			// 
			// addFacultyToolStripMenuItem
			// 
			this->addFacultyToolStripMenuItem->Name = L"addFacultyToolStripMenuItem";
			this->addFacultyToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->addFacultyToolStripMenuItem->Text = L"Add Faculty";
			// 
			// removeFacultyToolStripMenuItem
			// 
			this->removeFacultyToolStripMenuItem->Name = L"removeFacultyToolStripMenuItem";
			this->removeFacultyToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->removeFacultyToolStripMenuItem->Text = L"Remove Faculty";
			// 
			// editStudentToolStripMenuItem
			// 
			this->editStudentToolStripMenuItem->Name = L"editStudentToolStripMenuItem";
			this->editStudentToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->editStudentToolStripMenuItem->Text = L"Edit Student";
			// 
			// editStudentToolStripMenuItem1
			// 
			this->editStudentToolStripMenuItem1->Name = L"editStudentToolStripMenuItem1";
			this->editStudentToolStripMenuItem1->Size = System::Drawing::Size(270, 34);
			this->editStudentToolStripMenuItem1->Text = L"Edit Student";
			// 
			// addCourseToolStripMenuItem
			// 
			this->addCourseToolStripMenuItem->Name = L"addCourseToolStripMenuItem";
			this->addCourseToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->addCourseToolStripMenuItem->Text = L"Add Course";
			// 
			// removeCourseToolStripMenuItem
			// 
			this->removeCourseToolStripMenuItem->Name = L"removeCourseToolStripMenuItem";
			this->removeCourseToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->removeCourseToolStripMenuItem->Text = L"Remove Course";
			// 
			// editCourseToolStripMenuItem
			// 
			this->editCourseToolStripMenuItem->Name = L"editCourseToolStripMenuItem";
			this->editCourseToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->editCourseToolStripMenuItem->Text = L"Edit Course";
			// 
			// mdiForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(905, 394);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->IsMdiContainer = true;
			this->Name = L"mdiForm";
			this->Text = L"University Students Management System";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &mdiForm::mdiForm_Load);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void ConfigureUIBasedOnRole() {
			if (UserRole == "Student") {

				// Show only student-related items
				studentToolStripMenuItem->Visible = true;
				facultyToolStripMenuItem->Visible = false;
				administratorToolStripMenuItem->Visible = false;
				toolStripButton1->Visible = false; // Hide admin button
				toolStripButton2->Visible = false; // Hide faculty button
				toolStripButton3->Visible = false; // Hide admin button
			}
			else if (UserRole == "Faculty") {
				// Show faculty-related items
				studentToolStripMenuItem->Visible = false;
				facultyToolStripMenuItem->Visible = true;
				administratorToolStripMenuItem->Visible = false;
				toolStripButton1->Visible = false; // Hide student button
				toolStripButton2->Visible = false;  // Show faculty button
				toolStripButton3->Visible = false; // Hide admin button
			}
			else if (UserRole == "Admin") {
				// Show administrator-related items
				studentToolStripMenuItem->Visible = false;
				facultyToolStripMenuItem->Visible = false;
				administratorToolStripMenuItem->Visible = true;
				toolStripButton1->Visible = true;  // Show admin button
				toolStripButton2->Visible = true;  // Show faculty button
				toolStripButton3->Visible = true;  // Show admin button
			}
			else {
				MessageBox::Show(UserRole);
				// Default, maybe logged-out state
				studentToolStripMenuItem->Visible = false;
				facultyToolStripMenuItem->Visible = false;
				administratorToolStripMenuItem->Visible = false;
				toolStripButton1->Visible = false;
				toolStripButton2->Visible = false;
				toolStripButton3->Visible = false;
			}
		}

#pragma endregion
private: System::Void toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void mdiForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripButton6_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void toolStripButton4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void addStudentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	addUser ^ addStudentForm = gcnew addUser();
	addStudentForm->MdiParent = this;  // Set the MDI parent to the current form
	addStudentForm->Show();

	// Assuming the user will enter their details and submit via a button or dialog
	if (addStudentForm->DialogResult == Windows::Forms::DialogResult::OK) {
		String^ firstName = addStudentForm->firstNameTextBox->Text;
		String^ lastName = addStudentForm->lastNameTextBox->Text;
		String^ email = addStudentForm->emailTextBox->Text;
		DateTime^ dob = addStudentForm->dobPicker->Value;
		Image^ picture = addStudentForm->pictureBox->Image;
		String^ password = addStudentForm->passwordTextBox->Text;
		String^ confirmPassword = addStudentForm->confirmPasswordTextBox->Text;

		// Validate passwords
		if (password != confirmPassword) {
			MessageBox::Show("Passwords do not match. Please try again.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return; // Stop further processing if passwords don't match
		}

		// Hardcode the role as "Student"
		String^ role = "Student";

		// Insert the student into the database
		InsertStudentIntoDatabase(firstName, lastName, email, dob, picture, password, role);
	}
}

	   // Method to insert the student data into the database
	   void InsertStudentIntoDatabase(String^ firstName, String^ lastName, String^ email, DateTime^ dob, Image^ picture, String^ password, String^ role) {
		   // Implement the logic to insert the student into your database.
		   // This is just a placeholder for the actual database logic.

		   // For example:
		   // String^ connectionString = "your_connection_string_here";
		   // SqlConnection^ connection = gcnew SqlConnection(connectionString);
		   // SqlCommand^ command = gcnew SqlCommand("INSERT INTO Students (FirstName, LastName, Email, DateOfBirth, Picture, Password, Role) VALUES (@FirstName, @LastName, @Email, @DOB, @Picture, @Password, @Role)", connection);

		   // Add parameters to the SQL command
		   // command->Parameters->AddWithValue("@FirstName", firstName);
		   // command->Parameters->AddWithValue("@LastName", lastName);
		   // command->Parameters->AddWithValue("@Email", email);
		   // command->Parameters->AddWithValue("@DOB", dob);
		   // command->Parameters->AddWithValue("@Picture", picture);
		   // command->Parameters->AddWithValue("@Password", password);
		   // command->Parameters->AddWithValue("@Role", role);

		   // Execute the command
		   // connection->Open();
		   // command->ExecuteNonQuery();
		   // connection->Close();

		   MessageBox::Show("Student added successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	   }
};
