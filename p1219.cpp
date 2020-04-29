#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a[15][105], n,ans[50],sum;
void dfs(int x) {//递归行
	if (x>n)
	{
		for (int i = 1; i <= n; i++)
		{
			sum++;
			if (sum>3)
				return;
			for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
			printf("\n");
			return;
		}
	}
	for (int i = 1; i <= n; i++)//搜索列
	{
		if (!a[1][i] && (!a[2][x + i]) && (!a[3][x - i + n])) {
			ans[x] = i;
			a[1][i] = 1;
			a[2][x + i] = 1;
			a[3][x - i + n] = 1;
			dfs(x + 1);
			a[1][i] = 0;
			a[2][x + i] = 0;
			a[3][x - i + n] = 0;
		}
	}
}
int main() {
	cin >> n;
	dfs(1);
	printf("%d", sum);
	return 0;
}