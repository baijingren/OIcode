#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n, aa, ab, ac, ba, bb, bc,ma,mb,mc;
int main() {
	scanf("%d", &n);
	scanf("%d %d\n %d %d\n %d %d\n", &aa, &ba, &ab, &bb, &ac, &bc);
	ma = (n / aa + 1) * ba;
	mb = (n / ab + 1) *bb;
	mc = (n / ac + 1) * bc;
	if (ma>mb&&ma>mc)
	{
		printf("%d", ma);
	}
	if (mb > ma && mb > mc)
	{
		printf("%d", mb);
	}
	if (mc > mb && mc > ma)
	{
		printf("%d", mc);
	}
	return 0;
}