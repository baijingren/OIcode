#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,s,t,cnt=0;
int a[qwe],b[qwe];
int hd[qwe];
int c[qwe][3],h[1005][1005];
struct Edge{
    int to,nxt,w;
} edge[qwe];
#define nxt(i) edge[i].nxt
#define to(i) edge[i].to
#define w(i) edge[i].w
void add(int u,int v,int w){
    cnt++;
    nxt(cnt)=hd[u];
    to(cnt)=v;
    w(cnt)=w;
    hd[u]=cnt;
}
int dep[qwe],cur[qwe];
queue<int> q;
bool bfs(){
    memset(dep,0,sizeof(dep));
    while(!q.empty()) q.pop();
    q.push(s);
    cur[s]=hd[s];
    dep[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=hd[u];i;i=nxt(i)){
            int v=to(i);
            if(!dep[v] && w(i)){
                dep[v]=dep[u]+1;
                q.push(v);
                if(v==t){
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    s=n+n+1,t=n+n+2;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        add(i,t,a[i]);
        add(t,i,0);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
        add(i+n,t,b[i]);
        add(t,i+n,0);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int k;
        scanf("%d",&k);
        scanf("%d",&c[i][1],&c[i][2]);
        for(int j=1;j<=k;j++){
            scanf("%d",&h[i][j]);
            add(h[i][j-1],h[i][j],)
            a
        }
    }

}