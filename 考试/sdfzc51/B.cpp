#include <bits/stdc++.h>
using namespace std;
const int qwe = 5e3 + 5;
int n, m, ans = 0, cnt = 0;
int a[qwe], b[qwe];
int f[qwe][qwe];
int px[qwe][qwe], py[qwe][qwe];
// int low[qwe][qwe];
void otp(int x, int y)
{
    if (!f[x][y])
    {
        // cout<<1;
        return;
    }
    int vx = px[x][y], vy = py[x][y];
    // if(vx && vy){
    otp(vx, vy);
    // }
    if (f[x][y] != f[vx][vy] && y)
    {
        printf("%d ", b[y]);
        cnt++;
        if (cnt == ans)
        {
            printf("\n");
            return;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
    }
    memset(px, -1, sizeof(px));
    memset(py, -1, sizeof(py));
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        // int cnt=0;
        int x = 0, y = 0;
        for (int j = 1; j <= m; j++)
        {
            // if(a[i]!=b[j]){
            f[i][j] = f[i - 1][j];
            // }
            px[i][j] = i - 1;
            py[i][j] = j;
            if (b[j] < a[i] && tmp < f[i - 1][j])
            {
                tmp = f[i - 1][j];
                x = i - 1;
                y = j;
                // cout<<a[i]<<' '<<b[j]<<' '<<i<<endl;
                // low[i][++cnt]=a[i];
            }
            else if (a[i] == b[j])
            {
                f[i][j] = tmp + 1;
                px[i][j] = x;
                py[i][j] = y;
            }
        }
        // cout<<endl;
    }
    int flag = 0;
    for (int i = 1; i <= m; i++)
    {
        if (ans <= f[n][i])
        {
            ans = max(ans, f[n][i]);
            flag = i;
        }
    }
    printf("%d\n", ans);
    if (ans > 0)
    {
        otp(n, flag);
    }
    return 0;
}