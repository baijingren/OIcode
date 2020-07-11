#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int num[15],n,sn,b,x[15],i,j;
long long sa,a,ss,z;
int main(){
	scanf("%d",&n);
	a=1;
	for(int k=1;k<=n;k++)
	{
		sa=a;
		for(i=1;sa>0;i++)
		{
			sa=sa/10;
		}
		sa=a;
		ss=sa/(i-1);
		for(j=1;z==ss;j++)
		{
			z=sa/(i-j);
			num[ss]++;
		}
		a=(num[z]*10+ss)+a*100;
		ss=sa/(i-j);
	}
	printf("%lld",a);
	return 0;
}
