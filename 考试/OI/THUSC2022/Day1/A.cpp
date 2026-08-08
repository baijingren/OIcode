#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, double>
const int qwe = 1e6 + 5;
int n, m, k, sx, ed;
PII a[qwe];
struct Edge
{
    int to, nxt, u, w, ls, mr;
} e[qwe];
int cnt, hd[qwe];
void add(int u, int v, int w, int l, int r)
{
    cnt++;
    e[cnt].u = u;
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].ls = l;
    e[cnt].mr = r;
    e[cnt].nxt = hd[u];
    hd[u] = cnt;
}
vector<int> road;
bool dfs(int u, int fa)
{
    if (u == ed)
    {
        return 1;
    }
    for (int i = hd[u]; i; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        bool k = dfs(v, u);
        if (k)
        {
            road.push_back(i);
            return 1;
        }
    }
    return 0;
}
double anss, sm;
void sol()
{
    dfs(sx, 0);
    int k = road.size();
    for (int i = 1; i <= ::k; i++)
    {
        int t = a[i].first;
        int ans = 0;
        for (int j = k - 1; j >= 0; j--)
        {
            if (t == 0)
            {
                ans += e[road[j]].w * e[road[j]].mr;
                continue;
            }
            if (e[road[j]].w > t)
            {
                int T = 0;
                T = e[road[j]].w - t;
                ans += t * e[road[j]].ls;
                ans += T * e[road[j]].mr;
                t = 0;
            }
            else
            {
                t -= e[road[j]].w;
                ans += e[road[j]].w * e[road[j]].ls;
            }
        }
        anss += (double)(ans)*a[i].second / sm;
    }
}
int main()
{
    scanf("%d%d%d%d%d", &n, &m, &k, &sx, &ed);
    for (int i = 1; i <= m; i++)
    {
        int u, v, l, r, w;
        scanf("%d%d%d%d%d", &u, &v, &w, &l, &r);
        add(u, v, w, l, r);
        add(v, u, w, l, r);
    }
    sm = 0;
    for (int i = 1; i <= k; i++)
    {
        int x;
        scanf("%d%d", &a[i].first, &x);
        sm += (double)x;
        a[i].second = (double)x;
    }
    if (m == n - 1)
    {
        sol();
        printf("%.12lf", anss);
        return 0;
    }
    return 0;
}