
#include "classlib.h"
int main() {
    char next;
    do {cout<<"\n----------------------------------------------"<<endl;
        Numeral_8 N1(getinput("N1"));//конструктор копіювання
        Numeral_8 N2(getinput("N2"));//конструктор копіювання
        Numeral_8 N3;//конструктор за замовчуванням
        current(N1, N2);
        ++N1;
        int b = increment();
        N2 += b;
        N3 = N1 + N2;
        result(N1, N2, b, N3);
        cout<<"Another exercise? Press ane key to continue; * - to end "<<endl;
        cin.ignore();
        next=getchar();
    }while(next!='*');
    return 0;
}
