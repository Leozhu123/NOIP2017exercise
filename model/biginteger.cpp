#include <iostream>
#include <vector>
#include <string>
using namespace std;
class BigInteger{
    vector<int> num;
    int len = 0;
    public:
    BigInteger(long long x = 0)
    {
        while (x)
        {
            num.push_back(x % 10);
            x /= 10;
        }
    }
    BigInteger(string s){
        for(int i=s.size()-1;i>=0;i--){
            num.push_back(s[i]-'0');
        }
    }
    string tostring(){
        string ret;
        for(int i=num.size()-1;i>=0;i--){
            ret += (num[i] + '0');
        }
        return ret;
    }
    BigInteger operator+(const BigInteger & l) {
        BigInteger ret;
        
    }
};
int main(){}