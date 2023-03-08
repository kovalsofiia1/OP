
#include "streamlib.h"
#include "pointerlib.h"
#include<cstring>
using namespace std;


int main(int argc, char* argv[]) {

if(argc!=3){
    cout<<"Please pass parameter (FileStream/FilePointer)!"<<endl;
    return 1;
}
char* mode=argv[2];
    if(!strcmp(mode,"FileStream")) {
        cout<<"Working with streams and strings:\n\n";
        string filename = "Test.txt";
        ofstream myfile;//запис у файл
        ifstream iffile;//зчитування з файлу
        createFile(myfile, filename);
        cout << "\tCreated file:" << endl;
        printFile(iffile, filename);
        appendfile(myfile, iffile, filename);
        cout << "\n\tChanged file:\n" << endl;
        changeFile(myfile, iffile, filename);
        printFile(iffile, filename);
    }
    else if(strcmp(mode,"FilePointer")==0){
        cout<<"Working with pointers and arrays:\n\n";
        FILE* myfile;
        char *n= "Text.txt";
        create(myfile,n);
        cout<<"\tCreated file:"<<endl;
        print(myfile,n);
        append(myfile,n);
        change(myfile,n);
        print(myfile,n);
    }
    else{
        cout<<"Unknown parameter! You can pass either FileStream or FilePointer to main function"<<endl;
        return 1;
    }

    return 0;
}



