#include <stdio.h>
#include <string.h>
void reserve(char *str){
    char str2[1000];
    int n = strlen(str);
    for (int i = 0; i < n;i++){
        str2[i] = str[i];
    }
    for (int i = 0; i < n;i++){
        str[i] = str2[n - i - 1];
    }
}
int main(){
    char str[1000];
    scanf("%s", str);
    reserve(str);
    printf("%s", str);
}