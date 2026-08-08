#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int, ll>
const int qwe = 1e6 + 5;
int n, m, s, t;
vector<PII> e[qwe];
ll dis[qwe];
struct Node
{
    int x;
    ll y;
    explicit Node(int x = 0, ll y = 0)
    {
        this->x = x;
        this->y = y;
    }
    bool operator<(const Node &a) const
    {
        return this->y > a.y;
    }
};
priority_queue<Node> q;
bool vis[qwe];
void dij()
{
    memset(dis, 0x3f, sizeof(dis));
    q.emplace(s, 0);
    dis[s] = 0;
    while (!q.empty())
    {
        int u = q.top().x;
        q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = 1;
        for (auto V : e[u])
        {
            int v = V.first;
            if (dis[v] > dis[u] + V.second)
            {
                dis[v] = dis[u] + V.second;
                if (!vis[v])
                {
                    q.emplace(v, dis[v]);
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
    cin >> n >> m >> s>>t;     
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].emplace_back(v, w);
        // e[v].emplace_back(u, w);
    }
    dij();
    if(dis[t]==0x3f3f3f3f3f3f3f3f){
        dis[t]=-1;
    }
    cout << dis[t] << endl;
    return 0;
}