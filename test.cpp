#include <iostream>
int main(){
    int *a =new int;
    try{
        delete a;
        delete a;
    }catch(...){
        std::cout << "233";
    }
}