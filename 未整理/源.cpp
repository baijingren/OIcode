#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int f[15] = { 6,2,5,5,4,5,6,3,7,6,0,0,0,0,0 }, n, ans;
int mah(int a) {
	int s = a, m = 0;
	if (s == 0)
	{
		return 6;
	}
	while (s)
	{
		m += f[s % 10];
		s = s / 10;
	}
	return m;
}
int main() {
	cin >> n;
	for (int i = 0; i <= 711; i++)
	{
		for (int j = 0; j <= 711; j++)
		{
//			printf("%d %d %d %d %d %d %d\n", i, j, mah(i), mah(j), mah(i + j), mah(i) + mah(j) + mah(i + j),ans);
			if (mah(i) + mah(j) + mah(i + j) == n-4)
			{
				ans++;
			}

		}

	}
	printf("%d", ans);
}