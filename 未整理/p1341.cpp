#include <bits/stdc++.h>
using namespace std;
const int pnt = 505;
int a[pnt][pnt];
int b[pnt];
int n, m;
stack<int> s;
int chk(char x)
{
	if (x >= 'A' && x <= 'Z')
	{
		return x - 'A' + 1;
	}
	else if (x >= 'a' && x <= 'z')
	{
		return x - 'a' + 1 + 26;
	}
}
char ck(int x)
{
	if (x <= 26)
	{
		return x + 'A' - 1;
	}
	else if (x > 26)
	{
		return x + 'a' - 1 - 26;
	}
}
void dfs(int x)
{
	for (int i = 1; i <= 50; i++)
	{
		if (a[x][i])
		{
			a[x][i]--;
			a[i][x]--;
			dfs(i);
		}
	}
	s.push(x);
	return;
}
int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	scanf("%d\n", &n);
	// cout << 1;
	int v = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		// cout << 2;
		char x, y;
		scanf("%c%c\n", &x, &y);
		int xx = chk(x), yy = chk(y);
		v = min(xx, v);
		v = min(yy, v);
		a[xx][yy]++;
		a[yy][xx]++;
		b[xx]++;
		b[yy]++;
		// cout << 3;
	}
	int cnt = 0;
	for (int i = 1; i <= 60; i++)
	{
		if (b[i] % 2 == 1)
		{
			cnt++;
			cout << 1;
			if (!v)
			{
				v = i;
			}
		}
	}
	if (cnt && cnt != 2)
	{
		printf("No Solution");
		return 0;
	}
	// cout << 4;
	dfs(v);
	// cout << 5;
	if (s.size() < m + 1)
	{
		printf("No Solution");
		return 0;
	}
	while (!s.empty())
	{
		printf("%c", ck(s.top()));
		s.pop();
	}
	return 0;
}
