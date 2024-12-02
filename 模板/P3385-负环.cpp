#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
#define PII pair<int, int>
int n, m, T;
vector<PII> e[qwe];
queue<int> q;
int dis[qwe], cnt[qwe];
bool vis[qwe];
bool spfa(int st)
{
    while (!q.empty())
    {
        q.pop();
    }
    memset(vis,0,sizeof(vis));//******
    memset(dis, 0x3f, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));//注意多测清空（尤其是边）
    q.push(st);
    vis[st] = 1;
    dis[st] = 0;
    cnt[st] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto V : e[u])
        {
            int v = V.first;
            if (dis[v] > dis[u] + V.second)
            { //不管是否在队列中，都要更新dis
                dis[v] = dis[u] + V.second;
                /*
                法1：在经过最短路的情况下，最多经过m-1条边（即记录从u到v最短路经过的边数）（当有重边的时候可能被HACK）
                cnt[v] = cnt[u] + 1; 
                if (cnt[v] >= m)
                {
                    return false;
                }
                */
               //法2：统计入队次数，当一个点入队n次以上，则此处是一个负环
                if (!vis[v])
                {
                    if(++cnt[v]>=n){
                        return false;
                    }
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            e[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            e[u].emplace_back(v, w);//注意题目是有向边还是无向边
            if(w>=0){//本题特殊情况：当w>=0时，会建立无向边
                e[v].emplace_back(u,w);
            }
            // e[v].emplace_back(u, w);
        }
        if (spfa(1))
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}