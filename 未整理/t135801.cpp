#include<bits/stdc++.h> 
using namespace std;
const int qwe = 10005;
int n, top;
int a[qwe], m[qwe];
int main()
{
	freopen("test.in", "r", stdin);
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d", &a[i], &b[i]);
	}
	for(int i = 1;i <= n;i++)
	{
		if(a[i] <= m[top])
		{
			m[++top] = a[i];
		}
		else
		{
			int s = 0, sv = 0;
			for(int j = 1;j <= top;j++)
			{
				if(sv >= m[j] && m[j] <= a[i])
				{
					sv = m[top];
					s = j;
				}
			}
			m[s] = a[i];
		}
	}
	printf("%d",&top);
}