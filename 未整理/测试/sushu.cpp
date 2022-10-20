#include<bits/stdc++.h>
using namespace std;
// const int qwe = 10000 * 10000 / 2;
const int qwe = 10000;
bool vis[qwe];
int f[qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int ans = 0;
    for (int i = 2; i <= qwe; i++)
    {
        if(!vis[i])
        {
            f[++ans] = i;
            for (int j = 1; i * j <= qwe; j++)
            {
                vis[i * j] = 1;
            }
        }
    }
    for (int i = 1; i <= ans; i++)
    {
        printf("%d, ", f[i]);
    }
    printf("\n%d", ans);
    return 0;
}