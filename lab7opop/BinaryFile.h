#pragma once
#include <iostream>
#include<fstream>
#include<cfloat>
using namespace std;

#define MAX 1000000
#define MIN -1000000

class BinaryFile {
    fstream file;
    string filename;

public:
    BinaryFile();
    BinaryFile(string name) {
        if (name.find(".dat") == -1) {
            filename = name + ".dat";
        }

        file.open(filename, ios::out | ios::binary);
        file.close();
    }
    void SBinaryFile(string name) {
        if (name.find(".dat") == -1) {
            filename = name + ".dat";
        }
        
        file.open(filename, ios::out | ios::binary);
        file.close();
    }
    void Clear_File() {
        file.open(filename, ios::out | ios::binary);
        file.close();
    }
    int GetFileSize() {
        file.seekg(0, ios::end);

        // Отримання поточної позиції, яка є довжиною файла
        streampos length = file.tellg();
        return length/sizeof(double);
    }
    void AddNumber(double n) {
        file.open(filename, ios::app | ios::binary);
        if (!file.is_open()) {
            cout << "Can`t open file" << endl;
            return;
        }
        file.write(reinterpret_cast<char*>(&n), sizeof(double));
        file.close();
    }
    void ReadFile() {
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
    string GetName() {
        return filename;
    }
    double ReadFile1(int i) {
        file.open(filename, ios::binary | ios::in);
        if (!file.is_open()) {
            cout << "can`t open file" << endl;
            
        }
        streampos position = i * sizeof(double);
        file.seekg(position);
        double n;
        file.read(reinterpret_cast<char*>(&n), sizeof(double));
        cout << n << endl;
        file.close();
        return n;
    }
    void WriteToAnother(double a, double b, double t, BinaryFile* f) {
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
   


};