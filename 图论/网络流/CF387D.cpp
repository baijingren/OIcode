#include <bits/stdc++.h>
using namespace std;
#define edge G.e
const int qwe = 2e4 + 5;
int n, m, v, ans = INT_MAX;
int s = 0, t = 2e4 + 4;

struct Graph
{
    int cnt = 1;
    int hd[qwe], in[qwe], out[qwe];
    struct Edge
    {
        int nxt, to, w, from;
    } e[qwe];
    void add(int u, int v, int w)
    {
        e[++cnt].nxt = hd[u];
        e[cnt].to = v;
        e[cnt].w = w;
        hd[u] = cnt;
    }
    void add(int u,int v){
        // e[++cnt].nxt = hd[u];
        cnt++;
        e[cnt].to = v;
        e[cnt].from = u;
        // hd[u] = cnt;
    }
};
Graph G, graph;
class Dinic
{
private:
    int dis[qwe], cur[qwe]; 
    int bfs()
    {
        queue<int> q;
        memset(dis, 0, sizeof(dis));
        dis[s] = 1;
        q.push(s);
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (int i = G.hd[u]; i; i = edge[i].nxt)
            {
                int v = edge[i].to;
                if (!dis[v] && edge[i].w > 0)
                {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        return dis[t];
    }
    int dfs(int u = s, int flow = INT_MAX)
    {
        int ret = 0;
        if ((u == t) || !flow)
        {
            return flow;
        }
        for (int &i = cur[u]; i; i = edge[i].nxt)
        {
            int v = edge[i].to, d;
            if (dis[v] == dis[u] + 1 && edge[i].w > 0 && (d = dfs(v, min(flow, edge[i].w))))
            {
                edge[i].w -= d;
                edge[i ^ 1].w += d;
                ret += d;
                flow -= d;
            }
        }
        return ret;
    }
public:
    int dinic()
    {
        int maxflow = 0;
        //cerr<<"0:dinic()\n";
        while (bfs())
        {
            //cerr<<"1:bfs()\n";
            int tmp = 0;
            memcpy(cur, G.hd, sizeof(G.hd));
            while (tmp = dfs())
            {
                //cerr<<"2:dfs()="<<tmp<<'\n';
                maxflow += tmp;
            }
        }
        return maxflow;
    }
    void build(){
        G.cnt = 1;
        memset(G.hd, 0, sizeof(G.hd));
        for(int i = 1; i <= n; i++){
            if(i == ::v)
                continue;
            G.add(s, i, 1);
            G.add(i, s, 0);
        }
        for(int i = n + 1; i <= n * 2; i++){
            if(i == ::v + n)
                continue;
            G.add(i, t, 1);
            G.add(t, i, 0);
        }
        // cerr<<"var:graph.cnt = "<<graph.cnt<<'\n';
        for(int i = 2; i <= graph.cnt; i++){
            if(graph.e[i].to == ::v || graph.e[i].from == ::v){
                continue;
            }
            G.add(graph.e[i].from, graph.e[i].to + n, 1);
            G.add(graph.e[i].to + n, graph.e[i].from, 0);
        }
    }
};
Dinic dinic;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph.add(u, v);
        graph.in[v]++;
        graph.out[u]++;
        if(u == v){
            graph.in[v]--;
        }
    }
    for(int i = 1; i <= n; i++){
        ::v = i;
        int tmp = 2 * n - 1 - graph.in[::v] - graph.out[::v];
        // cerr<<"var:tmp = "<<tmp<<'\n';
        dinic.build();
        int maxflow = dinic.dinic();
        // cerr<<"var:maxflow = "<< maxflow<<'\n';
        int tmpt = (m - graph.in[::v] - graph.out[::v] - maxflow) + (n - 1 - maxflow);
        // cerr<<"var:tmpt = "<<tmpt<<'\n'
        //    <<"var: m - graph.in[::v] - graph.out[::v] = "<<m - graph.in[::v] - graph.out[::v]<<'\n';
        ans = min(ans, tmp + tmpt);
    }
    cout << ans << endl;
}