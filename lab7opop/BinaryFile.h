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
    BinaryFile(string name);
    void SBinaryFile(string name);
    void Clear_File();
    void AddNumber(double n);
    void ReadFile();
    string GetName();

    void WriteToAnother(double a, double b, double t, BinaryFile* f);

};
