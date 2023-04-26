

#ifndef LAB5OP_L5LIB_H
#define LAB5OP_L5LIB_H
#include <iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>      // std::setw

#define random ((rand() % 2 == 0 ? 1 : -1) * (rand()%100+1));
#define m 2
#define n 2
using namespace std;


//bx+c=0
//ax^2+bx+c=0
class TEquation{
protected:
    float a,b,c;
    float x1,x2;
public:
    void Set(float _a,float _b,float _c){
        a=_a;b=_b;c=_c;
    }
    float get_a(){
        return a;
    }
    float get_b(){
        return b;
    }
    float get_c(){
        return c;
    }
    float get_x1(){
        return x1;
    }
    float get_x2(){
        return x2;
    }

    virtual void result()=0;
    virtual void check()=0;
    virtual void show()=0;
};
class LinearEquation:public TEquation{
public:
    LinearEquation(float _b,float _c){Set(0,_b,_c);x2=0;}
    void result() override;
    void check()override;
    void show() override ;
};

class QuadraticEquation:public TEquation{
    //float a,b,c;
    //float x1,x2;
public:
    QuadraticEquation(float _b,float _c,float _a){Set(_a,_b,_c);}
    void result() override;
    void check() override ;
    void show() override;
};
void fill_equations(TEquation* (&equation)[n+m]);
void solve_equations(TEquation* (&equation)[n+m]);
void find_sum1(TEquation* (&equation)[n+m]);
void is_root(TEquation* (&equation)[n+m],int num,float r);
void get_input(int &num,float &r);
#endif //LAB5OP_L5LIB_H
