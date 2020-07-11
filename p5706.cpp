#include <bits/stdc++.h>
using namespace std;
double t;
int n;
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%lf %d", &t, &n);
    printf("%.3lf %d", t / n, n * 2);
    return 0;
}