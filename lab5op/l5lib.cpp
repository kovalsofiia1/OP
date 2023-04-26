#include "l5lib.h"


void LinearEquation::result() {
    x1=(-c)/b;
}
void LinearEquation::check(){
    cout<<"\tCheck:"<<endl;
    cout<<int(b)<<"*"<<x1<<"+"<<int(c)<<" =0   -->  ";
    cout<<b*x1<<"+"<<c<<" =0  -->  ";
    cout<<b*x1+c<<" =0 "<<endl;
}
void LinearEquation::show() {
    cout<<setw(4)<<int(b)<<" * x + "<<setw(4)<<int(c)<<" = 0;"<<"  ";
}

void QuadraticEquation:: result() {
    float D;
    D=b*b-4*a*c;
    if(D<0){
        cout<<" -- >  The equation dosn`t have solution"<<endl;
        x1=x2=-100000;
    }
    else{
        x1=(-b-sqrt(D))/(2*a);
        x2=(-b+sqrt(D))/(2*a);

    }
}
void QuadraticEquation::check() {
    cout<<"\tCheck:"<<endl;
    cout<<setw(4)<<int(a)<<" * "<<setw(8)<<x1<<" ^2 + "<<setw(4)<<int(b)<<" * "<<setw(8)<<x1<<" + "<<setw(4)<<int(c)<<" =0  -->  ";
    cout<<setw(10)<<a*x1*x1<<" + "<<setw(8)<<b*x1<<" + "<<setw(4)<<int(c)<<" = 0  -->  " ;
    cout<<a*x1*x1+b*x1+c<<" =0 "<<endl;

    cout<<setw(4)<<int(a)<<" * "<<setw(8)<<x2<<" ^2 + "<<setw(4)<<int(b)<<" * "<<setw(8)<<x2<<" + "<<setw(4)<<int(c)<<" =0  -->  ";
    cout<<setw(10)<<a*x2*x2<<" + "<<setw(8)<<b*x2<<" + "<<setw(4)<<int(c)<<" = 0  -->  ";
    cout<<a*x2*x2+b*x2+c<<" =0 "<<endl;

}
void QuadraticEquation::show() {
    cout<<setw(4)<<int(a)<<" * x^2 + "<<setw(4)<<int(b)<<" * x + "<<setw(4)<<int(c)<<" = 0"<<"  ";
}


void fill_equations(TEquation* (&equation)[n+m]){
    srand (time(NULL));
    for(int i=0; i<n;i++){
        float b_,c_;
        b_= random;
        c_= random;
        equation[i]= new LinearEquation(b_,c_);
    }
    for(int i=n; i<m+n;i++){
        float b_,c_,a_;
        a_= random;
        b_= random;
        c_= random;
        equation[i]= new QuadraticEquation(b_,c_,a_);
    }
}

void solve_equations(TEquation* (&equation)[n+m]){
    cout<<"\t\tTask 1"<<endl;
    for(int i=0;i<n+m;i++){
        if(i==0) cout<<"\n\tLinear equations:"<<endl;
        else if(i==n) {cout<<"----------------------------------------------------------------------------------------------------"<<endl;
            cout<<"\n\tQuadratic equations:"<<endl;}
        cout<<"----------------------------------------------------------------------------------------------------"<<endl;
        cout<<i+1<<") ";
        equation[i]->show();
        equation[i]->result();
        if(i<n){
            cout<<" -->  Result: x = "<<setw(7)<<fixed<<setprecision(3)<<equation[i]->get_x1()<<endl;
            equation[i]->check();
        }else{
            if(equation[i]->get_x1()!=-100000) {
                cout << " -- >  Result: x1 = " << setw(7)<<fixed<<setprecision(3) <<equation[i]->get_x1()
                     <<" ; x2 = " << setw(7)<<fixed<<setprecision(3)
                     <<equation[i]->get_x2()<< " ;" << endl;
                equation[i]->check();
            }
        }

        //cout<<res[0]<<endl;

    }
}

void find_sum1(TEquation* (&equation)[n+m]) {
    float LinearSum = 0, QuadraticSum = 0;
    for (int i = 0; i < n + m; i++) {
        if (i < n) {
            //LinearSum+=res[i][0];
            LinearSum += equation[i]->get_x1();
        } else {
            if ((equation[i]->get_x1()) != (-100000)) {
                QuadraticSum += equation[i]->get_x1()+equation[i]->get_x2();
            }
        }
    }
    cout << "\n----------------------------------------------------------------------------------------------------"
         << endl;
    cout << "----------------------------------------------------------------------------------------------------"
         << endl;
    cout<<"\t\tTask 2"<<endl;
    cout << "\nThe sum of solutions to linear equations is " << LinearSum << endl;
    if(QuadraticSum==0){
        cout<<"All quadratic equations don`t have solutions so sum can`t be counted"<<endl;
    }else{
        cout << "The sum of solutions to quadratic equations is " << QuadraticSum << endl;

    }

    cout<<"\n----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
}

void is_root(TEquation* (&equation)[n+m],int num,float r){
    float k=0;
    cout<<endl;
    equation[num-1]->show();
    cout<<endl;
    if(num-1<n){

        cout<<"\tCheck:"<<endl;
        cout<<int(equation[num-1]->get_b())<<"*"<<r<<"+"<<int(equation[num-1]->get_c())<<" =0   -->  ";
        cout<<equation[num-1]->get_b()*r<<"+"<<equation[num-1]->get_c()<<" =0  -->  ";
        k=equation[num-1]->get_b()*r+equation[num-1]->get_c();
        cout<<k<<" =0 ?"<<endl;

    }
    else{
        cout<<"\tCheck:"<<endl;
        cout<<setw(4)<<int(equation[num-1]->get_a())<<" * "<<setw(8)<<r<<" ^2 + "<<setw(4)<<int(equation[num-1]->get_b())<<" * "<<setw(8)<<r<<" + "<<setw(4)<<int(equation[num-1]->get_c())<<" =0  -->  ";
        cout<<setw(10)<<equation[num-1]->get_a()*r*r<<" + "<<setw(8)<<equation[num-1]->get_b()*r<<" + "<<setw(4)<<int(equation[num-1]->get_c())<<" = 0  -->  " ;
        k=equation[num-1]->get_a()*r*r+equation[num-1]->get_b()*r+equation[num-1]->get_c();
        cout<<fixed<<setprecision(3)<<k<<" =0 ?"<<endl;
    }
    if(k>=0 && k<0.1){
        cout<<"\n"<<r<<" is a root of this equation."<<endl;
    }
    else{
        cout<<"\n"<<r<<" is not a root of this equation."<<endl;
    }
}

void get_input(int &num,float &r){
    cout<<"\t\tTask 3"<<endl;
    do {cout<<"Choose the number of equation you want to check the root for :";
        cin >> num;
        if(num<=0 || num>n+m){
            cout<<endl;
            cout<<"Number of equation that you entered doesn`t exist. It must be in range [1;"<<n+m<<"]. Try again!"<<endl;
            cout<<endl;
        }
    }while (num<=0 || num>n+m);
    cout<<endl;
    cout<<"Enter the root you want to check for equation No"<<num<<" : ";
    cin>>r;
}
