#include <bits/stdc++.h>
using namespace std;
bool ju[15][100005];
char ch[15][100005];
int a[40000];
int r, c, ans = 0;
bool judge(int s)
{
    for (int i = 1; i <= r; i++)
        if (ju[i][s])
        {
            return 1;
            break;
        }
    return 0;
}
int find(int j, int i)
{
    int k;
    if (!judge(i + 1))
    {
        k = 1;
        return k;
    }
    if (!ju[j + 2][i + 1])
    {
        if (ju[j + 4][i])
        {
            k = 0;
            return k;
        }
        else
        {
            k = 7;
            return k;
        }
    }
    if (!ju[j + 1][i + 2])
    {
        if (ju[j + 3][i])
        {
            k = 6;
            return k;
        }
        else
        {
            k = 5;
            return k;
        }
    }
    if (!ju[j][i + 1])
    {
        k = 4;
        return k;
    }
    if (!ju[j + 1][i])
    {
        if (ju[j + 3][i + 2])
        {
            k = 3;
            return k;
        }
        else
        {
            k = 2;
            return k;
        }
    }
    if (ju[j + 3][i])
    {
        k = 8;
        return k;
    }
    else
    {
        k = 9;
        return k;
    }
}
int main()
{
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++)
        for (int j = 0; j <= c; j++)
        {
            scanf("%c", &ch[i][j]);
            if (ch[i][j] == 'o')
                ju[i][j] = true;
            else
                ju[i][j] = false;
        }
    int i = 1;
    while (i <= c)
    {
        for (int j = 1; j <= r;j++){
            int x = find(j, i);
            if(x !=-1){
                cout << x;
                break;
            }
        }
    }
    for (int i = 0; i < ans; i++)
        printf("%d", a[i]);
    return 0;
}