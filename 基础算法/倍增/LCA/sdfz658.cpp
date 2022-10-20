#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,s,cnt,t;
int hd[qwe], d[qwe],du[qwe];
int f[qwe][25];
struct EDGE{
    int nxt,to;
} edge[qwe];
void add(int u, int v){
    cnt++;
    edge[cnt].nxt=hd[u];
    edge[cnt].to=v;
    hd[u]=cnt;
    return;
}
int lca(int x,int y){
    // if(d[x]<d[y]) swap(x,y);
    // for(int i=t;i>=0;i--){
    //     if(d[f[x][i]]>=d[y]) x=f[x][i];
    // }
    // if(x == y) return x;
    // for(int i=t;i>=0;i--){
    //     if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    // }
    // return f[x][0];
    queue<int> q;
    q.push(x);
    
}
int main(){
    // freopen("/home/bai/code/test.in", "r", stdin);
    int T=0;
    scanf("%d",&T);
    while(T--){
        // scanf("%d%d%d", &n,&m,&s);
        memset(d,0,sizeof(d));
        memset(hd,0,sizeof(0));
        memset(edge,0,sizeof(edge));
        memset(f,0,sizeof(f));
        // memset(du,0,sizeof(du));
        // queue<int> q;
        cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n-1;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            // add(u,v);
            add(v,u);
            du[v]++;
        }
        int s;
        for(int i=1;i<=n;i++){
            if(du[i]==0){
                s=i;
                break;
            }
        }
        // q.push(s);
        // d[s]=1;
        // // q.push(1);
        // // d[1]=1;
        // t=log2(n);
        // while(!q.empty()){
        //     int u = q.front();
        //     q.pop();
        //     for(int i = hd[u];i;i=edge[i].nxt){
        //         int v=edge[i].to;
        //         if(d[v]) continue;
        //         d[v]=d[u]+1;
        //         f[v][0]=u;
        //         for(int j = 1;j <= t;j++){
        //             f[v][j]=f[f[v][j-1]][j-1];
        //         }
        //         q.push(v);
        //     }
        // }
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",lca(x,y));
    }
    return 0;
}