#include<bits/stdc++.h>
using namespace std;
queue<int> qax, qay, qbx, qby;
int n, m, mp[5005][5005];
int xp[4] = {1, -1, 0, 0};
int yp[4] = {0, 0, 1, -1};
int vis[5005][5005], s[5005][5005];
bool chk(int x, int y)
{
    if (x>=0&&y>=0&&x<=m&&y<n)
    {
        return true;
    }
    return false;
}
void bfs()
{
    qax.push(1);
    qay.push(1);
    qbx.push(m);
    qby.push(n);
    s[qax.front()][qay.front()] = 0;
    s[qbx.front()][qby.front()] = 0;
    vis[qax.front()][qay.front()] = 1;
    vis[qbx.front()][qby.front()] = 2;
    while ((qax.size() && qay.size()) || (qbx.size() && qby.size()))
    {
        int ux = qax.front(), uy = qay.front();
        qax.pop();
        qay.pop();
        for (int i = 0; i < 4; i++)
        {
            int vx = ux + xp[i], vy = uy + yp[i];
            if (!chk(vx, vy))
            {
                continue;
            }
            if (vis[vx][vy]==2)
            {
                printf("%d", s[vx][vy] + s[ux][uy] + 1);
                exit(0);
            }
            if (!mp[vx][vy])
            {
                qax.push(vx);
                qay.push(vy);
                s[vx][vy] = s[ux][uy] + 1;
                vis[vx][vy] = 1;
            }
        }
        ux = qbx.front(), uy = qby.front();
        qbx.pop();
        qby.pop();
        for (int i = 0; i < 4; i++)
        {
            int vx = ux + xp[i], vy = uy + yp[i];
            if (!chk(vx, vy))
            {
                continue;
            }
            if (vis[vx][vy]==1)
            {
                printf("%d", s[vx][vy] + s[ux][uy] + 1);
                exit(0);
            }
            if (!mp[vx][vy])
            {
                qbx.push(vx);
                qby.push(vy);
                s[vx][vy] = s[ux][uy] + 1;
                vis[vx][vy] = 2;
            }
        }
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &mp[n][m]);
        }
    }
    bfs();
    printf("wo tai nan le");
    return 0;
}