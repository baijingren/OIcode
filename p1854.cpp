#include<bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int F, V;
int f[qwe][qwe], a[qwe][qwe];
int main()
{
    freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
    scanf("%d %d", &F, &V);
    for(int i = 1; i <= F; i++)
    {
        for(int j = 1; j <= V; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= F; i++)
    {
        for(int j = i; j <= V-F+i; j++)
        {
            // f[i][j] = max(f[i][j - 1], f[i - 1][j - 1] + a[i][j]);
            if(f[i][j - 1] > f[i - 1][j - 1] + a[i][j])
            {
                f[i][j] = f[i][j - 1];
                s[i][j] = j;
            }
            else
            {
                f[i][j] = f[i - 1][j - 1] + a[i][j];
                s[i][j] = j - 1;
            }
        }
    }
    printf("%d", f[F][V]);
    return 0;
}