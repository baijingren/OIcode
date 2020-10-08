#include<bits/stdc++.h>
using namespace std;
const int qwe = 100005;
int ans = 1, n;
struct C
{
	int b, e;
} c[qwe];
bool cmp(C x, C y)
{
	return x.b < y.b;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &c[i].b, &c[i].e);
	}
	sort(c + 1, c + n + 1, cmp);
	int ed = c[1].e;
	for(int i = 2; i <= n; i++)
	{
		if(c[i].b >= ed)
		{
			ans++;
			ed = c[i].e;
		}
	}
	printf("%d", ans);
	return 0;
}