#include<bits/stdc++.h>
using namespace std;
#define to(i) edge[i].to
#define nxt(i) edge[i].nxt
#define w(i) edge[i].w
#define ml(it) multiset<int>::iterator it
multiset<int> 
const int qwe=1e6+5;
int n,cnt=0,tail=0;
int a[qwe],hd[qwe],q[qwe];
struct EDGE{
    int to,nxt,w;
}edge[qwe];
void add(int u,int v,int w){
    cnt++;
    edge[cnt].to=v;
    edge[cnt].nxt=u;
    edge[cnt].w=w;
    hd[u]=cnt;
}
void dfs(int u){
    
}
bool chk(int x){
    dfs(x)
    return false;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(chk(mid)) l=mid;
        else r=mid;
    }
}