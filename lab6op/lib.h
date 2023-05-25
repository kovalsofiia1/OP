
#ifndef LAB6OP_LIB_H
#define LAB6OP_LIB_H


#include <iostream>
#include<sstream>
#include<type_traits>
#include<string>
using namespace std;
template<typename T>
void get_input(T& v, string text, int f=0, int n=0);

template<typename T>
struct Node{
    T data;
    Node* next;

    Node(T n){
        data=n;
        next=nullptr;
    }
};

template<typename T>
class Queue{
    Node<T> *head, *tail;
public:
    class Iterator{
    public:
        Node<T>* pos;
        Node<T>* previous;
        Iterator(Node<T>* param=NULL){
            pos = param;
            previous = nullptr;
        }
        bool operator!=(const Iterator &r)const{
            return (this->pos!=r.pos);
        }
        Iterator operator++(int){
            previous=pos;
            Iterator temp(pos);
            pos=pos->next;
            return temp;
        }
        Iterator& operator++(){
            previous=pos;
            pos=pos->next;
            return *this;
        }
        int operator*() const {
            return pos->data;
        }

        Iterator& operator--(){
            if (previous != nullptr) {
                pos = previous;
                previous = NULL;
            }
            return *this;
        }
        Iterator& operator+(int n) {
            for (int i = 0; i < n; i++) {
                previous = pos;
                pos = pos->next;
            }
            return *this;
        }

    };
    Iterator begin() {
        return Iterator(head);
    }
    Iterator end(){
        return Iterator(nullptr);
    }
    Queue():head(nullptr),tail(NULL){}
    void append(T n){
        Node<T>* node= new Node<T>(n);
        if(head==nullptr){
            head= tail=node;
        }
        else{
            tail->next=node;
            tail=node;

        }
    }
    void remove(){
        if(head==nullptr){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        Node<T>* current;
        current=head;
        head=head->next;
        if(head==nullptr) tail=nullptr;
        delete current;
    }
    void display(){
        cout<<endl;
        cout<<"Current queue: "<<endl;
        Node<T>* temp=head;
        Iterator i=begin();
        cout<<"[ ";
        while(i!=nullptr){
            cout<<temp->data;
            if(i!=tail){
                cout<<", ";
            }

            temp=temp->next;
            i++;
        }
        cout<<" ]"<<endl;
    }
    void is_empty_text(){
        if(head==nullptr){
            cout<<"The queue is empty"<<endl;
        }
        else{
            cout<<"Queue has elements"<<endl;
        }
    }
    void clear(){
        while (head!=nullptr) {
            remove();
        }
    }

};
template<typename T>
void fillQueue(Queue<T> &q,int num){
    for(int i=0; i<num; i++){
        T t;
        cout<<i+1<<": ";
        get_input<T>(t,"Wrong type of input!",1,i);
        q.append(t);
    }
}

void fillQueue(Queue<string> &q,int num){
    for(int i=0; i<num; i++){
        string t;
        cout<<i+1<<": ";
        getline(cin,t);
        q.append(t);
    }
}
template<typename T>
void get_input(T& v, string text, int f, int n){
    if (is_same<T, int>::value || is_same<T, float>::value) {
        string line;
        while (getline(cin, line)) {
            stringstream ss(line);
            if ((ss >> v) && ss.eof()) {
                break;
            } else {
                cout << text << endl;
                if (f == 1) {
                    cout << n + 1 << ": ";
                }
            }
        }
    }
    else if(is_same<T, char>::value){
        cin>>v;
        cin.ignore();
    }
}

void check_type(int& v, string line){
    int error=0;
    while(error==0)
    {
        stringstream ss(line);
        if ((ss >> v) && ss.eof())
        {
            error=1;
            break;
        }
        else
        {
            cout << "Wrong type of input! Try again: "<< endl;

            getline(cin,line);
        }
    }
}
void check_bounderies(int& v, int a, int b, string text){
    string line;
    v=0;
    while(v<a || v>b){
        getline(cin, line);
        check_type(v,line);
        if(v<a || v>b){
            cout<<"Error! Value out of range!"<<endl;
            cout<<text;
        }



    }
}

template<typename T>
void menu(Queue<T> &q, int n){
    fillQueue(q,n);
    q.display();

    string next;
    do {
        int task;
        cout << "\n\tList of possible operations:" << endl;
        cout << "1. Delete element from queue" << endl;
        cout << "2. Add element to queue" << endl;
        cout << "3. Check if queue is empty" << endl;
        cout << "4. Clear queue" << endl;
        cout << endl;
        cout << "Choose task:";
        check_bounderies(task, 1, 4, "Choose task :");

        if (task == 1) {
            q.remove();
            q.display();
        } else if (task == 2) {

            cout << "Input value to add: ";
            T value;
            get_input(value, "Wrong type! Enter again: ",0,0);
            q.append(value);
            q.display();

        } else if (task == 3) {
            q.is_empty_text();
        } else {
            q.clear();
            q.display();
        }

        cout<<"To continue press ENTER , to end- any symbol"<<endl;
        cin.clear();
        getline(cin,next);


    }while(next.empty());

}
void menu(Queue<string> &q, int n){
    fillQueue(q,n);
    q.display();
    string next;
    do {
        int task;
        cout<<"\n\tList of possible operations:"<<endl;
        cout<<"1. Delete element from queue"<<endl;
        cout<<"2. Add element to queue"<<endl;
        cout<<"3. Check if queue is empty"<<endl;
        cout<<"4. Clear queue"<<endl;
        cout<<endl;
        cout<<"Choose task:";
        check_bounderies(task,1,4,"Choose task :");

        if(task==1){
            q.remove();
            q.display();
        }
        else if(task==2){

            cout<<"Input value to add: ";

            string value;
            getline(cin,value);
            q.append(value);
            q.display();

        }
        else if(task==3){
            q.is_empty_text();
        }
        else{
            q.clear();
            q.display();
        }
        cout<<"To continue press ENTER , to end - any symbol"<<endl;
        cin.clear();
        getline(cin,next);


    }while(next.empty());


}




#endif //LAB6OP_LIB_H
