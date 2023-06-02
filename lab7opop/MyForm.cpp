#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Globalization;
using namespace System::Threading;

[STAThreadAttribute]

int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	lab7opop::MyForm form;
	Application::Run(% form);
}

System::Void lab7opop::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ nn = number->Text;
	string num = marshal_as<std::string>(nn);
	try {
		if (number->Text == "") {
			throw "Please input coordinates!";
		}
		int pos = num.find(",");
		if (pos != -1 && num.find(",", pos + 1) != -1) {
			number->Text = "";
			throw "Decimal point entered more than once!";
		}
		pos = num.find("-");
		if (pos != -1 && num.find("-", pos + 1) != -1) {
			number->Text = "";
			throw "Minus entered more than once!";
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


}


System::Void lab7opop::MyForm::file1_show_Click(System::Object^ sender, System::EventArgs^ e) {
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
System::Void lab7opop::MyForm::file2_show_Click(System::Object^ sender, System::EventArgs^ e) {
	string a = marshal_as<std::string>(a_t->Text);
	string b = marshal_as<std::string>(b_t->Text);
	string m = marshal_as<std::string>(multiple->Text);
	try {
		if (a_t->Text == "" || b_t->Text == "" || multiple->Text == "" || input->Items->Count == 0) {
			throw 1;
		}
		int pos = a.find(",");
		if (pos != -1 && a.find(",", pos + 1) != -1) {
			a_t->Text = "";
			throw "Decimal point in a entered more than once!";
		}
		pos = b.find(",");
		if (pos != -1 && b.find(",", pos + 1) != -1) {
			b_t->Text = "";
			throw "Decimal point in b entered more than once!";
		}
		pos = m.find(",");
		if (pos != -1 && m.find(",", pos + 1) != -1) {
			multiple->Text = "";
			throw "Decimal point entered more than once!";
		}
		pos = a.find("-");
		if (pos != -1 && a.find("-", pos + 1) != -1) {
			a_t->Text = "";
			throw "Minus in a entered more than once!";
		}
		pos = b.find("-");
		if (pos != -1 && b.find("-", pos + 1) != -1) {
			b_t->Text = "";
			throw "Minus in b entered more than once!";
		}
		pos = m.find("-");
		if (pos != -1 && m.find("-", pos + 1) != -1) {
			multiple->Text = "";
			throw "Minus entered more than once!";
		}
		if (a.find("-") != -1 && a.find("-") > 0) {

			a_t->Text = "";

			throw "Minus in a in the wrong place!";
		}
		if (b.find("-") != -1 && b.find("-") > 0) {

			b_t->Text = "";
			throw "Minus in b in the wrong place!";
		}
		if (m.find("-") != -1 && m.find("-") > 0) {

			multiple->Text = "";
			throw "Minus in the wrong place!";
		}
		if (a.find(",") != -1 && a.find(",") == 0) {

			a_t->Text = "";

			throw "Decimal point in a in the wrong place!";
		}
		if (b.find(",") != -1 && b.find(",") == 0) {
			b_t->Text = "";
			throw "Decimal point in b in the wrong place!";
		}
		if (m.find(",") != -1 && m.find(",") == 0) {
			multiple->Text = "";
			throw "Decimal point in the wrong place!";
		}
		String^ aa = a_t->Text;
		string aaa = marshal_as<std::string>(aa);
		String^ bb = b_t->Text;
		string bbb = marshal_as<std::string>(bb);
		String^ mm = multiple->Text;
		string mmm = marshal_as<std::string>(mm);



		file2->Items->Clear();


		double a = Convert::ToDouble(aa);
		double b = Convert::ToDouble(bb);
		double m = Convert::ToDouble(mm);
		if (a > b) {
			a_t->Text = "";
			b_t->Text = "";
			throw "Imposible diapazon!";
		}
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


}

System::Void lab7opop::MyForm::file1_clear_Click(System::Object^ sender, System::EventArgs^ e) {

		file1->Items->Clear();
		a_t->Text = "";
		b_t->Text = "";
		multiple->Text = "";
		file->Clear_File();
		file2->Items->Clear();
		input->Items->Clear();

	}

System::Void lab7opop::MyForm::number_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != '-' && e->KeyChar != '\b') {
		MessageBox::Show("Please enter only numbers.");
		e->Handled = true;
	}

}

System::Void lab7opop::MyForm::a_t_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != '-' && e->KeyChar != '\b') {
		MessageBox::Show("Please enter only numbers.");
		e->Handled = true;
	}

}
 System::Void lab7opop::MyForm::b_t_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != '-' && e->KeyChar != '\b') {
		MessageBox::Show("Please enter only numbers.");
		e->Handled = true;
	}

}

 System::Void lab7opop::MyForm::multiple_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (!Char::IsDigit(e->KeyChar) && e->KeyChar != ',' && e->KeyChar != '-' && e->KeyChar != '\b') {
		MessageBox::Show("Please enter only numbers.");
		e->Handled = true;
	}

}

