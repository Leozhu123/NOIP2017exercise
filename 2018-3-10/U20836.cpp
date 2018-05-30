#include <cstdio>
#include <cstring>
#include <iostream>
char str[1000005];
using namespace std;
const int maxn = 1000005;
struct BIT
{
	int C[maxn];
	int n;
	void init()
	{
		for (int i = 0; i < maxn; i++)
		{
			C[i] = 0;
		}
	}
	int lowbit(int x)
	{
		return x & -x;
	}
	void add(int x, int a)
	{
		while (x <= n)
		{
			C[x] += a;
			x += lowbit(x);
		}
	}
	int sum(int x)
	{
		int ret = 0;
		while (x > 0)
		{
			ret += C[x];
			x -= lowbit(x);
		}
		return ret;
	}
};
int main()
{
	int n, m;
	BIT st;
	st.init();
	scanf("%s", str + 1);
	int t = strlen(str);
	for (int i = 1; i <= t; i++)
	{
		//if (str[i] == "B")
			st.add(i, 1);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d%d", &a, &b);
		cout << st.sum(b) - st.sum(a - 1) << endl;
	}
}
