#include<bits/stdc++.h>
using namespace std;
int m, num;
float t, s;
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %f %f", &m, &t, &s);
    num = int(ceil(s / t)) ;
    if (num>m)
    {
        printf("0");
        return 0;
    }

    printf("%d", m - num);
    return 0;
}