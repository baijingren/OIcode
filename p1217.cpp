#include<iostream>
#include<cmath>
#include<cstring> 
#include<cstdio>
using namespace std;
int a, b;
void huiw(int n) {
	int s[15],ss=n,i=1;
	for (int i = 0; i < 15; i++)
	{
		s[i] = 0;
	}
	while (ss>0)
	{
		s[i] = ss % 10;
		ss = ss / 10;
		i++;
	}
	ss = 0;
	while (i>0)
	{
		ss = ss * 10 + s[i];
		i--;
	}
	if (ss==n)
	{
		printf("%d\n", n);
	}
}
void sus(int n, int m) {
	int ans = 0;
	for (int i = n; i <= m; i+=2)
	{
		for (int j = 2; j <= i/2; j++)
		{
			if (i % j == 0)
				ans++;
		}
		if (ans == 0);
			huiw(i);
			ans = 0;
	}
}
int main() {
	cin >> a >> b;
	sus(a, b);
	return 0;
}