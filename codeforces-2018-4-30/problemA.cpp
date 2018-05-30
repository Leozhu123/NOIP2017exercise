#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int n;
struct Number
{
    int num[105];
    int len;
};
bool operator<(const Number &lhs, const Number &rhs)
{
        if (lhs.len < rhs.len)
            return true;
        if (lhs.len > rhs.len)
            return false;
        for (int i=0;i<lhs.len;i++){
            if (lhs.num[i]>=rhs.num[i]) return false;
        }
        return true;
}
    Number now_min, num;
    void dfs(Number &x)
    {
        Number num;
        for (int i = 0; i < x.len; i++)
        {
            num.num[i] = x.num[i];
        }
        num.len = x.len;
        //case 1
        for (int i = 0; i < num.len - 1; i++)
        {
            Number new_num;
            for (int j = 0; j < num.len; j++)
            {
                new_num.num[j] = num.num[j];
            }
            
            new_num.len = num.len;
            int tmp = new_num.num[i];
            new_num.num[i] = new_num.num[i + 1];
            new_num.num[i + 1] = tmp;
            if (new_num.num[0] == 1 || new_num.len==1)
            {   
            	for (int j = 0; j < new_num.len; j++)
                {
                    cout << new_num.num[j];
                }
                cout << endl;
                cout << "n:";
                for (int j = 0; j < now_min.len; j++)
                {
                    cout << now_min.num[j];
                }
                cout << endl;
                if (new_num < now_min)
                {
                    for (int i = 0; i < new_num.len; i++)
                    {
                        now_min.num[i] = new_num.num[i];
                    }
                    now_min.len = new_num.len;
                    system("pause");
                    dfs(new_num);
                }
            }
        }
        //case2
        for (int i = 0; i < num.len - 1; i++)
        {
            if (num.num[i] == num.num[i + 1] && num.num[i] == 1)
            {
                Number new_num;
                for (int j = 0; j < num.len; j++)
                {
                    new_num.num[j] = num.num[j];
                }
                new_num.len = num.len;
                for (int j = i + 1; j < num.len; j++)
                {
                    new_num.num[j] = new_num.num[j + 1];
                }
                new_num.len--;
                
                for (int j = 0; j < new_num.len; j++)
                {
                    cout << new_num.num[j];
                }
                cout << endl;
                cout << "n:";
                for (int j = 0; j < now_min.len; j++)
                {
                    cout << now_min.num[j];
                }
                cout << endl;
                
                if (new_num < now_min)
                {
                    for (int i = 0; i < new_num.len; i++)
                    {
                        now_min.num[i] = new_num.num[i];
                    }
                    now_min.len = new_num.len;
                    dfs(new_num);
                }
            }
        }
}
int main()
{
    cin >> n;
    char ch;
    scanf("%c", &ch);
    for (int i = 0; i < n; i++)
    {
        char ch;
        scanf("%c", &ch);
        num.num[i] = ch - '0';
        now_min.num[i] = num.num[i];
    }
    num.len = n;
    now_min.len = n;
    dfs(num);
    for (int i = 0; i < now_min.len; i++)
    {
        cout << now_min.num[i];
    }
    cout << endl;
}
