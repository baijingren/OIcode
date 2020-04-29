#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int a[16], b,x,y,z;
int main() {
	for (int i = 100; i <= 334; i++)
	{
		x = i;
		y = i * 2;
		z = i * 3;
		for (int j = 0; j < 3; j++)
		{
			a[x % 10]++;
			a[y % 10]++;
			a[z % 10]++;
			x /= 10;
			y /= 10;
			z /= 10;
		}
		for (int j = 1; j < 10; j++)
		{
			if (a[j] == 1)
				b++;
		}
		if (b == 9)
		{
			printf("%d %d %d\n", i, i * 2, i * 3);
		}
		for (int k = 0; k < 16; k++)
		{
			a[k] = 0;
			b = 0;
		}
	}
	return 0;
}