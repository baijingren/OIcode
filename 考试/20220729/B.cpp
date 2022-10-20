#include <bits/stdc++.h>
using namespace std;
const int qwe = 3e3 + 5;
const int inf = 0x3f3f3f3f;
int n, m;
vector<int> e[qwe];
int dis[qwe][qwe];
queue<int> q;
bool vis[qwe];
vector<pair<int, int>> a[qwe], b[qwe];
struct ANS
{
    int val = 0;
    int a, b, c, d;
} ans;
void spfa(int s)
{
    memset(vis, 0, sizeof(vis));
    while (!q.empty())
        q.pop();
    q.push(s);
    dis[s][s] = 0;
    vis[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int v : e[u])
        {
            if (dis[s][v] > dis[s][u] + 1)
            {
                dis[s][v] = dis[s][u] + 1;
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v);
        // e[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        spfa(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (dis[i][j] != inf)
            {
                a[i].emplace_back(dis[i][j], j);
            }
            if (dis[j][i] != inf)
            {
                b[i].emplace_back(dis[j][i], j);
            }
        }
        sort(a[i].begin(), a[i].end(), [](pair<int, int> a, pair<int, int> b)
             { return a.first > b.first; });
        sort(b[i].begin(), b[i].end(), [](pair<int, int> a, pair<int, int> b)
             { return a.first > b.first; });
    }
    for (int j = 1; j <= n; j++)
    {
        for (int k = 1; k <= n; k++)
        {
            if (j == k || dis[j][k] == inf)
            {
                continue;
            }
            for (int I = 0; I <= 2 && I < b[j].size(); I++)
            {
                int i = b[j][I].second;
                if (i == j || i == k)
                {
                    continue;
                }
                for (int L = 0; L <= 2 && L < a[k].size(); L++)
                {
                    int l = a[k][L].second;
                    if (l == i || l == j || l == k)
                    {
                        continue;
                    }
                    if (ans.val < dis[i][j] + dis[j][k] + dis[k][l])
                    {
                        ans = {dis[i][j] + dis[j][k] + dis[k][l], i, j, k, l};
                    }
                    // cerr<<"DEBUG:"<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<ans.val<<' '<<dis[i][j]<<' '<<dis[j][k]<<' ' <<dis[k][l]<<endl;
                }
            }
        }
    }
    // cout << ans.a << ' ' << ans.b << ' ' << ans.c << ' ' << ans.d << '\n';
    cout << ans.val << '\n';
    return 0;
}