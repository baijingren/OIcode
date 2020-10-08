#include <bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n, m;
int a[qwe][qwe];
int stx, sty, edx, edy;
char c;
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d ", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &c);
            if (c == '.')
            {
                a[i][j] = 0;
            }
            else if (c == '*')
            {
                a[i][j] = 1;
            }
            else if (c == 'a')
            {
                stx = j;
                sty = i;
                a[i][j] = 0;
            }
            else if (c == 'b')
            {
                edx = j;
                edy = i;
                a[i][j] = 0;
            }
        }
        scanf(" ");
    }
    int x = stx, y = sty;
    int ans = 0;
    while (scanf("%c", &c) != EOF)
    {
        int ux, uy;
        if (c == 'w')
        {
            uy = y - 1;
            if (uy >= 0 && a[x][uy] == 0)
            {
                y = uy;
                ans++;
            }
            else
            {
                printf("%d", ans);
                break;
            }
        }
        if (c == 'a')
        {
            ux = x - 1;
            if (ux >= 0 && a[ux][y] == 0)
            {
                x = ux;
                ans++;
            }
            else
            {
                printf("%d\n", ans);
                break;
            }
        }
        if (c == 's')
        {
            uy = y + 1;
            if (uy >= 0 && a[x][uy] == 0)
            {
                y = uy;
                ans++;
            }
            else
            {
                printf("%d", ans);
                break;
            }
        }
        if (c == 'a')
        {
            ux = x + 1;
            if (ux >= 0 && a[ux][y] == 0)
            {
                x = ux;
                ans++;
            }
            else
            {
                printf("%d\n", ans);
                break;
            }
        }
    }
    return 0;
}