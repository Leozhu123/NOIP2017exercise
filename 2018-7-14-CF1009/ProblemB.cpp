#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
bool vis[3];
char str[100005];
int main()
{
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    while (true)
    {
        bool ok = false;
        for (int i = 1; i <= len - 1; i++)
        {
            if (str[i] == '1' && str[i + 1] == '0')
            {
                char t = str[i + 1];
                str[i + 1] = str[i];
                str[i] = t;
                ok = true;
            }
            else if (str[i] == '2' && str[i + 1] == '1')
            {
                char t = str[i + 1];
                str[i + 1] = str[i];
                str[i] = t;
                ok = true;
            }
        }
        if(!ok)
            break;
    }
    printf("%s", str + 1);
}