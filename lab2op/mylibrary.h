
#ifndef LAB2OP_MYLIBRARY_H
#define LAB2OP_MYLIBRARY_H

#endif //LAB2OP_MYLIBRARY_H
#include<iostream>
#include<fstream>
#include<cstring>


using namespace std;

struct Calls;
struct newCalls;
void create(string name);
int check_if_open(fstream& f,string name);
int fillchoice();
string get_filename();
void print(string name);
void print_prize(string name);
void fillauto(fstream& f,string name);
void fill_you(fstream& f,string name);
void append_file( string name);
void fill_file(string name);
void count_prize(string name);
void delete_short_calls(string name);