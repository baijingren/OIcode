#include<bits/stdc++.h>
using namespace std;
const int qwe=100005;
int m,n,cnt=0;
int hd[qwe];
struct EDGE{
    
}
void add(int u,int v){//从0开始建边
    edge[cnt].nxt=hd[u];
    edge[cnt].to=v;
    hd[u]=cnt;
    cnt++;
    return;
}
int main(){
    freopen("/home/bai/code/test.in", "r", stdin);
    freopen("/home/bai/code/test.out", "w", stdout);
    scanf("%d",&n,&m);
    for(int i=1;i<=n;i++){
        int u,v;
        scanf("%d",&u,&v);
        add(u,v);
    }
    return 0;
}
