#include<bits/stdc++.h>
using namespace std;
int n, s, ans = INT_MAX;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s);
        ans = min(s, ans);
    }
    printf("%d", ans);
    return 0;
}