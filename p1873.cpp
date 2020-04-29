#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int n, m,a[10000];
int tr(int x) {
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if(a[i]>x) sum += a[i] - x;
	}
	return sum;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 0, r = a[n];
	while (l<r)
	{
		int mid = (l + r + 1) / 2;
		if (tr(mid) >= m)	l = mid;
		else r = mid - 1;
	}
	printf("%d", l);
}