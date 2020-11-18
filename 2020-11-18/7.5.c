#include <stdio.h>
#include <string.h>
void rev(char *s1){
    char s2[1000];
    int n = strlen(s1);
    for(int i = 0;i < n;i++){
        s2[i] = s1[i];
    }
    for(int i = 0;i < n;i++){
        s1[n - i - 1] = s2[i];
    }
}
int main(){
    char str[1000];
    scanf("%s",str);
    rev(str);
    printf("%s",str);
}