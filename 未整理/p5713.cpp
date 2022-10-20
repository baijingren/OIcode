#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &n);
    if (n >= 5.5)
    {
        printf("Luogu");
    }
    else
    {
        printf("Local");
    }

    return 0;
}