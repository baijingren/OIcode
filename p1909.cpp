#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n, aa, ab, ac, ba, bb, bc, ma, mb, mc;
int main() {
	cin >> n;
	cin >> aa >> ba >>  ab >> bb >> ac >> bc;
	ma = (n / aa ) * ba;
	mb = (n / ab ) * bb;
	mc = (n / ac ) * bc;
	if (ma > mb && ma > mc)
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