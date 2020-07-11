#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a, b, c;
int main() {
	cin >> a >> b >> c;
	double d = a * 0.2 + b * 0.3 + c * 0.5;
	printf("%d", int(d));
	return 0;
}