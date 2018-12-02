#include <cstdlib>
#define S system
int main(){
    for(int i=1;i<=10;i++){
        S("rand > in.txt");
        S("book.exe <in.txt");
        S("pause");
    }
}