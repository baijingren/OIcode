#include<bits/stdc++.h>
using namespace std;
const int qwe=1e3+5;
int n,m;
int a[qwe],in[qwe],out[qwe];

int hd[qwe],cnt=1;
struct Edge{
    int to,nxt,w;
} edge[qwe];
#define to(i) edge[i].to
#define nxt(i) edge[i].nxt
#define w(i) edge[i].w
void add(int u,int v,int w){
    cnt++;
    nxt(cnt)=hd[u];
    to(cnt)=v;
    w(cnt)=w;
    hd[u]=cnt;
}

int s,t;
int dep[qwe],cur[qwe];
queue<int> q;
bool bfs(){
    memset(dep,0,sizeof(dep));
    while(!q.empty()) q.pop();
    q.push(s);
    cur[s]=
}

int main(){
    scanf("%d%d",n,m);
    s=0,t=n+1;
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        out[u]++;
        in[v]++;
        if(u==v){
            in[v]--;
        }
        // add(u,v,1);
        // add(v,u,0);
    }
    for(int i=1;i<=n;i++){
        memset(hd,0,sizeof(hd));;
        cnt=1;
        int tmp=in[i]+out[i];
        for(int j=1;j<=n;j++){

        }
        int mxflow=0;
        while(bfs()){
            int flow=0;
            while(flow=dinic()){
                mxflow+=flow;
            }
        }
    }
    printf("%d",&n);
}