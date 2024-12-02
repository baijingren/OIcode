#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e4 + 5;
int n, m;
// 一维树状数组
namespace _1D_Tree
{
	int t[qwe];
	void addPoint(int x, int w)
	{
		while (x <= n)
		{
			t[x] += w;
			x += (x & -x);
		}
	}
	int query(int x)
	{
		int ans = 0;
		while (x)
		{
			ans += t[x];
			x -= (x & -x);
		}
	}
	int treeQuery(int l, int r)
	{
		return query(r) - query(l - 1);
	}
}
// 二维树状数组或者线段树
int t[qwe][qwe];
int d1[qwe][qwe], d2[qwe][qwe],d3[qwe][qwe],d4[qwe][qwe];
void addPoint(int x, int y, int w)
{
	int a = x, b = y, K = ;
	while(a <= n){
		b = y;
		while(b <= m){
			t[a][b] += w;
			b += (b & -b);
		}
		a += (a & -a);
	}
}
void addInterval(int a, int b, int c, int d, int w){
	
}
int query(int x, int y)
{
	int a = x, b = y;
	int ans = 0;
	while (a)
	{
		b = y;
		while (b)
		{
			ans += t[a][b];
			b -= (b & -b);
		}
		a -= (a & -a);
	}
	return ans;
}
int queryTree(int a, int b, int c, int d)
{
	return query(c, d) - query(c, b) - query(a, d) + query(a, b);
}

int main()
{
	char x;
	cin >> x >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		int a, b, c, d, w;
		if (x == 'L')
		{
			cin >> a >> b >> c >> d >> w;
			
		}
		else if (x == 'k')
		{
			cin >> a >> b >> c >> d;
			cout << queryTree(a, b, c, d) << '\n';
		}
	}
}