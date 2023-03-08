//
// Created by gr on 08.03.2023.
//
#include <iostream>
#include<fstream>
#include<string>
#include "streamlib.h"
using namespace std;

int fillchoice(){
    int choice;
    do {
        cout<<"To input information PRESS 1, to creat automatically PRESS 2"<<endl;
        cin >> choice;
        cin.ignore();
    }while(choice!=1 && choice!=2);
    return choice;
}
int fillyourself(ofstream& f,string name){
    f.open(name);
    if(!f.is_open()){
        cout<<"Can't open file!"<<endl;
        return 1;
    }
    string line;
    char nextline;
    do {
        cout << "Enter line: ";
        getline(cin, line);

        f << line << endl;
        do {
            cout << "Another line? PRESS Y for yes or N for no" << endl;
            cin >> nextline;
            cin.ignore();
        } while (nextline != 'Y' && nextline != 'y' && nextline != 'N' && nextline != 'n');
    }while(nextline=='Y'|| nextline=='y');
    f.close();

}
int fillautomatically(ofstream& f, string name){
    f.open(name);
    if(!f.is_open()){
        cout<<"Can't open file!"<<endl;
        return 1;
    }
    f << "ONCE UPON A TIME a girl named Cinderella lived with her stepmother and two stepsisters\n";
    f << "Poor Cinderella had to work hard all day long oso the others could restr\n";
    f << "It was she who had to wake up each morning when it was still dark and cold to start the fire\n";
    f << "It was she owho cooked the meals\n";
    f << "It was she who kept the fire going\n";
    f << "The poor girl could tnot stay clean from lall the ashes and cinders by the fire\n";
    f.close();
}
void createFile(ofstream& f,string name)
{
        cout<<"Do you want to input information into the file or automatically create file?"<<endl;
        //int choice;
        //char nextline;
       // string line;
       int choice=fillchoice();
        if(choice==1){
           fillyourself(f,name);//введення даних самостійно
        }
        else {
            fillautomatically(f,name);//заповнення файла автоматично
        }
}
int printFile(ifstream& f, string name)
{
    string line1;
    f.open(name);//зчитати файл
    if(f.is_open()){
        while(getline(f,line1)){
            cout<<line1<<endl;
        }
        f.close();
    }
    else{
        cout<<"Can't open file\n";
        return 1;
    }
}
void appendfile(ofstream& ff,ifstream& f, string name) {
    char choice;
    string text;
    int i=0;
    ff.open(name, ios::app);
    if (ff.is_open()) {
        do{
            cout << "\nDo you want to add something to current file? " << endl;
            do {
                cout << "PRESS Y for YES or N for NO" << endl;
                cin >> choice;
                cin.ignore();
            } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
            if (choice == 'Y' || choice == 'y') {
                i++;
                cout << "Enter line: ";
                getline(cin, text);
                ff << text << endl;
            }
        }while(choice=='Y'||choice=='y');

    }else{
        cout<<"Can't open this file for appending!"<<endl;
    }
ff.close();
if(i>0) {
    cout << "\tAppended file:" << endl;
    printFile(f, name);
}
}
string oddline(string line){
    int j=0;//початок слова
    int pos=0;//пробіл
    int w=0;
    int k=line.length();//довжина рядка
    //cout<<"1"<<endl;
    while(j<k)
    {//cout<<"2"<<endl;
        pos=line.find(" ", j);//позиція пробілу
        if(pos<=0){
            w=line.length()-j;
            k=0;
        }
        if(line[j]>=65 && line[j]<= 90){//чи перша буква велика
            if(pos>0){
                w=pos-j+1;
                k=k-pos-1-j;//зменшити довжину рядка
            }

            //cout<<"w  "<<w<<endl;
            line.erase(j, w);//видалити слово

            pos=j-1;
        }
        j=pos+1;
    }
    return line;
}
string evenline(string line){
    int j=0;//початок слова
    int pos=0;//пробіл
    int k=line.length();//довжина рядка
    string line1;

    while(j<k)//поки не кінець рядка
    {
        pos=line.find(" ", j);//позиція пробілу
        if(pos<0){
            pos=line.length();
        }
        if(line[j]==line[pos-1] ){//перевірка чи слово поч. і зак. на однакову букву
            if(j==pos-1){//якщо слово з одної букви
                line1=line[j];}
            else{
                line1=line.substr(j,pos-j);//спопіювати слово у line1
            }
            if(pos==line.length()){
                line.insert(pos, " ");
                line.insert(pos+1,line1);

            }else {
                line.insert(pos + 1, line1);//вставити слово
                pos = pos + 1 + line1.length();//перенести курсор на кінець слова
                line.insert(pos, " ");//вставити пробіл після
                k=k+ 1 + line1.length();
            }
        }
        j=pos+1;//початок наступного слова
    }
    return line;
}
int changeFile(ofstream& f,ifstream& ff,string name)
{
    //ofstream f;//запис у файл
    //ifstream ff;//зчитування з файлу
     string temp_file="Test1.txt";
    f.open(temp_file);
    ff.open(name);//зчитати файл
    if(ff.is_open()){
        int i=1;//лічильник рядка
        int max=0;//максимальна довжина рядка
        int len=0;//довжина рядка
        int num=0;//номер найдовшого рядка
        while(!ff.eof()){
            string line;
            getline(ff,line);//записати рядок з файла у line

            if(i%2!=0){//якщо непарний рядок
                line=oddline(line);
               }
            else{//парний рядок
                line=evenline(line);


            }
            len=line.length();
            if(len>max){//перевірити чи довжина рядка більша за максимум
                max=len;
                num=i;
            }
            f<<line<<endl;//записати рядок у файл
            i=i+1;
        }
        f.close();
        ff.close();
        f.open(temp_file, ios::app);//відкрити файл у режимі "дописати"
        if(f.is_open()){
            f<<"Length - "<<max<<", number of line - "<<num<<"."<<endl;
        }else cout<<"Can't open file"<<endl;
        f.close();
    }
    else{
        cout<<"Can't open file!\n";
        return 1;
    }
    remove(name.c_str());//видалити початковий файл
    rename(temp_file.c_str(),name.c_str());//перейменувати тимчасовий файл
}