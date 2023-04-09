#include "classlib.h"
bool isOctal(int n)
{
    while (n)
    {
        if ((n % 10) >= 8)
            return false;
        else
            n = n / 10;
    }
    return true;
}
int OctalToDecimal(int num8)
{
    int num10 = 0, i = 0, rem;
    while (num8 != 0)
    {
        rem = num8 % 10;
        num8 /= 10;
        num10 += rem * pow(8, i);
        ++i;
    }
    return num10;
}
int DecimalToOctal(int num10)
{
    int rem, i = 1, num8 = 0;
    while (num10 != 0)
    {
        rem = num10 % 8;
        num10 /= 8;
        num8 += rem * i;
        i *= 10;
    }
    return num8;
}
Numeral_8 getinput(string text){
    int n,error;
    bool check;

    do {
        cout << "Enter "<<text<<" in octal system: "<<endl;
        //cin >> n;
        do {error=0;
            cin >> n;
            if(!cin){
                cout << "That was no integer! Please enter an integer: ";
                cin.clear();
                cin.ignore();
                error=1;
            }
        }while(error);
        check = isOctal(n);
        if(check==0) cout<<"The number you entered is not in octal system! Try again!"<<endl;
    }while(check==0);
    Numeral_8 temp(n);//конструктор з параметрами
    return temp;
}
Numeral_8 Numeral_8::operator++(){
    number=OctalToDecimal(number);
    ++number;
    number=DecimalToOctal(number);
    return *this;
}
Numeral_8 Numeral_8::operator+=(int num){
    number=OctalToDecimal(number);
    number += num;
    number=DecimalToOctal(number);

    return *this;
}
Numeral_8 Numeral_8::operator+(Numeral_8 obj){
    Numeral_8 temp(0);
    int t1=OctalToDecimal(number);
    int t2=OctalToDecimal(obj.number);
    temp.number=t1+t2;
    temp.number=DecimalToOctal(temp.number);
    return temp;
}
int increment(){
    int num,error;
    cout << "\tEnter the number you want to add to N2: " << endl;
    do {error=0;
        cin >> num;
        if(!cin){
            cout << "That was no integer! Please enter an integer: ";
            cin.clear();
            cin.ignore();
            error=1;
        }
    }while(error);
    return num;
}
void current(Numeral_8 n1, Numeral_8 n2){
    cout<<"\n\tCurrent vallues:"<<endl;
    cout<<"N1 = "<<n1.getN()<<";"<<endl;
    cout<<"N2 = "<<n2.getN()<<";"<<endl;
    cout<<"\nN1 will be incremented by 1;"<<endl;
    cout<<"N2 will be incremented by users input ->"<<endl;
}
void result(Numeral_8 n1, Numeral_8 n2,int k,Numeral_8 n3){
    cout<<"\n\tResults:"<<endl;
    cout<<"++N1 = "<<n1.getN()<<";"<<endl;
    cout<<"N2 + "<<k<<" = "<<n2.getN()<<";"<<endl;
    cout<<"N3 = N1 + N2 = "<<n3.getN()<<";"<<endl;
    cout<<"N3 in decimal form: "<<OctalToDecimal(n3.getN())<<endl;

}