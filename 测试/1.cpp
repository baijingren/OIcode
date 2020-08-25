<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
int n,m,X,Y,Z,id,s,t,u,v;
int to[4000010];
int wi[4000010];
int ne[4000010];
int po[4000010];
int vis[4010];
double dis[4000];
queue<int> q;
inline void add(int x,int y,int z)
{
    id++;
    to[id]=y;
    wi[id]=z;
    ne[id]=po[x];
    po[x]=id;
}
void spfa()
{
    for (int i=0;i<=n+1;i++) dis[i]=23333333.0;
    q.push(s);
    dis[s]=100.0;
    vis[s]=1;
    while (!q.empty())
    {
        u=q.front();q.pop();
        vis[u]=0;
        for (int i=po[u];i;i=ne[i])
        {
            v=to[i];
            if (dis[v]>(double)(dis[u])/(1-0.01*wi[i]))//松弛操作
            {
                dis[v]=(double)(dis[u])/(1-0.01*wi[i]);
                if (vis[v]==0)//入队
                {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d%d", &n, &m);
    int uu, vv;
    double ww;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%lf", &uu, &vv, &ww);
        add(uu, vv, ww);
        add(vv, uu, ww);
    }
    scanf("%d%d", &t, &s);
    spfa();
    printf("%.8lf",dis[t]);
    return 0;
=======
void dij()
{
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (int i = hd[u]; i != -1; i = edge[i].nxt)
        {
            int v = edge[i].nxt;
            if (dis[u] + edge[i].w < dis[v])
            {
				secondmin = min;
				dis[v] = dis[u] + edge[i].w;
				q.push(NODE(dis[v], v));
            }
        }
    }
>>>>>>> 54968d54e06c8c200387462b01be1223bac46373
}