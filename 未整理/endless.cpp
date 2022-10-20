#include <bits/stdc++.h>
using namespace std;
const int qwe = 200005;
int n, L, v, a[qwe], q, t,s;
int jud(int x)
{
	int ans = L;
	for (int i = 1; i <= x; i++)
	{
		ans += a[i];
	}
	return ans;
}
int main()
{
	freopen("endless.in", "r", stdin);
	freopen("endless.out", "w", stdout);
	scanf("%d %d %d", &n, &L, &v);
	int ans = L;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d ", &a[i]);
		ans += a[i];
	}
	// sort(a + 1, a + n + 1);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d", &t);
		int l = 0, r = q;
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (jud(mid) / v >= t)
				r = mid;
			else
				l = mid + 1;
		}
		// s = jud(l);
		if(ans/v<=t)
		{
			printf("-1");
			continue;
		}
		if (l<=n)
		{
			printf("%d\n", l);
			continue;
		}
	}
	return 0;
}
