#pragma once

#include <iostream>
#include "../undo_redo.cpp"
#include "../undo.cpp"
#include "../scanner.cpp"
#include "../Tree.cpp"
#include "../TreeGUI.cpp"
#include "../Tree.h"
#include "../parse.h"

//#include <cstdio>

#include <msclr\marshal_cppstd.h>





namespace GUIP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Xml;
	using namespace std;

	using namespace msclr::interop; // Required for string conversions

	//GUIDS::Operation globalOperation;
	// Forward declaration of the Operation class

	// Declare a global object of the Operation class
	//extern Operation globalOperation;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	private: System::Windows::Forms::Button^ button12;

	private: System::Windows::Forms::Button^ button4;




	private: System::Windows::Forms::Button^ button11;


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:








	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Panel^ panel1;






	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->HideSelection = false;
			resources->ApplyResources(this->textBox1, L"textBox1");
			this->textBox1->Name = L"textBox1";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button12);
			this->panel1->Controls->Add(this->button11);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->Name = L"panel1";
			// 
			// button4
			// 
			this->button4->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button4, L"button4");
			this->button4->Name = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button12
			// 
			this->button12->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button12, L"button12");
			this->button12->Name = L"button12";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button11
			// 
			this->button11->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button11, L"button11");
			this->button11->Name = L"button11";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button3
			// 
			this->button3->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button3, L"button3");
			this->button3->Name = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_1);
			// 
			// button2
			// 
			this->button2->ForeColor = System::Drawing::SystemColors::Desktop;
			resources->ApplyResources(this->button2, L"button2");
			this->button2->Name = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// button1
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->AcceptsReturn = true;
			this->textBox2->AcceptsTab = true;
			this->textBox2->AllowDrop = true;
			resources->ApplyResources(this->textBox2, L"textBox2");
			this->textBox2->BackColor = System::Drawing::SystemColors::Info;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// MyForm
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox1);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Stream^ myStream;
	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
	openFileDialog1->InitialDirectory = "";
	openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->FilterIndex = 1;
	openFileDialog1->RestoreDirectory = true;
	String^ filePath = openFileDialog1->FileName;



	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{

		if ((myStream = openFileDialog1->OpenFile()) != nullptr)
		{

			String^ fileName = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
			String^ readFile = File::ReadAllText(fileName);
			std::string input = msclr::interop::marshal_as<std::string>(readFile);
			input = newLinesinString(input);
			System::String^ output = msclr::interop::marshal_as<String^>(input);
		
			textBox1->Text = output;
			

			myStream->Close();
		}
	}
	return System::Void();
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}


