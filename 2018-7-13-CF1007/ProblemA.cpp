#include <iostream>
#include <set>
#include <cstring>
#include <cstdlib>
using namespace std;
set <char> vowel;
int main(){
    vowel.insert('a');
    vowel.insert('e');
    vowel.insert('i');
    vowel.insert('o');
    vowel.insert('u');
    char in_str[105];
    scanf("%s",in_str);
    int len = strlen(in_str);
    for(int i=1;i<len;i++){
        if(( !vowel.count(in_str[i-1]) && !vowel.count(in_str[i]) && in_str[i-1]!='n')){
            puts("NO");
 //           cout << i << endl;
            return 0; 
        }   
    }
    if(!vowel.count(in_str[len-1]) && in_str[len-1]!='n'){
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}