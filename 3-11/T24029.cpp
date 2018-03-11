#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
bool visited[233333];
int n, a[300], answers[233333], pos = 0;
queue<int> q;
int main()
{
    cin >> n;
    answers[pos++] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < pos; j++)
        {
            int t = answers[j] + a[i];
            if (!visited[t])
            {
                q.push(t);
            }
        }
        while (!q.empty())
        {
            int t = q.front();
            visited[t] = true;
            answers[pos++] = t;
            q.pop();
        }
    }
    cout << pos - 1;
}