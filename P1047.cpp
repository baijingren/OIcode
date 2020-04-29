#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int m, l, st[105], ed[105], tr[10005],x;
	scanf("%d %d\n", &l, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", st[i], ed[i]);
	}
	for (int j = 0; j <= m; j++)
	{
		for (int i = st[j]; i <= ed[j]; i++)
		{
			tr[i] = 1;
		}
	}
	for (int i = 0; i <= l; i++)
	{
		if (n[i]==0)
		{
			x++;
		}
	}
	printf("%d", x);
	return 0;
}