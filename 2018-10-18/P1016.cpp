#include <bits/stdc++.h>
double D0, C, D, cost, left;
struct node
{
    double d, p;
} s[8];
int n;
bool cmp(node a, node b) { return a.d < b.d; }
int main()
{
    scanf("%lf%lf%lf%lf%d", &D0, &C, &D, &s[0].p, &n);
    s[n + 1].d = D0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &s[i].d, &s[i].p);
        if (s[i].d - s[i - 1].d > C * D)
        {
            printf("No Solution");
            return 0;
        }
    }
    std::sort(s + 1, s + 1 + n, cmp);
    for (int i = 0; i <= n + 1;)
    {
        int j, k;
        for (j = k = i + 1; j <= n; j++)
        {
            k = s[j].p <= s[k].p ? j : k;
            if (s[j].p <= s[i].p || s[j + 1].d - s[i].d > C * D)
                break;
        }
        if (s[j].p > s[i].p)
        {
            cost += (C - left) * s[i].p, left = C - (s[k].d - s[i].d) / D;
            i = k;
        }
        else
            cost += s[i].p * ((s[j].d - s[i].d) / D - left), i = j, left = 0;
    }
    printf("%.2lf", cost);
    return 0;
}