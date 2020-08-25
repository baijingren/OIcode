#include<bits/stdc++.h>
using namespace std;
int na, nb, ma, mb;
int main()
{
    freopen("/home/baijingren/Desktop/编程/test.in", "r", stdin);
    freopen("/home/baijingren/Desktop/编程/test.out", "w", stdout);
    scanf("%d/%d", &na, &ma);
    scanf("%d/%d", &nb, &mb);
    int ansn = na * nb;
    int ansm = ma * mb;
    int t = __gcd(ansn, ansm);
    printf("%d %d", ansn / t, ansm / t);
    return 0;
}