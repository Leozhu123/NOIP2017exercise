#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
struct rec
{
	double x;
	int to, e;
} a[2100000], b[2100000]; //a b 作用

int c[1100000][2],
	f[2100000], n, i, j, k, x, y, z, data; // c f

double len, ans, x1, y1, x2, y2; //len ans

int cmp(const void *a, const void *b)
{
	return ((rec *)a)->x > ((rec *)b)->x ? 1 : -1;
} // 快排参数

int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		a[i * 2 - 1].x = x1;
		a[i * 2 - 1].to = i;
		a[i * 2 - 1].e = 1; //to  e
		a[i * 2].x = x2;
		a[i * 2].to = i;
		a[i * 2].e = -1;
		b[i * 2 - 1].x = y1;
		b[i * 2 - 1].to = i;
		b[i * 2 - 1].e = 0;
		b[i * 2].x = y2;
		b[i * 2].to = i;
		b[i * 2].e = 1;
	}
	qsort(b + 1, 2 * n, sizeof(b[1]), cmp);
	qsort(a + 1, 2 * n, sizeof(a[1]), cmp);

	for (i = 1; i <= 2 * n; i++)
		c[b[i].to][b[i].e] = i; //c
	memset(f, 0, sizeof(f));
	for (ans = 0, i = 1; i < 2 * n; i++)
	{
		j = a[i].to;
		x = c[j][0];
		y = c[j][1];
		z = a[i].e;
		for (k = x; k < y; k++)
			f[k] += z;
		for (len = 0, k = 1; k < 2 * n; k++)
			if (f[k])
				len += b[k + 1].x - b[k].x; //f
		ans += len * (a[i + 1].x - a[i].x);
	}
	printf("%.2f\n", ans);

	return 0;
}
