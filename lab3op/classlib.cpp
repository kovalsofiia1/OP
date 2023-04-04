
#include"classlib.h"
#define size 20
using namespace std;

void User::SetValues(string n,string s,string f,string num){
    name=n;
    surname=s;
    fathers_name=f;
    phone_number=num;
}
void Address::SetCountry(string c1,string c2,string s, int n){
    country=c1;
    city=c2;
    street=s;
    street_number=n;
}
string Address::get_full_address(){
    string full_address=country+", "+city+", "+street+" " +to_string(street_number);
    return full_address;
}
void User::SetAddress(string coun, string cit,string str,int str_n){
    address.SetCountry(coun,cit,str,str_n);
};
string get_input(string text){
    string obj;
    int error;
    do {error=0;

        cout << text<<": ";
        getline(cin, obj);
        cout<<endl;
        if(obj[0]<65 || obj[0]>90){
            cout<<text<<" should start with capital letter! Try again!"<<endl;
            error=1;
        }
    }while(error);
    return obj;
}
string get_number(){
    int error;
    string phone;
    do{error=0;
        cout<<"Phone number (XXX-XXX-XX-XX): ";
        getline(cin,phone);
        cout<<endl;
        if(phone.length()!=13 || phone[3]!='-' || phone[7]!='-' || phone[10]!='-'){
            cout<<"Wrong format! Try again!"<<endl;
            error=1;
        }
    }while(error);
    return phone;
}
int get_str_num(){
    int num,error;
    do{error=0;
        cout<<"Street number: ";
        cin>>num;
        cin.ignore();
        if(num<=0){
            cout<<"There can't be such street! Try again!"<<endl;
            error=1;
        }
    }while(error);
    return num;
}
int make_choice(string text){
    int choice;
    do {cout<<endl;
        cout << text << endl;
        cin>>choice;
        cin.ignore();
    }while(choice!=1 && choice!=2);
    return choice;
}
string generate_number(){
    string n="";
    for(int i=0;i<13;i++){
        string n1;int nn;
        if(i==3||i==7||i==10){
            n1="-";
        }
        else{
            nn=rand()%10;
            n1=to_string(nn);
        }
        n+=n1;
    }
    return n;
}
void fill_random(User *t, int &n){
    srand(time(NULL));
    int num,error;
    string country1[]={"Ukraine","Spain","England","Italy","Poland"};
    string city1[]={"Kyiv","Madrid","London", "Milan","Warshaw"};
    string street1[]={"Spaska", "de Rodas", "John Adam st","Via Cirie","Johna Lennona"};
    string name1[]={"Oleg","Sofiia","Viktoriia","Roman","Oksana","Nestor","Anastasiia","Evgeniia","Denys"};
    string surname1[]={"Nykyforuk","Kovalenko","Vitenko","Antonyk","Gladun","Smith","Jonas","Biber","Gomez"};
    string f_name1[]={"Olegivych(-ivna)","Petrovych(-ivna)","Mychailovych(-ivna)","Tarasovych(-ivna)"};
    do {error=0;
        cout << "How many users to generate? ";
        cin >> num;
        if(num>size){
            cout<<"Maximum number of users is "<<size<<" !"<<endl;
            error=1;
        }
    }while(error);
    for(int k=0; k<num; k++){
        int j=rand()%5;
        string surname = surname1[rand()%9];
        string name =name1[rand()%9] ;
        string f_name = f_name1[rand()%4];
        string number = generate_number();
        string country =country1[j] ;
        string city =city1[j] ;
        string street = street1[j];
        int street_number = rand()%100+1;
        t[k].SetValues(name, surname, f_name, number);
        t[k].SetAddress(country, city, street, street_number);
        n++;
    }
}
void fill_array(User *t, int &k){
    int c=1;
    while(c==1) {
        cout << "\tUser" << k + 1 << ":" << endl;
        string surname = get_input("Surname");
        string name = get_input("Name");
        string f_name = get_input("Fathers name");
        string number = get_number();
        string country = get_input("Country");
        string city = get_input("City");
        string street = get_input("Street");
        int street_number = get_str_num();

        t[k].SetValues(name, surname, f_name, number);
        t[k].SetAddress(country, city, street, street_number);
        k++;
        c = make_choice("Another object? Press 1 if YES 2 if NO ");
    }
}
void fill(User *t,int &k){
    cout<<"Do you want to input information or generate?"<<endl;
    int choice=make_choice("To input information PRESS 1, to generate PRESS 2");
    if(choice==1){
        fill_array(t,k);
    }
    else {
        fill_random(t,k);
    }
}
void find_number(User t[],int &k,int* arr){
    int sum,l,max=0;
    arr[0]=0;arr[1]=0;
    //cout<<k;
    for(int j=0;j<k;j++){
        string n= t[j].GetNumber();
        sum=0;
        for(int m=0; m<13;m++){

            if(m!=3 && m!=10 && m!=7){
                l=int(n[m])-48;
                sum+=l;
            }
        }
        if(sum>max)
        {
            max=sum; arr[0]=j;
        }
    }
    arr[1]=max;

}
void print(User t[],int k){
    for(int j=0;j<k;j++){
        cout<<"\tUser"<<j+1<<":"<<endl;
        cout<<t[j].GetSurname()<<" "<<t[j].GetName()<<" "<<t[j].GetFathersName()<<endl;
        cout<<"Phone number: "<<t[j].GetNumber()<<endl;
        cout<< "Address: " <<t[j].GetAddress()<<endl;
    }
}
void print_result(User *t,int *b){
    cout<<"\t\nResult:"<<endl;
    int j=b[0];
    cout<<"The User whose number makes the biggest sum is No "<<j+1<<" with sum "<<b[1]<<": "<<endl;
    cout<<t[j].GetSurname()<<" "<<t[j].GetName()<<" "<<t[j].GetFathersName()<<endl;
    cout<<"Phone number: "<<t[j].GetNumber()<<endl;
    cout<< "Address: " <<t[j].GetAddress()<<endl;
}