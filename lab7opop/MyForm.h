#pragma once
#include"BinaryFile.h"
#include <msclr/marshal_cppstd.h>
#include<string>


namespace lab7opop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		BinaryFile* file;
	private: System::Windows::Forms::ListBox^ input;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ file1_clear;
		   BinaryFile* newfile;
	public:
		MyForm(void)
		{
			InitializeComponent();
			file = new BinaryFile("my");
			newfile = new BinaryFile("new");

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
	private: System::Windows::Forms::Button^ add_b;
	protected:

	protected:
	private: System::Windows::Forms::TextBox^ number;
	private: System::Windows::Forms::TextBox^ a_t;
	private: System::Windows::Forms::TextBox^ b_t;
	private: System::Windows::Forms::TextBox^ multiple;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ListBox^ file1;
	private: System::Windows::Forms::ListBox^ file2;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ file1_show;
	private: System::Windows::Forms::Button^ file2_show;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->add_b = (gcnew System::Windows::Forms::Button());
			this->number = (gcnew System::Windows::Forms::TextBox());
			this->a_t = (gcnew System::Windows::Forms::TextBox());
			this->b_t = (gcnew System::Windows::Forms::TextBox());
			this->multiple = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->file1 = (gcnew System::Windows::Forms::ListBox());
			this->file2 = (gcnew System::Windows::Forms::ListBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->file1_show = (gcnew System::Windows::Forms::Button());
			this->file2_show = (gcnew System::Windows::Forms::Button());
			this->input = (gcnew System::Windows::Forms::ListBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->file1_clear = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// add_b
			// 
			this->add_b->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_b->Location = System::Drawing::Point(164, 43);
			this->add_b->Name = L"add_b";
			this->add_b->Size = System::Drawing::Size(120, 37);
			this->add_b->TabIndex = 0;
			this->add_b->Text = L"Додати";
			this->add_b->UseVisualStyleBackColor = true;
			this->add_b->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// number
			// 
			this->number->Location = System::Drawing::Point(26, 54);
			this->number->Name = L"number";
			this->number->Size = System::Drawing::Size(100, 26);
			this->number->TabIndex = 1;
			this->number->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::number_KeyPress);
			// 
			// a_t
			// 
			this->a_t->Location = System::Drawing::Point(26, 154);
			this->a_t->Name = L"a_t";
			this->a_t->Size = System::Drawing::Size(100, 26);
			this->a_t->TabIndex = 2;
			this->a_t->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::a_t_KeyPress);
			// 
			// b_t
			// 
			this->b_t->Location = System::Drawing::Point(164, 154);
			this->b_t->Name = L"b_t";
			this->b_t->Size = System::Drawing::Size(100, 26);
			this->b_t->TabIndex = 3;
			this->b_t->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::b_t_KeyPress);
			// 
			// multiple
			// 
			this->multiple->Location = System::Drawing::Point(26, 242);
			this->multiple->Name = L"multiple";
			this->multiple->Size = System::Drawing::Size(100, 26);
			this->multiple->TabIndex = 4;
			this->multiple->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::multiple_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 119);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Діапазон";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 205);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(202, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Число, на яке помножити";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 26);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(108, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Дійсне число";
			// 
			// file1
			// 
			this->file1->FormattingEnabled = true;
			this->file1->ItemHeight = 20;
			this->file1->Location = System::Drawing::Point(351, 194);
			this->file1->Name = L"file1";
			this->file1->Size = System::Drawing::Size(177, 84);
			this->file1->TabIndex = 8;
			// 
			// file2
			// 
			this->file2->FormattingEnabled = true;
			this->file2->ItemHeight = 20;
			this->file2->Location = System::Drawing::Point(351, 324);
			this->file2->Name = L"file2";
			this->file2->Size = System::Drawing::Size(177, 84);
			this->file2->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(347, 160);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(65, 20);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Файл 1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(347, 291);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(65, 20);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Файл 2";
			// 
			// file1_show
			// 
			this->file1_show->Location = System::Drawing::Point(26, 312);
			this->file1_show->Name = L"file1_show";
			this->file1_show->Size = System::Drawing::Size(181, 46);
			this->file1_show->TabIndex = 12;
			this->file1_show->Text = L"Показати файл 1";
			this->file1_show->UseVisualStyleBackColor = true;
			this->file1_show->Click += gcnew System::EventHandler(this, &MyForm::file1_show_Click);
			// 
			// file2_show
			// 
			this->file2_show->Location = System::Drawing::Point(30, 378);
			this->file2_show->Name = L"file2_show";
			this->file2_show->Size = System::Drawing::Size(308, 46);
			this->file2_show->TabIndex = 13;
			this->file2_show->Text = L"Показати файл 2";
			this->file2_show->UseVisualStyleBackColor = true;
			this->file2_show->Click += gcnew System::EventHandler(this, &MyForm::file2_show_Click);
			// 
			// input
			// 
			this->input->FormattingEnabled = true;
			this->input->ItemHeight = 20;
			this->input->Location = System::Drawing::Point(351, 55);
			this->input->Name = L"input";
			this->input->Size = System::Drawing::Size(177, 84);
			this->input->TabIndex = 14;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(351, 25);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(119, 20);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Введені числа";
			// 
			// file1_clear
			// 
			this->file1_clear->Location = System::Drawing::Point(213, 312);
			this->file1_clear->Name = L"file1_clear";
			this->file1_clear->Size = System::Drawing::Size(125, 46);
			this->file1_clear->TabIndex = 16;
			this->file1_clear->Text = L"Очистити все";
			this->file1_clear->UseVisualStyleBackColor = true;
			this->file1_clear->Click += gcnew System::EventHandler(this, &MyForm::file1_clear_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(579, 467);
			this->Controls->Add(this->file1_clear);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->input);
			this->Controls->Add(this->file2_show);
			this->Controls->Add(this->file1_show);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->file2);
			this->Controls->Add(this->file1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->multiple);
			this->Controls->Add(this->b_t);
			this->Controls->Add(this->a_t);
			this->Controls->Add(this->number);
			this->Controls->Add(this->add_b);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			bool dotEntereda = false;
			bool dotEnterednum = false;
			bool minusEntereda = false;
			bool minusEnterednum = false;
			bool dotEnteredb = false;
			bool minusEnteredb = false;
			bool dotEnteredm = false;
			bool minusEnteredm = false;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ nn = number->Text;
		string num = marshal_as<std::string>(nn);
		try {
			if (number->Text == "") {
				throw "Please input coordinates!";
			}
			if (num.find("-") != -1 && num.find("-") > 0) {
				number->Text = "";
				throw "Minus in the wrong place!";
				
			}
			if (num.find(",") != -1 && num.find(",") == 0) {
				number->Text = "";
				throw "Decimal point in the wrong place!";

			}
			
				double n = Convert::ToDouble(nn);
				file->AddNumber(n);
				input->Items->Add(nn);
				number->Text = "";
			
		}
		catch (const char* s) {
			string ss = s;
			cout << ss << endl;
			String^ sss = marshal_as<String^>(ss);
			MessageBox::Show(sss);

		}
		dotEntereda = false;
		dotEnterednum = false;
		minusEntereda = false;
		minusEnterednum = false;
		dotEnteredb = false;
		minusEnteredb = false;
		dotEnteredm = false;
		minusEnteredm = false;


	}
	private: System::Void file1_show_Click(System::Object^ sender, System::EventArgs^ e) {
		file1->Items->Clear();
		file->ReadFile();
		ifstream file11;
		file11.open(file->GetName(), std::ios::binary);
		if (!file11.is_open()) {
			MessageBox::Show("Can't open file");
			return;
		}

		double n;
		while (file11.read(reinterpret_cast<char*>(&n), sizeof(double))) {
			file1->Items->Add(n);
		}

		file11.close();
		

	}
	private: System::Void file2_show_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (a_t->Text == "" || b_t->Text == "" || multiple->Text == ""|| input->Items->Count==0) {
				throw 1;
			}
			String^ aa = a_t->Text;
			string aaa = marshal_as<std::string>(aa);
			String^ bb = b_t->Text;
			string bbb = marshal_as<std::string>(bb);
			String^ mm = multiple->Text;
			string mmm = marshal_as<std::string>(mm);
			
				if (aaa.find("-") != -1 && aaa.find("-") > 0) {
					a_t->Text = "";
					throw "Minus in the wrong place!";

				}

				if ( bbb.find("-") != -1 && bbb.find("-") > 0 ) {
					b_t->Text = "";
					throw "Minus in the wrong place!";

				}

				if ( mmm.find("-") != -1 && mmm.find("-") > 0) {
					multiple ->Text = "";
					throw "Minus in the wrong place!";

				}
				if (aaa.find(",") != -1 && aaa.find(",") == 0) {
					a_t->Text = "";
					throw "Decimal point in the wrong place!";

				}
				if (bbb.find(",") != -1 && bbb.find(",") == 0) {
					b_t->Text = "";
					throw "Decimal point in the wrong place!";

				}
				if (mmm.find(",") != -1 && mmm.find(",") == 0) {
					multiple->Text = "";
					throw "Decimal point in the wrong place!";

				}

			
			file2->Items->Clear();

			
			double a = Convert::ToDouble(aa);		
			double b = Convert::ToDouble(bb);
			double m = Convert::ToDouble(mm);
			//try {
				file->WriteToAnother(a, b, m, newfile);

				ifstream file11;
				file11.open(newfile->GetName(), std::ios::binary);
				if (!file11.is_open()) {
					MessageBox::Show("Can't open file");
					return;
				}

				double n;
				while (file11.read(reinterpret_cast<char*>(&n), sizeof(double))) {
					file2->Items->Add(n);
				}

				file11.close();
			//}
		/*
			catch (const char* s) {
				string ss = s;
				cout << ss << endl;
				String^ sss = marshal_as<String^>(ss);
				MessageBox::Show(sss);

			}
			*/	
			
		}
		
		catch (int i) {
			MessageBox::Show("Fill all filds!");
		}
		catch (const char* s) {
			string ss = s;
			cout << ss << endl;
			String^ sss = marshal_as<String^>(ss);
			MessageBox::Show(sss);

		}
		dotEntereda = false;
		dotEnterednum = false;
		minusEntereda = false;
		minusEnterednum = false;
		dotEnteredb = false;
		minusEnteredb = false;
		dotEnteredm = false;
		minusEnteredm = false;

	}
	private: System::Void file1_clear_Click(System::Object^ sender, System::EventArgs^ e) {
		file1->Items->Clear();
		a_t->Text = "";
		b_t->Text = "";
		multiple->Text = "";
		file->Clear_File();
		file2->Items->Clear();
		input->Items->Clear();

	}
