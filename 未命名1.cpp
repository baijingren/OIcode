#include<bits/stdc++.h>
using namespace std;
int main(){
	int js,sz,bc,jg=0;
	scanf("%d%d",&js,&sz);
	for(int i=1;i<=js;i++)
	{
		bc=i;
		while(bc>0)
		{
			if(bc%10==sz)
				jg++;
			bc/=10;
		}
	}
	printf("%d",jg);
}
