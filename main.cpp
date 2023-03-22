#include"mylibrary.h"

int main(){
    string filename= get_filename();
    cout<<filename<<endl;
    create(filename);
    fill_file(filename);
    count_prize(filename);
    delete_short_calls(filename);
}
