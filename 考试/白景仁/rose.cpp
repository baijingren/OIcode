#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n,h[250005],x=0,y=0,z=0,t;
int main(){
	scanf("%d %d",&t,&n);
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&h[j]);
		}
		for(int k=1;x==0;k++)
		{
			if(h[k]>h[k+1])
				x=k;
		}
		for(int k=x;y==0;k++)
		{
			if(h[k]<h[k+1]){
				y=k;
			}
		}
		for(int k=y;z==0;k++)
		{
			if(h[k]>h[k+1])
				z=k;
		}
		if(1<x&&x<y&&y<z&&z<n)
			printf("TAK\n");
		else
			printf("NIE\n");
		x=0;y=0;z=0;
	}
	return 0;
}
