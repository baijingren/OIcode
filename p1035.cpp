#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int k;
double n;
int main() {
	scanf("%d", &k);
	for (int i = 1; n<k+1; i++)
	{
		n = n+1.0 / i;
		if (n > k)
		{
			printf("%d", i);
			break;
		}
	}
	return 0;
}