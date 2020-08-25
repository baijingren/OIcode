#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[1000],n,cc=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int o=i+1;o<=n;o++)
		{
			if(a[i]<a[o])
				cc=a[i];
				a[i]=a[o];
				a[o]=cc;
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
