#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e5+5;

int cnt=0;
int hd[qwe];
struct Edge{
    int to,nxt,w;
} edge[qwe];
void add (int u, int v, int w)
{
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].nxt=hd[u];
    hd[u]=cnt;
}

int n;

queue<pair<int,int> > q;
void dij(){
    q.push(make_pair(1,0));
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }

    dij();

    return 0;
}