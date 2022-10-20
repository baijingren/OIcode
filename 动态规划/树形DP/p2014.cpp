#include<bits/stdc++.h>
using namespace std;
const int qwe=2e4+5;
int n,m,cnt;
int hd[qwe];
int f[qwe][qwe];
struct EDGE{
    int to,nxt;
} edge[qwe];
void add(int u,int v){
    cnt++;
    edge[cnt].to=v;
    edge[cnt].nxt=hd[u];
    hd[u]=cnt;
}
void dp(int u){
    for(int i=hd[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        dp(v);
        for(int j=m+1;j>=1;j--){
            for(int k=0;k<j;k++){
                f[u][j]=max(f[v][k]+f[u][j-k],f[u][j]);
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int fa;
        scanf("%d%d",&fa,&f[i][1]);
        add(fa,i);
    }
    dp(0);
    printf("%d\n",f[0][m+1]);
    return 0;
}