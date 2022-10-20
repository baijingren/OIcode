#include<bits/stdc++.h>
using namespace std;
const int qwe=30005;
int n,m,cnt;
int hd[qwe],in[qwe],out[qwe];
struct EDGE{
    int to,nxt;
}edge[qwe];
void add(int u,int v){
    cnt++;
    edge[cnt].to=v;
    edge[cnt].nxt=hd[u];
    hd[u]=cnt;
}
queue<int> q;
void topsort(){
    for(int i=1;i<=n;i++){
        if(out[i]==0){
            q.push(i);
        }
        int k=0;
        for(int i=1;)
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        in[v]++;
        out[u]++;
    }
    topsort();
}