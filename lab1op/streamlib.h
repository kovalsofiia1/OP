//
// Created by gr on 08.03.2023.
//

#ifndef LAB1OP_STREAMLIB_H
#define LAB1OP_STREAMLIB_H

#endif //LAB1OP_STREAMLIB_H
#include <iostream>
#include<fstream>
#include<string>

using namespace std;
int fillchoice();
int fillyourself(ofstream& f,string name);
int fillautomatically(ofstream& f, string name);
string oddline(string line);
string evenline(string line);
void createFile(ofstream& f,string name);
int printFile(ifstream& f, string name);
void appendfile(ofstream& ff,ifstream& f, string name);
int changeFile(ofstream& f,ifstream& ff,string name);