#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,s,t;
int hd[qwe],cnt=1;
struct Edge{
    int to,nxt,c,d;
}edge[qwe];
#define nxt(i) edge[i].nxt
#define to(i) edge[i].to
#define c(i) edge[i].c
#define d(i) edge[i].d
void add(int u,int v,int c,int d){
    cnt++;
    nxt(cnt)=hd[u];
    to(cnt)=v;
    c(cnt)=c;
    d(cnt)=d;
    hd[u]=cnt;
}
int dep[qwe],cur[qwe];
queue<int> q;
bool bfs(){
    memset(dep,0,sizeof(dep));
    while(!q.empty()) q.pop();
    q.push(s);
    dep[s]=1;
    cur[s]=hd[s];
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=hd[u];i;i=nxt(i)){
            int v=to(i);
            if(w(i) && !dep[v]){
                dep[v]=dep[u]+1;
                q.push(v);
                cur[v]=hd[v];
                if(v==t){
                    return 1;
                }
            }
        }
        return 0;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int u,v,c,d;
        scanf("%d%d%d%d",&u,&v,&c,&d);
        add(u,v,c,d);
        add(v,u,0,INT_MAX);
    }
}