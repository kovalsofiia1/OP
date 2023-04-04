
#ifndef LAB3OP_CLASSLIB_H
#define LAB3OP_CLASSLIB_H

#endif //LAB3OP_CLASSLIB_H
#include<iostream>
#include<string>
#define size 20
using namespace std;
class Address{
protected:
    string country;
    string city;
    string street;
    int street_number;
public:
    void SetCountry(string ,string,string , int);
    string get_full_address();
};
class User{
private:
    string name;
    string surname;
    string fathers_name;
    Address address;
    string phone_number;
public:
    void SetValues(string,string,string,string);
    void SetAddress(string, string,string,int);
    string GetName(){
        return name;
    };
    string GetSurname(){
        return surname;
    };
    string GetFathersName(){
        return fathers_name;
    }
    string GetAddress(){
        string ad=address.get_full_address();
        return ad;
    };
    string GetNumber(){
        return phone_number;
    };
};
string get_input(string);
string get_number();
int get_str_num();
int make_choice(string);
string generate_number();
void fill_random(User *, int &);
void fill_array(User *, int &);
void fill(User *,int &);
void find_number(User* ,int&,int* );
void print(User* ,int );
void print_result(User *,int *);
