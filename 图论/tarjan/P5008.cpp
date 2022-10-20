#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,k;
int w[qwe];
int hd[qwe],cnt=1;
struct Edge{
    int nxt,to;
}edge[qwe];
#define nxt(i) edge[i].nxt
#define to(i) edge[i].to
void add(int u,int v){
    cnt++;
    nxt(cnt)=hd[u];
    to(cnt)=v;
    hd[u]=cnt;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        add(u,v);
    }
    tarjan
}