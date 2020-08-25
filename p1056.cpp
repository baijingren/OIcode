#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct stu { int cnt, num; };
stu cp[1005], rq[1005];
int n, m, k, l, d;
int xa, xb, ya, yb,x,y;
bool cmp1(const stu& x, const stu& y) {
	if (x.cnt < y.cnt) return 0;
	else if (x.cnt > y.cnt) return 1;
	else {
		if (x.num < y.num) return 1;
		else return 0;
	}
}
bool cmp2(const stu& x, const stu& y) {
	return x.num < y.num;
}
int main()
{
	cin >> n >> m >> k >> l >> d;
	for (int i = 1; i <= d; i++)
	{
		cin >> xa >> ya >> xb >> yb;
		if (xa <= xb)
		{
			x = xa;
		}
		else
		{
			x = xb;
		}
		if (ya <= yb)
		{
			y = ya;
		}
		else
		{
			y = yb;
		}
		if (xa == xb)
		{
			cp[y].cnt++, cp[y].num = y;
		}
		else
		{
			rq[x].cnt++, rq[x].num = x;
		}
	}
	sort(cp, cp + m, cmp1);
	sort(rq, rq + n, cmp1);
	sort(rq, rq + k, cmp2);
	for (int i = 0; i < k; i++)
	{
		cout << rq[i].num << " ";
	}
	cout << endl;
	sort(cp, cp + l, cmp2);
	for (int i = 0; i < l; i++)
	{
		cout << cp[i].num << " ";
	}
	return 0;
}

