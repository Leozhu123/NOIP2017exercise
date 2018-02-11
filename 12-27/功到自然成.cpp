#include <cstdio>
int q[1000005], sum = 0, st, ed, mid, n, k;
bool check(int s)
{
	int temp = 0, tot = 1;
	for (int i = 1; i <= n; i++) if (q[i] > s) return false;
		else if (temp + q[i] <= s) temp += q[i];
		else tot++, temp = q[i];
	if (tot <= k) return true;
	else return false;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &q[i]);
		sum += q[i];
	}
	st = 0, ed = sum;
	while (ed - st > 1)
	{
		mid = (st + ed) / 2;
		if (check(mid)) ed = mid;
		else st = mid;
	}
	printf("%d\n", ed);
	return 0;
}