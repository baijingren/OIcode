#include<bits/stdc++.h>
using namespace std;
const int qwe=100005;
int n,cnt;
int a[qwe],hd[qwe];
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
bool chk(int x){
    
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
}