#include<iostream>
#include<fstream>
#include<cstring>
#include"mylibrary.h"
using namespace std;

struct Calls{
    char phone_n[12];
    char start[6];
    char end[6];
};
struct newCalls{
    Calls call;
    float prize;
    int hours;
    int minutes;
};

void create(string name){
    ofstream f(name, ios::binary);
    f.close();
}
int check_if_open(fstream& f,string name){
    if(!f.is_open()){
        cout<<"Can't open file!"<<endl;
        return 1;
    }
}
int fillchoice(){
    int choice;
    do {
        cout<<"To input information PRESS 1, to creat automatically PRESS 2"<<endl;
        cin >> choice;
        cin.ignore();
    }while(choice!=1 && choice!=2);
    return choice;
}
string get_filename(){
    string name;
    cout<<"Enter the name of the file without extension: ";
    cin>>name;
    name=name+".ban";
    cin.ignore();
    return name;
}
void print(string name){
    fstream f;
    f.open(name,ios::binary|ios::in);
    check_if_open(f,name);
    cout<<"--Phone number---Start----End "<<endl;
    Calls call1[1];
    while(f.read(reinterpret_cast<char*>(call1),sizeof(Calls))){
        cout <<"|| "<< call1[0].phone_n << " || " << call1[0].start <<" || "<< call1[0].end <<endl;
    }
    f.close();
}
void print_prize(string name){
    fstream f;
    cout<<"-Phone number---Start-----End-----Time-----Prize--"<<endl;
    f.open(name,ios::binary|ios::in);
    check_if_open(f,name);
    newCalls call1[1];
    while(f.read(reinterpret_cast<char*>(call1),sizeof(newCalls))){
        cout <<"|| "<< call1[0].call.phone_n <<" || " << call1[0].call.start <<" || "<<call1[0].call.end;
        if(call1[0].hours<10) cout << " || "<<"0"<<call1[0].hours;
        else cout << " || "<<call1[0].hours;
        if(call1[0].minutes<10) cout<< ":"<<"0"<<call1[0].minutes<<" || "<<call1[0].prize<<" hrn."<<endl;
        else cout<< ":"<<call1[0].minutes<<" || "<<call1[0].prize<<" hrn."<<endl;
    }
    f.close();
}
void fillauto(fstream& f,string name){
    Calls call[6]= {
            {"0507237372", "07:30", "09:35"},
            {"0674346679", "13:15", "13:27"},
            {"0976435673", "02:30", "02:31"},
            {"0956678543", "10:45", "11:03"},
            {"0664587999","19:57", "20:13"}
    };

    f.open(name,ios::binary|ios::out);
    check_if_open(f,name);
    f.write(reinterpret_cast<char *>(call),  5*sizeof(Calls));
    f.close();
}
void fill_you(fstream& f,string name){
    struct Calls c[1];
    int error=0;
    int h,m,h1,m1;
    char choise;
    do {error=0;
        do {
            error = 0;
            cout << "Enter phone number (format: 099*******): ";
            cin >> c[0].phone_n;
            cin.ignore();
            cout << endl;
            if (strlen(c[0].phone_n) != 10 && c[0].phone_n[0] != 30) {
                cout << "Wrong input! Number contains 10 numbers and starts with 0" << endl;
                error = 1;
            }
        } while (error);
        do {
            error = 0;
            cout << "Enter the start time (format HH:MM): ";
            cin >> c[0].start;
            cin.ignore();
            cout << endl;
            char hour[3], min[3];

            hour[0] = c[0].start[0];
            hour[1] = c[0].start[1];
            hour[2] = '\0';
            min[0] = c[0].start[3];
            min[1] = c[0].start[4];
            min[2] = '\0';
            //cout<<hour<<" "<<min<<endl;
            h = atoi(hour);
            m = atoi(min);
            //cout<<h<<" "<<m<<endl;
            if (strlen(c[0].start) != 5 || c[0].start[2] != 58) {
                cout << "Wrong format!" << endl;
                error = 1;
            } else if ((h < 0 || h > 23) || (m < 0 || m > 59)) {
                cout << "Hour was entered incorrectly!" << endl;
                error = 1;
            }
        } while (error);
        do {
            error = 0;
            cout << "Enter the end time (format HH:MM): ";
            cin >> c[0].end;
            cin.ignore();
            cout << endl;
            char hour[3], min[3];

            hour[0] = c[0].end[0];
            hour[1] = c[0].end[1];
            hour[2] = '\0';
            min[0] = c[0].end[3];
            min[1] = c[0].end[4];
            min[2] = '\0';
            //cout<<hour<<" "<<min<<endl;
            h1 = atoi(hour);
            m1 = atoi(min);
            //cout<<h1<<" "<<m1<<endl;
            if (strlen(c[0].end) != 5 || c[0].end[2] != 58) {
                cout << "Wrong format!" << endl;
                error = 1;
            } else if ((h1 < 0 || h1 > 23) || (m1 < 0 || m1 > 59)) {
                cout << "Hour was entered incorrectly!" << endl;
                error = 1;
            } else if (h1 < h || (h1==h && m1 <= m)) {
                cout << "This end time can't be possible!" << endl;
                error = 1;
            }
        } while (error);
        //cout << c.phone_n << " " << c.start <<" "<< c.end <<endl;
        f.open(name,ios::binary|ios::app);
        check_if_open(f,name);
        f.write(reinterpret_cast<char*>(c),  sizeof(Calls));
        f.close();
        cout<<"Do you want to enter another phone call? Press * if no. "<<endl;
        choise=getchar();
    }while(choise!='*');

}
void append_file( string name){
    fstream f;
    char choice;
    int i=0;
    cout << "\nDo you want to add data to current file? Press * if no.";
    choice=getchar();
    cin.ignore();
    if (choice !='*') {
        i++;
        fill_you(f,name);
    }
    if(i>0) {
        cout << "\tAppended file:" << endl;
        print(name);
    }
}
void fill_file(string name)
{
    cout<<"Do you want to input information into the file or automatically create file?"<<endl;
    fstream f;
    int choice=fillchoice();
    if(choice==1){
        fill_you(f,name);//введення даних самостійно
        cout<<"Created file: "<<endl;
        print(name);
    }
    else {
        fillauto(f,name);//заповнення файла автоматично
        cout<<"Created file: "<<endl;
        print(name);
        append_file(name);
    }
}
void count_prize(string name){
    fstream temp,f;

    string temp1="temp.ban";
    f.open(name,ios::binary|ios::in);
    check_if_open(f,name);
    temp.open(temp1,ios::binary|ios::out);
    check_if_open(temp,temp1);
    Calls call1[1];
    newCalls call2[1];
    char hour[3], min[3], hour1[3], min1[3];
    int h,m,h1,m1;
    while(f.read(reinterpret_cast<char*>(call1),sizeof(Calls))){

        strcpy(call2[0].call.phone_n,call1[0].phone_n);
        strcpy(call2[0].call.start,call1[0].start);
        strcpy(call2[0].call.end,call1[0].end);

        hour[0] = call1[0].start[0]; hour[1] = call1[0].start[1]; hour[2] = '\0';
        min[0] = call1[0].start[3]; min[1] = call1[0].start[4]; min[2] = '\0';
        h = atoi(hour);
        m = atoi(min);

        hour1[0] = call1[0].end[0]; hour1[1] = call1[0].end[1]; hour1[2] = '\0';
        min1[0] = call1[0].end[3]; min1[1] = call1[0].end[4]; min1[2] = '\0';
        h1 = atoi(hour1);
        m1 = atoi(min1);

        if(h1-h==0){
            call2[0].hours=0;
            call2[0].minutes=m1-m;
            if(h>=9 && h<20){
                call2[0].prize=1.5*call2[0].minutes;
            }
            else{
                call2[0].prize=0.9*call2[0].minutes;
            }
        }
        else if(h<9 && h1>=9){
            int hv_do=(9-h)*60 -m;
            int hv_pisla=(h1-9)*60 +m1;
            call2[0].prize=0.9*hv_do + 1.5*hv_pisla;
            call2[0].minutes= hv_do+hv_pisla;
            call2[0].hours= call2[0].minutes/60;
            call2[0].minutes=(call2[0].minutes%60);
        }
        else if(h<20 && h1>=20){
            int hv_do=(20-h)*60 -m;
            int hv_pisla=(h1-20)*60 +m1;
            call2[0].prize=1.5*hv_do + 0.9*hv_pisla;
            call2[0].minutes= hv_do+hv_pisla;
            call2[0].hours= call2[0].minutes/60;
            call2[0].minutes=(call2[0].minutes%60);
        }
        else if((h>=9 && h1<20) || (h>=20 && h1<9)){
            call2[0].minutes= (h1-h)*60 -m +m1;
            if(h>=9 && h<20 && h1>=9 && h1<20) {call2[0].prize=1.5*call2[0].minutes;}
            else {call2[0].prize=0.9*call2[0].minutes;}
            call2[0].hours= call2[0].minutes/60;
            call2[0].minutes=(call2[0].minutes%60);
        }
        temp.write(reinterpret_cast<char*>(call2),sizeof(newCalls));
    }
    temp.close();
    f.close();
    remove(name.c_str());//видалити початковий файл
    rename(temp1.c_str(),name.c_str());//перейменувати тимчасовий файл
    cout<<"\nFile with length of calls and their prize:\n";
    print_prize(name);


}
void delete_short_calls(string name){
    fstream temp,f;
    string temp1="temp.ban";
    f.open(name,ios::binary|ios::in);
    check_if_open(f,name);
    temp.open(temp1,ios::binary|ios::out);
    check_if_open(temp,temp1);
    newCalls call2[1];
    while(f.read(reinterpret_cast<char*>(call2),sizeof(newCalls))) {
        if(call2[0].hours>=0 && call2[0].minutes>=3){
            temp.write(reinterpret_cast<char*>(call2),sizeof(newCalls));
        }

    }
    temp.close();
    f.close();
    remove(name.c_str());//видалити початковий файл
    rename(temp1.c_str(),name.c_str());//перейменувати тимчасовий файл
    cout<<"\nFile with calls no shorten then 3 minutes:\n";
    print_prize(name);
}