private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(textBox1->Text)) {
		MessageBox::Show("Input is empty. Please provide valid input or file.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return; // Exit the function if input is empty
	}
	try {
		std::string input = msclr::interop::marshal_as<std::string>(textBox1->Text);
		input = scanner(input);
		input = newLinesinString(input);

		System::String^ output = msclr::interop::marshal_as<String^>(input);
		textBox2->Text = output;
	}
	catch (std::exception& ex) {
		// Handle parsing errors
		MessageBox::Show("Error: " + gcnew System::String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}	
private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {

	if (String::IsNullOrWhiteSpace(textBox1->Text)) {
		MessageBox::Show("Input is empty. Please provide valid input.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	try{
		std::string input = msclr::interop::marshal_as<std::string>(textBox1->Text);
		input = scanner(input);
		queue<Token> tokens = readTokensFromFile(input);
		Parser parser(&tokens);
		Node* parseTree = parser.program();

		//if (parseTree->children.empty()) {
		if (!tokens.empty() && tokens.front().type == "Error") {
			// Check if input is empty
			MessageBox::Show("Error empty child.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
        
		if (containsError(parseTree)) {
			MessageBox::Show("Error.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		SyntaxTree treeDrawer;
		treeDrawer.draw(parseTree);

		//System::String^ filePath = "D:\senior 2\compilers\Scanner-Parser-GUI-main(v4) - Copy\Scanner-Parser-GUI-main\GUIP\SavedFiles";
		//System::String^ filePath = "D:\\senior 2\\compilers\\Scanner-Parser-GUI-main(v4) - Copy\\Scanner-Parser-GUI-main\\GUIP\\SavedFiles";
       /* System::String^ filePath = "SavedFiles\\tree1.png";
                if (System::IO::File::Exists(filePath)) {
                    System::IO::File::Delete(filePath);
                }
                System::IO::File::Move("tree1.png", filePath);*/
		System::String^ appDirectory = System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location);
		System::String^ savedFilesDirectory = System::IO::Path::Combine(appDirectory, "SavedFiles");

		// Ensure the "SavedFiles" folder exists
		if (!System::IO::Directory::Exists(savedFilesDirectory)) {
			System::IO::Directory::CreateDirectory(savedFilesDirectory);
		}

		System::String^ filePath = System::IO::Path::Combine(savedFilesDirectory, "tree1.png");

		// Check if the file already exists and delete it if necessary
		if (System::IO::File::Exists(filePath)) {
			System::IO::File::Delete(filePath);
		}

		// Move the generated file to the SavedFiles directory
		System::IO::File::Move("tree1.png", filePath);

		// Cleanup: Delete parseTree
		if (parseTree != nullptr) {
			delete parseTree;
			parseTree = nullptr;
		}
		System::Diagnostics::Process::Start(gcnew System::Diagnostics::ProcessStartInfo(filePath));
	}
	catch (std::exception& ex) {
		// Handle parsing errors
		MessageBox::Show("Error: " + gcnew System::String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ output = msclr::interop::marshal_as<String^>(globalOperation.UNDO());
	//if (output != "NOT FOUND")
	textBox1->Text = output;
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	//Operation op;
	System::String^ output = msclr::interop::marshal_as<String^>(globalOperation.REDO());
	//if (output != "NOT FOUND")
	textBox1->Text = output;
}

private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {


	//	System::String^ outputu = msclr::interop::marshal_as<String^>(globalOperation.UNDO());

		//if (outputu != "NOT FOUND")

}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
//private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
//	std::string outputFilePath = "SavedFiles\\scanner_output.txt";
//	try {
//		StreamWriter^ sw = gcnew StreamWriter("SavedFiles" + "\\Scanner.txt");
//		sw->Write(textBox2->Text);
//		sw->Flush();
//		sw->Close();
//		MessageBox::Show("Scanner output saved successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
//	}
//	catch (const std::exception& e) {
//		MessageBox::Show("Error saving scanner output: " + gcnew System::String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
//	}	
//}
    private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		   try {
			   // Get the application's directory
			   System::String^ appDirectory = System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location);
			   System::String^ savedFilesDirectory = System::IO::Path::Combine(appDirectory, "SavedFiles");

			   // Ensure the "SavedFiles" folder exists
			   if (!System::IO::Directory::Exists(savedFilesDirectory)) {
				   System::IO::Directory::CreateDirectory(savedFilesDirectory);
			   }

			   // Create the dynamic file path
			   System::String^ outputFilePath = System::IO::Path::Combine(savedFilesDirectory, "Scanner.txt");

			   // Write the content of textBox2 to the file
			   StreamWriter^ sw = gcnew StreamWriter(outputFilePath);
			   sw->Write(textBox2->Text);
			   sw->Flush();
			   sw->Close();

			   // Notify the user of success
			   MessageBox::Show("Scanner output saved successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		   }
		   catch (const std::exception& e) {
			   // Handle errors during file operations
			   MessageBox::Show("Error saving scanner output: " + gcnew System::String(e.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		   }
	   }
private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	std::string input = msclr::interop::marshal_as<std::string>(textBox1->Text);
	if (input != "NOT FOUND")
		globalOperation.addOperation(input);

	std::string input_T = msclr::interop::marshal_as<std::string>(textBox1->Text);
	input_T = scanner(input_T);
	input_T = newLinesinString(input_T);

	System::String^ output = msclr::interop::marshal_as<String^>(input_T);
	textBox2->Text = output;


}
};
}
