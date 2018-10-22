#include<cstdio>
#include<cstring>
using namespace std;
char circle_R(char c1,char c2){
     int a=c1>='a'?c1-'a'+1:c1-'A'+1;
     int b=c2>='a'?c2-'a'+1:c2-'A'+1;
     int c=a-b<0?a-b+26:a-b;
     char result=c1>='a'?c+'a':c+'A';
     return result;
}
char M[1001],k[101],C[1001];
int main(){
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    scanf("%s",&k);
    scanf("%s",&M);
    int j=0;
    for(int i=0;i<strlen(M);i++){
        C[i]=circle_R(M[i],k[j]);
        j++;
        if(j>=strlen(k))j=0;
    }
    printf("%s",C);
    return 0;
}