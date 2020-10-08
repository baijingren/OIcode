#include <bits/stdc++.h>
using namespace std;
const int qwe = 100005;
int n;
int a[qwe], f[qwe];
int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	scanf("%d", &n);
	for (int q = 1; q <= n; q++)
	{
		memset(f, 0, sizeof(f));
		int nn, d;
		scanf("%d", &nn);
		d = nn;
		for (int i = 1; i <= nn; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + nn + 1);
		f[0] = 1;
		for (int i = 1; i <= nn; i++)
		{
			if (f[a[i]])
			{
				a[i] = 0;
				d--;
			}
			for (int j = a[i]; j <= a[n]; j++)
			{
				f[j] = f[j] | f[j - a[i]];
			}
		}
		printf("%d\n", d);
	}
	return 0;
}