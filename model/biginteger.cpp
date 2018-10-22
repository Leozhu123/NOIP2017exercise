#include <iostream>
#include <vector>
#include <string>
using namespace std;
class BigInteger{
    vector<int> num;
    int len = 0;
    public:
    BigInteger() { num.push_back(0); }
    BigInteger(long long x){
        vector<int> tmp;
        while(x){
            tmp.push_back(x%10);
            x /= 10;
        }
        for(int i=tmp.size()-1;i>=0;i--){
            num.push_back(tmp[i]);
        }
        for(int i=0;i<num.size();i++){
            cout << num[i];
        }
        cout << endl;
    }
    BigInteger(string s){
        for(int i=0;i<s.size();i++){
            num.push_back(s[i]-'0');
        }
        for(int i=0;i<num.size();i++){
            cout << num[i];
        }
        cout << endl;
    }
    string tostring(){
        string ret;
        for(int i=0;i<num.size();i++){
            
        }
    }
};
int main(){
}