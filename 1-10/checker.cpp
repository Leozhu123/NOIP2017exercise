#include "testlib.h"
const int maxn=10005;
int a[maxn],b[maxn],ann[maxn];
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int m=inf.readInt();
    int t=inf.readInt();
    for (int i=0;i<m;i++)
        a[i]=inf.readInt();
    for (int i=0;i<m;i++)
        b[i]=inf.readInt();
    int ah=ans.readInt();
    int atl=ans.readInt();
    int ouh=ouf.readInt();
    int outl=ouf.readInt();
    if (m<=100){
        if (ah==ouh && atl==outl) quitf(_ok, "The answer is correct.");
        else quitf(_wa, "The answer is wrong");
    } else{
        for (int i=0;i<m;i++)
            ann[i]=ouf.readInt();
        int sumh=0,sumlt=t;
        for (int i=0;i<m;i++){
            sumh+=a[i]*ann[i];
            sumlt-=b[i]*ann[i];
        }
        if (ah==ouh && atl==outl && ah==sumh && atl==sumlt)  quitf(_ok, "The answer is correct.");
        else  quitf(_wa, "The answer is wrong");
    }    
}
