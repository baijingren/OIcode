#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e4 + 5;
int n, m, s = 0, t = 10001;
string B[qwe], S[qwe];

int hd[qwe], cnt = 1;
struct Edge
{
    int nxt, to, w;
} edge[qwe];

class buildGraph
{
    int cnt_B[qwe], cnt_S[qwe];
    int w_B[qwe], w_S[qwe];
    int op[10][2] = {
        {1, 7},
        {1, 8},
        {2, 8},
        {2, 10},
        {3, 9},
        {3, 10},
        {4, 6},
        {4, 7},
        {5, 6},
        {5, 9}};
    int OP[15][15];
    void add(int u, int v, int w)
    {
        edge[++cnt].nxt = hd[u];
        edge[cnt].to = v;
        edge[cnt].w = w;
        hd[u] = cnt;
    }
    int mp(string s, int cnt)
    {
        int ret = 0;
        if (s == "J")
        {
            ret = 1;
        }
        else if (s == "HK")
        {
            ret = 2;
        }
        else if (s == "W")
        {
            ret = 3;
        }
        else if (s == "YYY")
        {
            ret = 4;
        }
        else if (s == "E")
        {
            ret = 5;
        }
        return ret + cnt * 5;
    }

public:
    void input()
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> B[i];
            cnt_B[mp(B[i], 0)]++;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> S[i];
            cnt_S[mp(S[i], 0)]++;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> w_B[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> w_S[i];
        }
    }
    int tmp_1(int a)
    {
        if (mp(B[a], 0) == 1)
        {
            return cnt_B[4];
        };
        return 0;
    }
    int tmp_2(int a)
    {
        if (S[a] == "J")
        {
            return cnt_S[4];
        }
        return 0;
    }
    void init()
    {
        memset(OP, 0, sizeof(OP));
        for (int i = 1; i <= n; i++)
        {
            add(s, i, w_B[i] + tmp_1(i));
            add(i, s, 0);
        }
        for (int i = 1; i <= n; i++)
        {
            add(i + n, t, w_S[i] + tmp_2(i));
            add(t, i + n, 0);
        }
        for (int i = 0; i < 10; i++)
        {
            OP[op[i][0]][op[i][1]] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (OP[mp(B[i], 0)][mp(S[j], 1)])
                {
                    add(i, j + n, 1);
                    add(j + n, i, 0);
                }
            }
        }
    }
};

class Dinic
{
    int cur[qwe], dep[qwe], flow[qwe], ans = 0;
    int bfs()
    {
        queue<int> q;
        memset(dep, 0, sizeof(dep));
        // dep[s] = 1;
        q.push(s);
        dep[s] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = hd[u]; i; i = edge[i].nxt)
            {
                int v = edge[i].to;
                if (!dep[v] && edge[i].w > 0)
                { // 需要记得修改残量网络
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return dep[t];
    }
    int dfs(int u = s, int flow = INT_MAX)
    {
        int ret = 0;
        if (!flow || (u == t))
        {
            return flow;
        }
        for (int& i = cur[u]; i; i = edge[i].nxt)
        {
            // cur[u] = i;
            int v = edge[i].to, d;
            if (dep[v] == dep[u] + 1 && edge[i].w > 0 && (d = dfs(v, min(edge[i].w, flow))))
            {
                edge[i].w -= d;
                edge[i ^ 1].w += d;
                ret += d;
                flow -= d; // 这行有什么用
            }
        }
        return ret;
    }

public:
    void dinic()
    {
        while (bfs())
        {
            memcpy(cur, hd, sizeof(hd));
            int d = 0;
            while (d = dfs())
            {
                ans += d;
                // cerr << ans << endl;
            }
        }
        cout << min(ans, m) << endl;
        // cerr << ans << endl;
        return;
    }
};

buildGraph b;
Dinic dinic;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    b.input();
    b.init();
    dinic.dinic();
}