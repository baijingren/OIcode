#include<bits/stdc++.h>
using namespace std;
int main()
{
	scanf("%d", &n, &m);
	for(int i = 1; i <= m;i++)
	{
		scanf("%d", &s[i]);
		for(int j = 1; j <= s[i]; j++)
		{
			scanf("%d", &a[i]);
			add(a[1], a[i]);
