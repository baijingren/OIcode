#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <bits/stdc++.h>

using namespace std;
const int qwe = 15;

int n;
// char s[qwe], t[qwe];
int m;
int a[qwe][qwe];

double ans[5];
int main()
{
	long long n = 1e18;
	for(int i = 1; i <= 64; i++){
		if(pow(2, i) > n){
			long long ans = ((long long)pow(2,i) - 1);
			cout << ans << endl;
			// cout << (long long)pow(2, i) - 1 << endl;
			cout << (long long)(1ll << 60) << endl;
			break;
		}
	}
	return 0;
}