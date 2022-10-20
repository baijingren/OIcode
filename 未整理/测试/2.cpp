#include<bits/stdc++.h>
using namespace std;
int main(){
	int deng[10000],n,i,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		deng[i]=0;
	}
	for(a=1;a<=n;a++)
	{
		for(int o=1;o<=n;o++)
		{
			if(o%a==0)
				deng[o]=!deng[o];
		}
	}
	for(b=1;b<=n;b++)
	{
		if(deng[b]==1)
			printf("%d ",b);
	}
}
