#include <bits/stdc++.h>
using namespace std;
const int qwe = 200005;
int cnt, hd[qwe], n, m, s, dis[qwe];
struct Edge
{
    int nxt, to, w;
} edge[qwe];
void add(int u, int v, int w)
{
    cnt++;
    edge[cnt].nxt = v;
    edge[cnt].to = u;
    edge[cnt].w = w;
    hd[u] = cnt;
}
void bf()
{
    dis[s] = 0;
    bool flag;
    for (int i = 1; i <= n; i++)
    {
        flag = false;
        for (int j = 1; j <= cnt; j++)
        {
            int x, y;
            x = edge[j].nxt;
            y = edge[j].to;
            if (dis[x] > dis[y] + edge[j].w)
            {
                dis[x] = dis[y] + edge[j].w;
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &s);
    memset(dis, 0x3f, sizeof(dis));
    int uu, vv, ww;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &uu, &vv, &ww);
        add(uu, vv, ww);
    }
    bf();
    for (int i = 0; i < n; i++)
    {
        if (dis[i + 1] == 1061109567)
        {
            printf("2147483647 ");
        }

        printf("%d ", dis[i + 1]);
    }
    return 0;
}
//60point