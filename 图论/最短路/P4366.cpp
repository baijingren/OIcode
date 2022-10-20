#include<bits/stdc++.h>
using namespace std;
#define PII Node
#define MP(a,b) Node(a,b)
const int qwe=1e6+5;
int n,m,c;
int cnt=0,hd[qwe];
struct Edge{
    int to,nxt,w,u;
} edge[qwe];
void add(int u,int v,int w){
    cnt++;
    edge[cnt].nxt=hd[u];
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].u=u;
    hd[u]=cnt;
}
int dist[qwe];
bool vis[qwe];
// priority_queue<PII> q;
// bool operator>(PII a,PII b){
//     return a.second<b.second;
// }
struct Node{
    int a,b;
    Node(int _a,int _b){
        a=_a,b=_b;
    }
    bool operator< (const Node &y)const
    {
        return b>y.b;
    }
};
priority_queue<Node> q;
void dij(int x){
    memset(dist,0x3f,sizeof(dist));
    memset(vis,0,sizeof(vis));
    dist[x]=0;
    q.push(MP(x,0));
    while(!q.empty()){
        auto k=q.top();
        q.pop();
        int u=k.a;
        if(!vis[u]){
            // if(dist[v])
            vis[u]=1;
            for(int i=hd[u];i;i=edge[i].nxt){
                int v=edge[i].to;
                if(dist[v]>dist[u]+edge[i].w){
                    dist[v]=dist[u]+edge[i].w;
                    // cout<<'a'<<' '<<v<<endl;
                    q.push(MP(v,dist[v]));
                }
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=1;j<=20;j++){
    //         int k=i^(1<<j);
    //         if(k<=n){
    //             add(i,k,c*(1<<j));
    //         }
    //     }
    // }
    for(int i=0;i<=n;i++) 
    {
        for(int j=1;j<=n;j<<=1) 
        {
            if((i^j)>n) continue;
            add(i,i^j,j*c);
        }
    }
    int a,b;
    scanf("%d%d",&a,&b);
    dij(a);
    printf("%d",dist[b]);
}