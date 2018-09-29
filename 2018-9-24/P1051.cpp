#include <iostream>
#include <string>
using namespace std;
string names[105];
int monny[105];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>names[i];
        int qimo,banji;
        bool gan,xi;
        int lun;
        cin>>qimo>>banji;
        char ch;
        cin>>ch;
        gan = (ch == 'Y' ? true : false);
        cin>>ch;
        xi = (ch == 'Y' ? true : false);
        cin >> lun;
        if(qimo>80 && lun>=1)
            monny[i] += 8000;
        if(qimo>85 && banji>80)
            monny[i] += 4000;
        if(qimo>90) 
            monny[i]+=2000;
        if(qimo>85 && xi)
            monny[i] += 1000;
        if(banji>80 && gan)
            monny[i] += 850;
    }
    int max=0;
    string name;
    int sum=0;
    for(int i=1;i<=n;i++){
        if(monny[i]>max){
            max=monny[i];
            name = names[i];
        }
        sum += monny[i];
    }
    cout<<name<<endl<<max<<endl<<sum<<endl;
}