private: System::Void number_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != '-' && e->KeyChar != '\b') {
		MessageBox::Show("Please enter only numbers.");
		e->Handled = true;
	}
	else if (e->KeyChar == ',' && dotEnterednum || e->KeyChar == '-' && minusEnterednum) {
		if (e->KeyChar == ',') {
			MessageBox::Show("You have already entered a decimal point.");
		}
		if (e->KeyChar == '-') {
			MessageBox::Show("You have already entered  minus.");
		}
		e->Handled = true;
	}
	else {
		if (e->KeyChar == ',') {
			dotEnterednum = (e->KeyChar == ',') ? true : dotEnterednum;
		}
		if (e->KeyChar == '-') {
			minusEnterednum = (e->KeyChar == '-') ? true : minusEnterednum;
		}


	}
}

private: System::Void a_t_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != '-' && e->KeyChar != '\b') {
		MessageBox::Show("Please enter only numbers.");
		e->Handled = true;
	}
	else if (e->KeyChar == ',' && dotEntereda || e->KeyChar == '-' && minusEntereda) {
		if (e->KeyChar == ',') {
			MessageBox::Show("You have already entered a decimal point.");
		}
		if (e->KeyChar == '-') {
			MessageBox::Show("You have already entered  minus.");
		}
		e->Handled = true;
	}
	else {
		if (e->KeyChar == ',') {
			dotEntereda = (e->KeyChar == ',') ? true : dotEntereda;
		}
		if (e->KeyChar == '-') {
			minusEntereda = (e->KeyChar == '-') ? true : minusEntereda;
		}


	}
}

