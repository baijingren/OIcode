#include <bits/stdc++.h>
using namespace std;
int m, n, a, b, cnt = 0;
int s[10001][10001];
void dfs(int x, int y)
{
	// if (x>=b&&s[cnt][a] != s[cnt][b])
	// {
	// 	return;
	// }
	if (x > 2 * n)
	{
		if (s[cnt][a] == s[cnt][b])
		{
			cnt++;
			for (int i = 1; i <= 2 * n; i++)
			{
				// printf("%d", s[cnt - 1][i]);
				s[cnt][i] = s[cnt - 1][i];
			}
			// printf("\n");
		}
		return;
	}
	if (x <= n)
	{
		for (int i = y; i <= m; i++)
		{
			s[cnt][x] = i;
			dfs(x + 1, i);
		}
	}
	if (x > n)
	{
		for (int i = y; i >= 1; i--)
		{
			s[cnt][x] = i;
			dfs(x + 1, i);
		}
	}
}
int main()
{
	freopen("city.in", "r", stdin);
	freopen("city.out", "w", stdout);
	scanf("%d %d %d %d", &m, &n, &a, &b);
	dfs(1, 1);
	printf("%d", cnt%998244353);
	return 0;
}
