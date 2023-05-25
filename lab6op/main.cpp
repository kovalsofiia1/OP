#include"lib.h"
int main() {

    cout<<"-----Working with queue based on linked list------\n";
    int type=0,num;
    cout<<"Choose type of ATD (1-int; 2-float; 3-char; 4-string) :";

    check_bounderies(type,1,4,"Choose type of ATD (1-int; 2-float; 3-char; 4-string) :");

    cout<<endl;
    cout<<"How many elements should be in queue? ";
    check_bounderies(num,1,20,"How many elements should be in queue? ");

    if(type==1){
        Queue<int> q;
        menu(q,num);
    }else if(type==2){
        Queue<float> q;
        menu(q,num);
    }else if(type==3){
        Queue<char> q;
        menu(q,num);
    }else{
        Queue<string> q;
        menu(q,num);
    }
    return 0;
}


/*12. Спроектувати АТД "Черга на базі зв'язного списку" для контейнера,
 * що містить дані довільного типу.
 * Інтерфейс АТД включає такі обов'язкові операції:

-перевірка черги на пустоту,
-очищення черги,
-видалення елемента із черги,
-включення нового елемента у чергу,
-ітератор для доступу до елементів черги з операціями:

1) встановлення на початок черги,
2) встановлення в кінець черги,
4) перехід до попереднього елемента черги,
5) перехід до наступного елемента черги.*/