private: System::Void b_t_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != '-' && e->KeyChar != '\b') {
		MessageBox::Show("Please enter only numbers.");
		e->Handled = true;
	}
	else if (e->KeyChar == ',' && dotEnteredb || e->KeyChar == '-' && minusEnteredb) {
		if (e->KeyChar == ',') {
			MessageBox::Show("You have already entered a decimal point.");
		}
		if (e->KeyChar == '-') {
			MessageBox::Show("You have already entered  minus.");
		}
		e->Handled = true;
	}
	else {
		if (e->KeyChar == ',') {
			dotEnteredb = (e->KeyChar == ',') ? true : dotEnteredb;
		}
		if (e->KeyChar == '-') {
			minusEnteredb = (e->KeyChar == '-') ? true : minusEnteredb;
		}


	}
}

private: System::Void multiple_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != '-' && e->KeyChar != '\b') {
		MessageBox::Show("Please enter only numbers.");
		e->Handled = true;
	}
	else if (e->KeyChar == ',' && dotEnteredm || e->KeyChar == '-' && minusEnteredm) {
		if (e->KeyChar == ',') {
			MessageBox::Show("You have already entered a decimal point.");
		}
		if (e->KeyChar == '-') {
			MessageBox::Show("You have already entered  minus.");
		}
		e->Handled = true;
	}
	else {
		if (e->KeyChar == ',') {
			dotEnteredm = (e->KeyChar == ',') ? true : dotEnteredm;
		}
		if (e->KeyChar == '-') {
			minusEnteredm = (e->KeyChar == '-') ? true : minusEnteredm;
		}


	}
}
};
}
