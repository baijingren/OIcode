#include <bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n, m;
int a[qwe][qwe];
int stx, sty, edx, edy;
bool vis[qwe][qwe];
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
    int ans = 1;
    while (scanf("%c", &c) != EOF)
    {
        int ux, uy;
        if (c == 'w')
        {
            uy = y - 1;
            if (uy >= 0 && a[uy][x] == 0)
            {
                y = uy;
                ans++;
                vis[x][y] = 1;
            }
            else
            {
                break;
            }
        }
        if (c == 'a')
        {
            ux = x - 1;
            if (ux >= 0 && a[y][ux] == 0)
            {
                x = ux;
                ans++;
                vis[x][y] = 1;
            }
            else
            {
                break;
            }
        }
        if (c == 's')
        {
            uy = y + 1;
            if (uy >= 0 && a[uy][x] == 0)
            {
                y = uy;
                ans++;
                vis[x][y] = 1;
            }
            else
            {
                break;
            }
        }
        if (c == 'd')
        {
            ux = x + 1;
            if (ux >= 0 && a[y][ux] == 0)
            {
                x = ux;
                ans++;
                vis[x][y] = 1;
            }
            else
            {
                break;
            }
        }
        if (vis[edx][edy] == 1)
        {
            printf("%d\n", ans);
            printf("YES");
            return 0;
        }
    }

    printf("%d\nNO", ans);
    return 0;
}
/*
0
0a0 1a0 2a0 
1
0a0 1a1 2a1 
2
0a0 1a0 2a0 
3
0a1 1a1 2a0 
4
0a0 1a0 2a0 
5
0a0 1a1 2a1 
6
0a0 1a0 2a0 
7
0a1 1a1 2a0 
8
0a1 1a1 2a1 
9
0a1 1a1 2a1 
*/