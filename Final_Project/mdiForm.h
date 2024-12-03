#pragma once
#include "addUsr.h"
#include "Add_Course.h"
#include "EnrollCourse.h"
#include "facultyCourse.h"


using namespace System::Windows::Forms;


namespace FinalProject
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace System::IO;




	/// <summary>
	/// Summary for mdiForm
	/// </summary>
	public ref class mdiForm : public System::Windows::Forms::Form
	{
		MySqlConnection^ sqlConn = gcnew MySqlConnection();
		MySqlCommand^ sqlCmd = gcnew MySqlCommand();
		DataTable^ sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter();

	private: System::String^ UserRole;
	private: System::Windows::Forms::ToolStripMenuItem^ profileToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ approveEnrollmentsToolStripMenuItem;
		   String^ user_email;

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
		void SetUserEmail(System::String^ email) {
			this->user_email = email;  // Set role after login
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
	private: System::Windows::Forms::ToolStripMenuItem^ viewStudentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewStudenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ viewCoursesToolStripMenuItem;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

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
			this->profileToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administratorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageStudentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addStudentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeStudentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editStudentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewStudentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageFacultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addFacultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeFacultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editStudentToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewStudenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->manageCoursesToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewCoursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->approveEnrollmentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->logoutToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::logoutToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(171, 34);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::exitToolStripMenuItem_Click);
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
			this->enrollInCourseToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::enrollInCourseToolStripMenuItem_Click);
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
			this->facultyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->manageCoursesToolStripMenuItem,
					this->approveEnrollmentsToolStripMenuItem, this->enterGradesToolStripMenuItem, this->viewRosterToolStripMenuItem, this->profileToolStripMenuItem1,
					this->profileToolStripMenuItem2
			});
			this->facultyToolStripMenuItem->Name = L"facultyToolStripMenuItem";
			this->facultyToolStripMenuItem->Size = System::Drawing::Size(82, 29);
			this->facultyToolStripMenuItem->Text = L"Faculty";
			// 
			// manageCoursesToolStripMenuItem
			// 
			this->manageCoursesToolStripMenuItem->Name = L"manageCoursesToolStripMenuItem";
			this->manageCoursesToolStripMenuItem->Size = System::Drawing::Size(306, 34);
			this->manageCoursesToolStripMenuItem->Text = L"Manage Course Material";
			// 
			// enterGradesToolStripMenuItem
			// 
			this->enterGradesToolStripMenuItem->Name = L"enterGradesToolStripMenuItem";
			this->enterGradesToolStripMenuItem->Size = System::Drawing::Size(306, 34);
			this->enterGradesToolStripMenuItem->Text = L"Enter Grades";
			// 
			// viewRosterToolStripMenuItem
			// 
			this->viewRosterToolStripMenuItem->Name = L"viewRosterToolStripMenuItem";
			this->viewRosterToolStripMenuItem->Size = System::Drawing::Size(306, 34);
			this->viewRosterToolStripMenuItem->Text = L"View Roster";
			// 
			// profileToolStripMenuItem1
			// 
			this->profileToolStripMenuItem1->Name = L"profileToolStripMenuItem1";
			this->profileToolStripMenuItem1->Size = System::Drawing::Size(306, 34);
			this->profileToolStripMenuItem1->Text = L"View Academic Records";
			this->profileToolStripMenuItem1->Click += gcnew System::EventHandler(this, &mdiForm::profileToolStripMenuItem1_Click);
			// 
			// profileToolStripMenuItem2
			// 
			this->profileToolStripMenuItem2->Name = L"profileToolStripMenuItem2";
			this->profileToolStripMenuItem2->Size = System::Drawing::Size(306, 34);
			this->profileToolStripMenuItem2->Text = L"Profile";
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
			this->manageStudentsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->addStudentToolStripMenuItem,
					this->removeStudentToolStripMenuItem, this->editStudentToolStripMenuItem, this->viewStudentToolStripMenuItem
			});
			this->manageStudentsToolStripMenuItem->Name = L"manageStudentsToolStripMenuItem";
			this->manageStudentsToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->manageStudentsToolStripMenuItem->Text = L"Manage Students";
			// 
			// addStudentToolStripMenuItem
			// 
			this->addStudentToolStripMenuItem->Name = L"addStudentToolStripMenuItem";
			this->addStudentToolStripMenuItem->Size = System::Drawing::Size(244, 34);
			this->addStudentToolStripMenuItem->Text = L"Add Student";
			this->addStudentToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::addStudentToolStripMenuItem_Click);
			// 
			// removeStudentToolStripMenuItem
			// 
			this->removeStudentToolStripMenuItem->Name = L"removeStudentToolStripMenuItem";
			this->removeStudentToolStripMenuItem->Size = System::Drawing::Size(244, 34);
			this->removeStudentToolStripMenuItem->Text = L"Remove Student";
			this->removeStudentToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::removeStudentToolStripMenuItem_Click);
			// 
			// editStudentToolStripMenuItem
			// 
			this->editStudentToolStripMenuItem->Name = L"editStudentToolStripMenuItem";
			this->editStudentToolStripMenuItem->Size = System::Drawing::Size(244, 34);
			this->editStudentToolStripMenuItem->Text = L"Edit Student";
			this->editStudentToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::editStudentToolStripMenuItem_Click);
			// 
			// viewStudentToolStripMenuItem
			// 
			this->viewStudentToolStripMenuItem->Name = L"viewStudentToolStripMenuItem";
			this->viewStudentToolStripMenuItem->Size = System::Drawing::Size(244, 34);
			this->viewStudentToolStripMenuItem->Text = L"View Students";
			this->viewStudentToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::viewStudentToolStripMenuItem_Click);
			// 
			// manageFacultyToolStripMenuItem
			// 
			this->manageFacultyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->addFacultyToolStripMenuItem,
					this->removeFacultyToolStripMenuItem, this->editStudentToolStripMenuItem1, this->viewStudenToolStripMenuItem
			});
			this->manageFacultyToolStripMenuItem->Name = L"manageFacultyToolStripMenuItem";
			this->manageFacultyToolStripMenuItem->Size = System::Drawing::Size(270, 34);
			this->manageFacultyToolStripMenuItem->Text = L"Manage Faculty";
			// 
			// addFacultyToolStripMenuItem
			// 
			this->addFacultyToolStripMenuItem->Name = L"addFacultyToolStripMenuItem";
			this->addFacultyToolStripMenuItem->Size = System::Drawing::Size(237, 34);
			this->addFacultyToolStripMenuItem->Text = L"Add Faculty";
			this->addFacultyToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::addFacultyToolStripMenuItem_Click);
			// 
			// removeFacultyToolStripMenuItem
			// 
			this->removeFacultyToolStripMenuItem->Name = L"removeFacultyToolStripMenuItem";
			this->removeFacultyToolStripMenuItem->Size = System::Drawing::Size(237, 34);
			this->removeFacultyToolStripMenuItem->Text = L"Remove Faculty";
			this->removeFacultyToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::removeFacultyToolStripMenuItem_Click);
			// 
			// editStudentToolStripMenuItem1
			// 
			this->editStudentToolStripMenuItem1->Name = L"editStudentToolStripMenuItem1";
			this->editStudentToolStripMenuItem1->Size = System::Drawing::Size(237, 34);
			this->editStudentToolStripMenuItem1->Text = L"Edit Faculty";
			this->editStudentToolStripMenuItem1->Click += gcnew System::EventHandler(this, &mdiForm::editStudentToolStripMenuItem1_Click);
			// 
			// viewStudenToolStripMenuItem
			// 
			this->viewStudenToolStripMenuItem->Name = L"viewStudenToolStripMenuItem";
			this->viewStudenToolStripMenuItem->Size = System::Drawing::Size(237, 34);
			this->viewStudenToolStripMenuItem->Text = L"View Faculty";
			this->viewStudenToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::viewStudenToolStripMenuItem_Click);
			// 
			// manageCoursesToolStripMenuItem1
			// 
			this->manageCoursesToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->addCourseToolStripMenuItem,
					this->removeCourseToolStripMenuItem, this->editCourseToolStripMenuItem, this->viewCoursesToolStripMenuItem
			});
			this->manageCoursesToolStripMenuItem1->Name = L"manageCoursesToolStripMenuItem1";
			this->manageCoursesToolStripMenuItem1->Size = System::Drawing::Size(270, 34);
			this->manageCoursesToolStripMenuItem1->Text = L"Manage Courses";
			// 
			// addCourseToolStripMenuItem
			// 
			this->addCourseToolStripMenuItem->Name = L"addCourseToolStripMenuItem";
			this->addCourseToolStripMenuItem->Size = System::Drawing::Size(238, 34);
			this->addCourseToolStripMenuItem->Text = L"Add Course";
			this->addCourseToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::addCourseToolStripMenuItem_Click);
			// 
			// removeCourseToolStripMenuItem
			// 
			this->removeCourseToolStripMenuItem->Name = L"removeCourseToolStripMenuItem";
			this->removeCourseToolStripMenuItem->Size = System::Drawing::Size(238, 34);
			this->removeCourseToolStripMenuItem->Text = L"Remove Course";
			this->removeCourseToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::removeCourseToolStripMenuItem_Click);
			// 
			// editCourseToolStripMenuItem
			// 
			this->editCourseToolStripMenuItem->Name = L"editCourseToolStripMenuItem";
			this->editCourseToolStripMenuItem->Size = System::Drawing::Size(238, 34);
			this->editCourseToolStripMenuItem->Text = L"Edit Course";
			this->editCourseToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::editCourseToolStripMenuItem_Click);
			// 
			// viewCoursesToolStripMenuItem
			// 
			this->viewCoursesToolStripMenuItem->Name = L"viewCoursesToolStripMenuItem";
			this->viewCoursesToolStripMenuItem->Size = System::Drawing::Size(238, 34);
			this->viewCoursesToolStripMenuItem->Text = L"View Courses";
			this->viewCoursesToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::viewCoursesToolStripMenuItem_Click);
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
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &mdiForm::toolStripButton3_Click);
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
			this->toolStripButton6->ToolTipText = L"Logout";
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
			// approveEnrollmentsToolStripMenuItem
			// 
			this->approveEnrollmentsToolStripMenuItem->Name = L"approveEnrollmentsToolStripMenuItem";
			this->approveEnrollmentsToolStripMenuItem->Size = System::Drawing::Size(306, 34);
			this->approveEnrollmentsToolStripMenuItem->Text = L"Approve Enrollments";
			this->approveEnrollmentsToolStripMenuItem->Click += gcnew System::EventHandler(this, &mdiForm::approveEnrollmentsToolStripMenuItem_Click);
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
		// Function to get the current student's ID based on the email
		int GetCurrentStudentID() {
			try {
				// Ensure the email is not empty or null
				if (String::IsNullOrEmpty(user_email)) {
					throw gcnew Exception("User email is not available.");
				}

				// Open database connection
				sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
				sqlConn->Open();

				// Query to get StudentID from the Students table using the logged-in user's email
				sqlCmd->Connection = sqlConn;
				sqlCmd->CommandText = "SELECT StudentID FROM Students INNER JOIN Users ON Students.UserID = Users.UserID WHERE Users.Email = @Email";
				sqlCmd->Parameters->Clear();
				sqlCmd->Parameters->AddWithValue("@Email", user_email);

				// Execute the query and fetch the StudentID
				Object^ studentIDObj = sqlCmd->ExecuteScalar();

				// Check if the student is found and return the ID
				if (studentIDObj != nullptr) {
					return Convert::ToInt32(studentIDObj);
				}
				else {
					MessageBox::Show("Student not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return -1;  // Returning -1 if no student is found
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return -1;
			}
			finally {
				if (sqlConn->State == ConnectionState::Open) {
					sqlConn->Close();
				}
			}
		}


#pragma endregion
	private: System::Void toolStripButton1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create an instance of the addUser form
		addUsr^ addUserForm = gcnew addUsr("Student");

		// Display the form as a modal dialog
		addUserForm->ShowDialog();
	}
	private: System::Void mdiForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void toolStripButton6_Click(System::Object^ sender, System::EventArgs^ e) {
		
		// Show confirmation dialog
		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Are you sure you want to log out?",
			"Confirm Logout",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);

		if (result == System::Windows::Forms::DialogResult::Yes) {
			

			// Exit the application
			Application::Exit();
		}

	}
	private: System::Void toolStripButton4_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ user_role = UserRole;
		String^ email = user_email;
		try {
			// Open the database connection
			sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
			sqlConn->Open();

			// Query for the user information based on the logged-in user's email
			sqlCmd->Connection = sqlConn;

			String^ query = "SELECT Users.FirstName, Users.LastName, Users.Email, Users.DateOfBirth, Users.ProfilePicture, ";

			if (user_role == "Student") {
				query += "Students.Major, Students.Status ";
				query += "FROM Users INNER JOIN Students ON Users.UserID = Students.UserID ";
			}
			else if (user_role == "Faculty") {
				query += "Faculty.Department, Faculty.Status ";
				query += "FROM Users INNER JOIN Faculty ON Users.UserID = Faculty.UserID ";
			}
			else if (user_role == "Admin") {
				query += "Administrators.AccessLevel ";
				query += "FROM Users INNER JOIN Administrators ON Users.UserID = Administrators.UserID ";
			}

			query += "WHERE Users.Email = @Email";

			sqlCmd->CommandText = query;
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@Email", email); // Use logged-in user's email

			MySqlDataReader^ reader = sqlCmd->ExecuteReader();

			if (reader->Read()) {
				// Create a new form to display the user's profile
				Form^ profileForm = gcnew Form();
				profileForm->Text = "Profile Information";
				profileForm->Width = 400;
				profileForm->Height = 300;

				// Create and display TextBoxes for the user's information
				TextBox^ firstNameBox = gcnew TextBox();
				firstNameBox->Text = "First Name: " + (reader["FirstName"] != DBNull::Value ? reader["FirstName"]->ToString() : "N/A");
				firstNameBox->Location = Point(10, 20);
				firstNameBox->Width = 350;
				firstNameBox->ReadOnly = true;

				TextBox^ lastNameBox = gcnew TextBox();
				lastNameBox->Text = "Last Name: " + (reader["LastName"] != DBNull::Value ? reader["LastName"]->ToString() : "N/A");
				lastNameBox->Location = Point(10, 60);
				lastNameBox->Width = 350;
				lastNameBox->ReadOnly = true;

				TextBox^ emailBox = gcnew TextBox();
				emailBox->Text = "Email: " + (reader["Email"] != DBNull::Value ? reader["Email"]->ToString() : "N/A");
				emailBox->Location = Point(10, 100);
				emailBox->Width = 350;
				emailBox->ReadOnly = true;

				TextBox^ dobBox = gcnew TextBox();
				dobBox->Text = "Date of Birth: " + reader["DateOfBirth"]->ToString();				dobBox->Location = Point(10, 140);
				dobBox->Width = 350;
				dobBox->ReadOnly = true;

				TextBox^ roleBox = gcnew TextBox();
				roleBox->Text = "Role: " + user_role; // Display the logged-in user's role
				roleBox->Location = Point(10, 180);
				roleBox->Width = 350;
				roleBox->ReadOnly = true;

				// Optionally, create a picture box to display the profile picture
				PictureBox^ pictureBox = gcnew PictureBox();
				if (reader["ProfilePicture"] != DBNull::Value) {
					array<Byte>^ imageData = (array<Byte>^)reader["ProfilePicture"];
					MemoryStream^ ms = gcnew MemoryStream(imageData);
					pictureBox->Image = Image::FromStream(ms);
				}
				else {
					pictureBox->Image = nullptr; // No image available
				}
				pictureBox->Location = Point(10, 220);
				pictureBox->Size = Drawing::Size(100, 100);
				pictureBox->SizeMode = PictureBoxSizeMode::StretchImage;

				// Add controls to the form
				profileForm->Controls->Add(firstNameBox);
				profileForm->Controls->Add(lastNameBox);
				profileForm->Controls->Add(emailBox);
				profileForm->Controls->Add(dobBox);
				profileForm->Controls->Add(roleBox);
				profileForm->Controls->Add(pictureBox);

				// Display the form
				profileForm->ShowDialog();

				// Display specific information based on the role
				if (user_role == "Student") {
					TextBox^ majorBox = gcnew TextBox();
					majorBox->Text = "Major: " + reader["Major"]->ToString();
					majorBox->Location = Point(10, 220);
					majorBox->Width = 350;
					majorBox->ReadOnly = true;

					TextBox^ statusBox = gcnew TextBox();
					statusBox->Text = "Status: " + reader["Status"]->ToString();
					statusBox->Location = Point(10, 260);
					statusBox->Width = 350;
					statusBox->ReadOnly = true;

					profileForm->Controls->Add(majorBox);
					profileForm->Controls->Add(statusBox);
				}
				else if (user_role == "Faculty") {
					TextBox^ departmentBox = gcnew TextBox();
					departmentBox->Text = "Department: " + reader["Department"]->ToString();
					departmentBox->Location = Point(10, 220);
					departmentBox->Width = 350;
					departmentBox->ReadOnly = true;

					TextBox^ statusBox = gcnew TextBox();
					statusBox->Text = "Status: " + reader["Status"]->ToString();
					statusBox->Location = Point(10, 260);
					statusBox->Width = 350;
					statusBox->ReadOnly = true;

					profileForm->Controls->Add(departmentBox);
					profileForm->Controls->Add(statusBox);
				}
				else if (user_role == "Admin") {
					TextBox^ accessLevelBox = gcnew TextBox();
					accessLevelBox->Text = "Access Level: " + reader["AccessLevel"]->ToString();
					accessLevelBox->Location = Point(10, 220);
					accessLevelBox->Width = 350;
					accessLevelBox->ReadOnly = true;

					profileForm->Controls->Add(accessLevelBox);
				}

				// Display the profile picture if available
				if (reader["ProfilePicture"] != DBNull::Value) {
					array<Byte>^ imageData = (array<Byte>^)reader["ProfilePicture"];
					MemoryStream^ ms = gcnew MemoryStream(imageData);
					PictureBox^ profilePictureBox = gcnew PictureBox();
					profilePictureBox->Image = Image::FromStream(ms);
					profilePictureBox->Location = Point(10, 300);
					profilePictureBox->Size = System::Drawing::Size(100, 100);
					profileForm->Controls->Add(profilePictureBox);
				}

				// Show the profile form
				//profileForm->ShowDialog();
			}
			else {
				MessageBox::Show(email);
				MessageBox::Show("No user found with the provided email.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

			reader->Close();
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

	private: System::Void toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create an instance of the addUser form
		addUsr^ addUserForm1 = gcnew addUsr("Faculty");

		// Display the form as a modal dialog
		addUserForm1->ShowDialog();
		addUserForm1->isEditMode = false;

	}

	private: System::Void addStudentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Create an instance of the addUser form
		addUsr^ addUserForm = gcnew addUsr("Student");

		// Display the form as a modal dialog
		addUserForm->ShowDialog();
		addUserForm->isEditMode = false;

	}
	private: System::Void addFacultyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{

		// Create an instance of the addUser form
		addUsr^ addUserForm1 = gcnew addUsr("Faculty");

		// Display the form as a modal dialog
		addUserForm1->ShowDialog();
		addUserForm1->isEditMode = false;
	}
	private: System::Void editStudentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create a prompt form to get the Student ID
		Form^ prompt = gcnew Form();
		prompt->Width = 300;
		prompt->Height = 150;
		prompt->Text = "Enter Student ID";

		Label^ label = gcnew Label();
		label->Text = "Index Number:";
		label->Location = Point(10, 10);
		label->AutoSize = true;

		TextBox^ textBox = gcnew TextBox();
		textBox->Location = Point(100, 10);
		textBox->Width = 150;

		Button^ confirmation = gcnew Button();
		confirmation->Text = "OK";
		confirmation->Location = Point(100, 50);
		confirmation->DialogResult = System::Windows::Forms::DialogResult::OK;

		prompt->Controls->Add(label);
		prompt->Controls->Add(textBox);
		prompt->Controls->Add(confirmation);
		prompt->AcceptButton = confirmation;

		// Show the prompt form
		if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			int indexNumber;
			if (int::TryParse(textBox->Text, indexNumber)) {
				// Open the addUser form
				addUsr^ editUserForm = gcnew addUsr("Student"); // Keep constructor simple
				editUserForm->isEditMode = true;
				editUserForm->editingIndexNumber = indexNumber;
				editUserForm->LoadStudentData(indexNumber); // Call new method for IndexNumber
				editUserForm->ShowDialog();
			}
			else {
				MessageBox::Show("Invalid Index Number. Please enter a numeric value.",
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}

		}
	}
		   // Helper Method to Delete Course
		void DeleteCourse(String^ courseID, MySqlConnection^ sqlConn) {
			try {
				MySqlCommand^ deleteCmd = gcnew MySqlCommand();
				deleteCmd->Connection = sqlConn;
				deleteCmd->CommandText = "DELETE FROM Courses WHERE CourseID = @CourseID";
				deleteCmd->Parameters->Clear();
				deleteCmd->Parameters->AddWithValue("@CourseID", courseID);

				int rowsAffected = deleteCmd->ExecuteNonQuery();

				if (rowsAffected > 0) {
					MessageBox::Show("Course removed successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else {
					MessageBox::Show("Failed to delete the course. Please ensure the Course ID is correct.",
						"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error while deleting the course: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	private: System::Void DeleteStudent(int indexNumber, MySqlConnection^ sqlConn) {
		try {
			//sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
			//sqlConn->Open();

			// Delete student record from Students table
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "DELETE users, students " +
				"FROM users INNER JOIN students ON users.UserID = students.UserID " +
				"WHERE students.IndexNumber = @IndexNumber";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@IndexNumber", indexNumber);

			int rowsAffected = sqlCmd->ExecuteNonQuery();

			if (rowsAffected > 0) {
				MessageBox::Show("Student record deleted successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				MessageBox::Show("No student found with the provided Index Number.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error deleting student: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//finally {
		//	if (sqlConn->State == ConnectionState::Open) {
		//		sqlConn->Close();
		//	}
		//}
	}void DeleteFaculty(String^ email, MySqlConnection^ sqlConn) {
		try {
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "DELETE FROM faculty WHERE UserID = (SELECT UserID FROM users WHERE Email = @Email)";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@Email", email);

			int rowsAffected = sqlCmd->ExecuteNonQuery();

			if (rowsAffected > 0) {
				MessageBox::Show("Faculty member deleted successfully.", "Deletion Successful", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else {
				MessageBox::Show("Error deleting faculty member.", "Deletion Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}


	private: System::Void removeStudentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create a prompt form to get the Student ID
		Form^ prompt = gcnew Form();
		prompt->Width = 300;
		prompt->Height = 150;
		prompt->Text = "Enter Student ID";

		Label^ label = gcnew Label();
		label->Text = "Index Number:";
		label->Location = Point(10, 10);
		label->AutoSize = true;

		TextBox^ textBox = gcnew TextBox();
		textBox->Location = Point(100, 10);
		textBox->Width = 150;

		Button^ confirmation = gcnew Button();
		confirmation->Text = "OK";
		confirmation->Location = Point(100, 50);
		confirmation->DialogResult = System::Windows::Forms::DialogResult::OK;

		prompt->Controls->Add(label);
		prompt->Controls->Add(textBox);
		prompt->Controls->Add(confirmation);
		prompt->AcceptButton = confirmation;

		// Show the prompt form
		if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			int indexNumber;
			if (int::TryParse(textBox->Text, indexNumber)) {
				try {
					sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
					sqlConn->Open();

					sqlCmd->Connection = sqlConn;
					sqlCmd->CommandText = "SELECT users.FirstName, users.LastName, users.Email, students.Major, students.Status " +
						"FROM Users INNER JOIN students ON users.UserID = students.UserID " +
						"WHERE students.IndexNumber = @IndexNumber";
					sqlCmd->Parameters->Clear();
					sqlCmd->Parameters->AddWithValue("@IndexNumber", indexNumber);

					MySqlDataReader^ reader = sqlCmd->ExecuteReader();

					if (reader->Read()) {
						// Step 4: Display the student's information
						String^ studentInfo = "First Name: " + reader["FirstName"]->ToString() + "\n" +
							"Last Name: " + reader["LastName"]->ToString() + "\n" +
							"Email: " + reader["Email"]->ToString() + "\n" +
							"Major: " + reader["Major"]->ToString() + "\n" +
							"Status: " + reader["Status"]->ToString();

						// Show the student info in a message box
						MessageBox::Show(studentInfo, "Student Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

						// Step 5: Ask user for confirmation to delete
						reader->Close(); // Close reader before DeleteStudent
						System::Windows::Forms::DialogResult result = MessageBox::Show("Are you sure you want to delete this student?",
							"Confirm Deletion", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

						if (result == System::Windows::Forms::DialogResult::Yes) {
							// Step 6: Call DeleteStudent method to remove the student
							DeleteStudent(indexNumber, sqlConn);
						}
					}
					else {
						MessageBox::Show("Student not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
					reader->Close();
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
			else {
				MessageBox::Show("Invalid Index Number. Please enter a numeric value.",
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}


	private: System::Void viewStudentToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			// Connect to the database
			sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
			sqlConn->Open();

			// Query to fetch student data
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT students.IndexNumber, users.FirstName, users.LastName, users.Email, " +
				"students.Major, students.Status " +
				"FROM students INNER JOIN users ON students.UserID = users.UserID";

			// Execute the query and fill the data into a DataTable
			MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter(sqlCmd);
			DataTable^ dataTable = gcnew DataTable();
			sqlDta->Fill(dataTable);

			// Create a form to display the data
			Form^ viewForm = gcnew Form();
			viewForm->Text = "View Students";
			viewForm->Width = 800;
			viewForm->Height = 400;

			// Add a DataGridView to the form
			DataGridView^ dataGridView = gcnew DataGridView();
			dataGridView->Dock = DockStyle::Fill;
			dataGridView->DataSource = dataTable;
			viewForm->Controls->Add(dataGridView);

			// Show the form
			viewForm->ShowDialog();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		finally {
			if (sqlConn->State == ConnectionState::Open) {
				sqlConn->Close();
			}
		}
	};
	private: System::Void toolStripButton3_Click(System::Object^ sender, System::EventArgs^ e) {
		// Create an instance of the addUser form
		addUsr^ addUserForm1 = gcnew addUsr("Admin");

		// Display the form as a modal dialog
		addUserForm1->ShowDialog();
		addUserForm1->isEditMode = false;
	}
private: System::Void removeFacultyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create a prompt form to get the Faculty Email
	Form^ prompt = gcnew Form();
	prompt->Width = 300;
	prompt->Height = 150;
	prompt->Text = "Enter Faculty Email";

	Label^ label = gcnew Label();
	label->Text = "Email:";
	label->Location = Point(10, 10);
	label->AutoSize = true;

	TextBox^ textBox = gcnew TextBox();
	textBox->Location = Point(100, 10);
	textBox->Width = 150;

	Button^ confirmation = gcnew Button();
	confirmation->Text = "OK";
	confirmation->Location = Point(100, 50);
	confirmation->DialogResult = System::Windows::Forms::DialogResult::OK;

	prompt->Controls->Add(label);
	prompt->Controls->Add(textBox);
	prompt->Controls->Add(confirmation);
	prompt->AcceptButton = confirmation;

	// Show the prompt form
	if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ facultyEmail = textBox->Text;

		try {
			sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
			sqlConn->Open();

			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT users.FirstName, users.LastName, users.Email, faculty.Department, faculty.Status " +
				"FROM users INNER JOIN faculty ON users.UserID = faculty.UserID " +
				"WHERE users.Email = @Email";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@Email", facultyEmail);

			MySqlDataReader^ reader = sqlCmd->ExecuteReader();

			if (reader->Read()) {
				// Step 4: Display the faculty's information
				String^ facultyInfo = "First Name: " + reader["FirstName"]->ToString() + "\n" +
					"Last Name: " + reader["LastName"]->ToString() + "\n" +
					"Email: " + reader["Email"]->ToString() + "\n" +
					"Department: " + reader["Department"]->ToString() + "\n" +
					"Status: " + reader["Status"]->ToString();

				// Show the faculty info in a message box
				MessageBox::Show(facultyInfo, "Faculty Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

				// Step 5: Ask user for confirmation to delete
				reader->Close(); // Close reader before DeleteFaculty
				System::Windows::Forms::DialogResult result = MessageBox::Show("Are you sure you want to delete this faculty member?",
					"Confirm Deletion", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

				if (result == System::Windows::Forms::DialogResult::Yes) {
					// Step 6: Call DeleteFaculty method to remove the faculty member
					DeleteFaculty(facultyEmail, sqlConn);
				}
			}
			else {
				MessageBox::Show("Faculty member not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			reader->Close();
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
	else {
		MessageBox::Show("Invalid Email. Please enter a valid email address.",
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}
private: System::Void viewStudenToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Connect to the database
		sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
		sqlConn->Open();

		// Query to fetch faculty data
		sqlCmd->Connection = sqlConn;
		sqlCmd->CommandText = "SELECT faculty.FacultyID, users.FirstName, users.LastName, users.Email, " +
			"faculty.Department, faculty.status " +
			"FROM faculty INNER JOIN users ON faculty.UserID = users.UserID";

		// Execute the query and fill the data into a DataTable
		MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter(sqlCmd);
		DataTable^ dataTable = gcnew DataTable();
		sqlDta->Fill(dataTable);

		// Create a form to display the data
		Form^ viewForm = gcnew Form();
		viewForm->Text = "View Faculty";
		viewForm->Width = 800;
		viewForm->Height = 400;

		// Add a DataGridView to the form
		DataGridView^ dataGridView = gcnew DataGridView();
		dataGridView->Dock = DockStyle::Fill;
		dataGridView->DataSource = dataTable;
		viewForm->Controls->Add(dataGridView);

		// Show the form
		viewForm->ShowDialog();
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
private: System::Void editStudentToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create a prompt form to get the Faculty Email
	Form^ prompt = gcnew Form();
	prompt->Width = 300;
	prompt->Height = 150;
	prompt->Text = "Enter Faculty Email";

	Label^ label = gcnew Label();
	label->Text = "Faculty Email:";
	label->Location = Point(10, 10);
	label->AutoSize = true;

	TextBox^ textBox = gcnew TextBox();
	textBox->Location = Point(100, 10);
	textBox->Width = 150;

	Button^ confirmation = gcnew Button();
	confirmation->Text = "OK";
	confirmation->Location = Point(100, 50);
	confirmation->DialogResult = System::Windows::Forms::DialogResult::OK;

	prompt->Controls->Add(label);
	prompt->Controls->Add(textBox);
	prompt->Controls->Add(confirmation);
	prompt->AcceptButton = confirmation;

	// Show the prompt form
	if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ facultyEmail = textBox->Text;

		if (!String::IsNullOrEmpty(facultyEmail)) {
			// Open the addUsr form for editing faculty
			addUsr^ editUserForm = gcnew addUsr("Faculty"); // Pass "Faculty" role
			editUserForm->isEditMode = true;
			editUserForm->LoadFacultyData(facultyEmail); // Load faculty-specific data
			editUserForm->ShowDialog();
		}
		else {
			MessageBox::Show("Invalid Email. Please enter a valid email address.",
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

}
private: System::Void viewCoursesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Connect to the database
		sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
		sqlConn->Open();

		// Query to fetch course data with the department name
		sqlCmd->Connection = sqlConn;
		sqlCmd->CommandText =
			"SELECT Courses.CourseID, Courses.CourseName, Courses.Credits, "
			"Departments.DepartmentName, Courses.Description "
			"FROM Courses "
			"INNER JOIN Departments ON Courses.DepartmentID = Departments.DepartmentID";

		// Execute the query and fill the data into a DataTable
		MySqlDataAdapter^ sqlDta = gcnew MySqlDataAdapter(sqlCmd);
		DataTable^ dataTable = gcnew DataTable();
		sqlDta->Fill(dataTable);

		// Create a form to display the data
		Form^ viewForm = gcnew Form();
		viewForm->Text = "View Courses";
		viewForm->Width = 800;
		viewForm->Height = 400;

		// Add a DataGridView to the form
		DataGridView^ dataGridView = gcnew DataGridView();
		dataGridView->Dock = DockStyle::Fill;
		dataGridView->DataSource = dataTable;
		viewForm->Controls->Add(dataGridView);

		// Show the form
		viewForm->ShowDialog();
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
private: System::Void removeCourseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create a prompt form to get the Course ID
	Form^ prompt = gcnew Form();
	prompt->Width = 300;
	prompt->Height = 150;
	prompt->Text = "Enter Course ID";

	Label^ label = gcnew Label();
	label->Text = "Course ID:";
	label->Location = Point(10, 10);
	label->AutoSize = true;

	TextBox^ textBox = gcnew TextBox();
	textBox->Location = Point(100, 10);
	textBox->Width = 150;

	Button^ confirmation = gcnew Button();
	confirmation->Text = "OK";
	confirmation->Location = Point(100, 50);
	confirmation->DialogResult = System::Windows::Forms::DialogResult::OK;

	prompt->Controls->Add(label);
	prompt->Controls->Add(textBox);
	prompt->Controls->Add(confirmation);
	prompt->AcceptButton = confirmation;

	// Show the prompt form
	if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ courseID = textBox->Text;

		try {
			sqlConn->ConnectionString = "datasource=localhost;port=3306;username=root;password=;database=usrmdb";
			sqlConn->Open();

			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "SELECT CourseName, Credits, DepartmentID, Description FROM Courses WHERE CourseID = @CourseID";
			sqlCmd->Parameters->Clear();
			sqlCmd->Parameters->AddWithValue("@CourseID", courseID);

			MySqlDataReader^ reader = sqlCmd->ExecuteReader();

			if (reader->Read()) {
				// Display course information
				String^ courseInfo = "Course Name: " + reader["CourseName"]->ToString() + "\n" +
					"Credits: " + reader["Credits"]->ToString() + "\n" +
					"Department: " + reader["DepartmentID"]->ToString() + "\n" +
					"Description: " + reader["Description"]->ToString();

				MessageBox::Show(courseInfo, "Course Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

				// Ask for confirmation to delete
				reader->Close(); // Close reader before delete operation
				System::Windows::Forms::DialogResult result = MessageBox::Show("Are you sure you want to delete this course?",
					"Confirm Deletion", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

				if (result == System::Windows::Forms::DialogResult::Yes) {
					DeleteCourse(courseID, sqlConn);
				}
			}
			else {
				MessageBox::Show("Course not found.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			reader->Close();
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
	else {
		MessageBox::Show("Invalid Course ID. Please enter a valid ID.",
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
	   
private: System::Void logoutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Show confirmation dialog
		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Are you sure you want to log out?",
			"Confirm Logout",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);

	if (result == System::Windows::Forms::DialogResult::Yes) {
		

		// Exit the application
		Application::Exit();
	}
}
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Show confirmation dialog
	System::Windows::Forms::DialogResult result = MessageBox::Show(
		"Are you sure you want to exit?",
		"Confirm Logout",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question
	);

	if (result == System::Windows::Forms::DialogResult::Yes) {


		// Exit the application
		Application::Exit();
	}
}
private: System::Void profileToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void addCourseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Create an instance of the AddCourse form
	Add_Course^ addCourseForm = gcnew Add_Course();

	addCourseForm->ShowDialog();

}
private: System::Void editCourseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// Prompt user for CourseID
	Form^ prompt = gcnew Form();
	prompt->Width = 300;
	prompt->Height = 150;
	prompt->Text = "Enter Course ID";

	Label^ label = gcnew Label();
	label->Text = "Course ID:";
	label->Location = Point(10, 10);
	label->AutoSize = true;

	TextBox^ textBox = gcnew TextBox();
	textBox->Location = Point(100, 10);
	textBox->Width = 150;

	Button^ confirmation = gcnew Button();
	confirmation->Text = "OK";
	confirmation->Location = Point(100, 50);
	confirmation->DialogResult = System::Windows::Forms::DialogResult::OK;

	prompt->Controls->Add(label);
	prompt->Controls->Add(textBox);
	prompt->Controls->Add(confirmation);
	prompt->AcceptButton = confirmation;

	// Show the prompt form
	if (prompt->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		String^ courseCode = textBox->Text->Trim();

		// Validate input and convert to integer
		int courseID;
		if (int::TryParse(courseCode, courseID)) {
			// Debugging: Confirm parsed CourseID
			MessageBox::Show("Parsed CourseID: " + courseID.ToString(),
				"Debug", MessageBoxButtons::OK, MessageBoxIcon::Information);

			// Open the Add_Course form for editing
			Add_Course^ editCourseForm = gcnew Add_Course();
			editCourseForm->isEditMode = true;
			editCourseForm->editingCourseID = courseID;
			editCourseForm->LoadCourseData(courseID); // Pass courseID as integer
			editCourseForm->ShowDialog();
		}
		else {
			MessageBox::Show("Invalid Course ID. Please enter a numeric value.",
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

private: System::Void enrollInCourseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Retrieve the logged-in user's email (assuming it is stored in a global variable or accessible in this context)
		String^ userEmail = user_email;

		// Create an instance of EnrollCourse form and pass the student ID to it
		EnrollCourse^ enrollCourseForm = gcnew EnrollCourse();
		enrollCourseForm->userEmail = user_email;

		// Show the EnrollCourse form
		enrollCourseForm->ShowDialog();
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}



private: System::Void approveEnrollmentsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ userEmail = user_email; 
	facultyCourse^ facultyForm = gcnew facultyCourse(userEmail);
	facultyForm->ShowDialog();
}
};
}