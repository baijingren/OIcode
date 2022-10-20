#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int a,n,aa;
int main(){
	scanf("%d",&a);
	if (a<=8)
	{
		aa=a*5+10;
	}
	else
	{
		aa=a*10-30;
	}
	printf("%d",aa);
	return 0;
}
