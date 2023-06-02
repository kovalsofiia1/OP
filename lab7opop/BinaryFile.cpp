#include"BinaryFile.h"

BinaryFile::BinaryFile(string name) {
    if (name.find(".dat") == -1) {
        filename = name + ".dat";
    }

    file.open(filename, ios::out | ios::binary);
    file.close();
}

void BinaryFile::SBinaryFile(string name) {
    if (name.find(".dat") == -1) {
        filename = name + ".dat";
    }

    file.open(filename, ios::out | ios::binary);
    file.close();
}
void BinaryFile::Clear_File() {
    file.open(filename, ios::out | ios::binary);
    file.close();
}

void BinaryFile::AddNumber(double n) {
    file.open(filename, ios::app | ios::binary);
    if (!file.is_open()) {
        cout << "Can`t open file" << endl;
        return;
    }
    file.write(reinterpret_cast<char*>(&n), sizeof(double));
    file.close();
}
void BinaryFile::ReadFile() {
    file.open(filename, ios::binary | ios::in);
    if (!file.is_open()) {
        cout << "can`t open file" << endl;
        return;
    }
    double n;
    while (file.read(reinterpret_cast<char*>(&n), sizeof(double))) {
        cout << n << "   ";
    }
    cout << endl;
    file.close();
}
string BinaryFile::GetName() {
    return filename;
}

void BinaryFile::WriteToAnother(double a, double b, double t, BinaryFile* f) {
    file.open(filename, ios::binary | ios::in);
    if (!file.is_open()) {
        cout << "can`t open file" << endl;
        return;
    }
    f->file.open(f->GetName(), ios::binary | ios::out);
    if (!f->file.is_open()) {
        cout << "can`t open new file" << endl;
        return;
    }

    double n;
    while (file.read(reinterpret_cast<char*>(&n), sizeof(double))) {

        if (n >= a && n <= b) {
            if (n * t > MAX) {
                throw "OVERFLOW";
            }
            else if (n * t < MIN) {
                throw "UNDERFLOW";
            }
            double nn = n * t;
            f->file.write(reinterpret_cast<char*>(&(nn)), sizeof(double));

        }

    }
    file.close();
    f->file.close();
}

