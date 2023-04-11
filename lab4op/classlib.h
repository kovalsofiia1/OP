
#ifndef LAB4OP_CLASSLIB_H
#define LAB4OP_CLASSLIB_H



#include <iostream>
#include<math.h>
using namespace std;

class Numeral_8{
    int number;
public:
    Numeral_8(){
        number=0;
    }
    Numeral_8(int n){
        number=n;
    }
    Numeral_8(const Numeral_8 &obj):number(obj.number){}
    Numeral_8 operator++();
    Numeral_8 operator+=(int);
    Numeral_8 operator+(Numeral_8);
    int getN(){
        return number;
    }
    friend Numeral_8 getinput(string);
    friend int OctalToDecimal(int );
    friend int DecimalToOctal(int );
};

bool isOctal(int);
Numeral_8 getinput(string);
int OctalToDecimal(int);
int DecimalToOctal(int );
int increment();
void current(Numeral_8 , Numeral_8 );
void result(Numeral_8, Numeral_8 ,int ,Numeral_8 );

#endif //LAB4OP_CLASSLIB_H
