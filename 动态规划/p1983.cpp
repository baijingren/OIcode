#include<bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n, m;
int s[qwe];
int a[qwe][qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &s[i]);
        for (int j = 1; j <= s[i]; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}