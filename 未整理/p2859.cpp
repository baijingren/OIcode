#include <bits/stdc++.h>
const int qwe = 50005;
using namespace std;
int n;
struct node
{
	int st, ed, adr, pla;
} q[qwe];
bool cmp1(node a, node b)
{
	return a.st < b.st;
}
bool cmp2(node a, node b)
{
	return a.adr < b.adr;
}
int c[qwe];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &q[i].st, &q[i].ed);
		q[i].adr = i;
	}
	sort(q + 1, q + 1 + n, cmp1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int k = 0;
		for (int j = 1; j <= ans; j++)
		{
			if (c[j] < q[i].st)
			{
				c[j] = q[i].ed;
				q[i].pla = j;
				k = 1;
				break;
			}
		}
		if (!k)
		{
			ans++;
			c[ans] = q[i].ed;
			q[i].pla = ans;
		}
	}
	printf("%d\n", ans);
	sort(q + 1, q + n + 1, cmp2);
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", q[i].pla);
	}
	return 0;
}
