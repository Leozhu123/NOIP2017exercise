#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define P pair<int, int>
using namespace std;
int a[200][200];
map<int, int> idx;
vector<P> roads;
int maxnum = 0;
int main()
{
    int d, n;
    cin >> d >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;
        a[x][y] = k;
        roads.push_back(P(x, y));
    }
    for (int i = 0; i <= 128; i++)
    {
        for (int j = 0; j <= 128; j++)
        {
            int sum = 0;
            for (int k = max(0, i - d); k <= min(i + d, 128); k++)
            {
                for (int h = max(0, j - d); h <= min(j + d, 128); h++)
                {
                    sum += a[k][h];
                }
            }
            idx[sum]++;
            maxnum = max(maxnum, sum);
        }
    }
    cout << idx[maxnum] << " " << maxnum;
}