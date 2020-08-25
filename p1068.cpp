#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct stu
{
	int k, s;
};
stu st[10005];
int n, m;
bool cmpa(stu x,stu y){
	return x.k < y.k&&x.s > y.s;
}
bool cmpb(stu x,stu y){
	return x.s > y.s;
}
int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> st[i].k >> st[i].s;
	}
	sort(st + 1, st + n + 1, cmpa);
	sort(st + 1, st + n + 1, cmpb);
	int i = 1;
	int a;
	a = st[int(m*1.5)].s;
	while (1)
	{
		if (st[i].s<a)
		{
			break;
		}
		i++;
	}
	printf("%d %d\n", a, i-1);
	i = 1;
	while (1)
	{
		if (st[i].s<a)
		{
			break;
		}
		printf("%d %d\n", st[i].k, st[i].s);
		i++;
	}
	return 0;
}