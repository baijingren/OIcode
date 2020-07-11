<<<<<<< HEAD
#include<iostream>
=======
﻿#include<iostream>
>>>>>>> 54968d54e06c8c200387462b01be1223bac46373
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
<<<<<<< HEAD
int a[15][15],n;
void pit(int X,int Y){
    for (int i = 0; i < n; i++)
    {
        a[i][Y]=2;
    }
    for (int i = 0; i < n; i++)
    {
        a[]
    }
    
        a[X][Y]=1;
}
void dfs(int x){
    for (int i = 0; i < n; i++)
    {
        pit(x,i);
        dfs(x+1);
        a[x][i]=0;
    }
    
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    printf("%d",&n);
    dfs(1);
    return 0;
=======
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
>>>>>>> 54968d54e06c8c200387462b01be1223bac46373
}