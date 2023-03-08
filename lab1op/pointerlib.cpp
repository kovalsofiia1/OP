#include<iostream>
#include<stdio.h>
#include <cstring>
#include "pointerlib.h"
#define MAX 255
using namespace std;
int choicep(){
    int choice;
    do {
        cout<<"To input information PRESS 1, to creat automatically PRESS 2"<<endl;
        cin >> choice;
        cin.ignore();
    }while(choice!=1 && choice!=2);
    return choice;
}
void fillfile(FILE* file,char* name){
    file= fopen(name,"w");
    if (file !=NULL) {
        char nextline;
        char *line = (char *) (malloc(sizeof(char) * MAX));

        do {
            cout << "Enter line: ";
            gets(line);
            fputs(line, file);
            fputs("\n", file);
            do {
                cout << "Another line? PRESS Y for yes or N for no" << endl;
                cin >> nextline;
                cin.ignore();
            } while (nextline != 'Y' && nextline != 'y' && nextline != 'N' && nextline != 'n');
        } while (nextline == 'Y' || nextline == 'y');
        free(line);
        fclose(file);
    }
    }
void autofill(FILE* file, char* name){
        file= fopen(name,"w");
        if (file !=NULL){
            fputs("ONCE UPON A TIME a girl named Cinderella lived with her stepmother and two stepsisters\n", file);
            fputs("Poor Cinderella had to work hard all day long oso the others could restr\n", file);
            fputs("It was she who had to wake up each morning when it was still dark and cold to start the fire\n", file);
            fputs("It was she owho cooked the meals \n", file);
            fputs("It was she who kept the fire going\n", file);
            fputs("The poor girl could tnot stay clean from lall the ashes and cinders by the fire\n", file);
        }
        fclose(file);
}
void create(FILE* file,char *name){

    if (file !=NULL){
        cout<<"Do you want to input information into the file or automatically create file?"<<endl;
        int choice = choicep();
        if(choice==1){
            fillfile(file,name);
        }
        else {
           autofill(file,name);
        }
    }
}
void print(FILE* file, char *name){
    file=fopen(name,"r");
    char *text=(char*)(malloc(sizeof(char)*MAX));;
    if(file!=NULL){
        while(fgets(text,1000,file)){
            cout<<text;
        }
    }
    free(text);
    fclose(file);
}
void append(FILE* file, char* name){
    char choice;
    char* line=(char*)(malloc(sizeof(char)*MAX));
    int i=0;
    file=fopen(name, "a");
    if (file!=NULL) {
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
                gets(line);
                fputs(line,file);
                fputs("\n",file);
            }
        }while(choice=='Y'||choice=='y');

    }else{
        cout<<"Can't open this file for appending!"<<endl;
    }
    fclose(file);
    if(i>0) {
        cout << "\tAppended file:" << endl;
        print(file, name);
    }
    free(line);
}
char* oddl(char* text){
    int j=0;//початок слова
    int pos=0;//пробіл
    int k= strlen(text);//довжина рядка

    int m=0;
    while(m<=k){

        char s=text[m];
        if(isspace(s)) {
            pos = m;
            if(text[j]>=65 && text[j]<= 90){//чи перша буква велика
                k=k-(m-j+1);//зменшити довжину рядка
                for(int r=j;r<k;r++){
                    //text[r]=text[pos+r+1];
                    text[r]=text[pos+1];
                    ++pos;
                }
                text[k]='\0';
                if(text[k-1]!='\n'){
                    text[k]='\n';
                    text[k+1]='\0';}
                m=j-1;
            }else j=1+pos;
        }m++;
    }
    return text;
}
char* evenl(char* text){
    int j=0;//start of word
    int pos=0;//' '
    int k=strlen(text);
    int m=0;
    while(m<=k+1){
        char s=text[m];
        if(isspace(s)){
            if(text[j]==text[m-1]){//вставити таке ж слово
                k=k+(m-j+1);
                for(int i=k; i>j+(m-j);i--){
                    text[i]=text[i-(m-j+1)];
                }
                for(int i=0;i<k-1;i++){
                    if(text[i]=='\n'){
                        text[i]=' ';
                    }
                }

                j=m+(m-j+1);
            }else j=m+1;

        }
        m++;
    }
    return text;
}
int change(FILE* file, char *name){
    FILE* temp;//тимчасовий файл
    char* name1="temp_file.txt";
    temp=fopen(name1, "w");
    file=fopen(name,"r");
    char *text=(char*)(malloc(sizeof(char)*MAX));

    if(file!=NULL){
        int i=1;//лічильник рядка
        int max=0;//максимальна довжина рядка
        int len=0;//довжина рядка
        int num=0;//номер найдовшого рядка
        cout<<"\n\tChanged file:"<<endl;
        while(fgets(text,sizeof(char)*MAX,file)){
            if(i%2!=0){
                text=oddl(text);
            }else{
                text=evenl(text);
            }
            len=strlen(text);
            if(len>max){//перевірити чи довжина рядка більша за максимум
                max=len;
                num=i;
            }
            fputs(text,temp);
            i++;
        }
        free(text);
        fclose(file);
        fclose(temp);
        temp=fopen(name1,"a");
        if(temp!=NULL){
            fprintf(temp,"\nLength - %d, number of line - %d.",max,num);
        }else cout<<"Can't open file"<<endl;
        fclose(temp);
    }else{
        cout<<"Can't open file!"<<endl;
        return 1;
    }
    remove(name);
    rename(name1,name);
}
