#include<bits/stdc++.h>
using namespace std;
#define to(i) edge[i].to
#define nxt(i) edge[i].nxt
const int qwe=2e3+5;
int n, cnt=0;
int a[qwe],hd[qwe];
int f[qwe][10];
struct Edge{
    int to,nxt;
} edge[qwe];
void add(int u,int v){
    cnt++;
    to(cnt)=v;
    nxt(cnt)=hd[u];
    hd[u]=cnt;
}
void dfs(int u,int fa){
// void dfs(int u){
    f[u][0]=1;
    f[u][3]=0;
    f[u][4]=0;
    for(int i=hd[u];i;i=nxt(i)){
        int v=to(i);
        if(fa==v) continue;
        dfs(v,u);
        // dfs(v);
        f[u][0]+=f[v][4];
        f[u][3]+=f[v][2];
        f[u][4]+=f[v][3];
    }
    // if(!hd[u]){
    //     f[u][1]=f[u][2]=1;
    // }
    // else{
        f[u][1]=f[u][2]=INT_MAX;
        for(int i=hd[u];i;i=nxt(i)){
            int v=to(i);
            if(v==fa) continue;
            int f1=f[v][0];
            int f2=f[v][1];
            for(int j=hd[u];j;j=nxt(j)){
                if(i==j) continue;
                int k=to(j);
                f1+=f[k][3];
                f2+=f[k][2];
            }
            f[u][1]=min(f[u][1],f1);
            f[u][2]=min(f[u][2],f2);
        }
    // }
    if(f[u][1]==INT_MAX&&f[u][2]==INT_MAX){
        f[u][1]=f[u][2]=1;
    }
    for(int i=1;i<=4;i++){
        f[u][i]=min(f[u][i],f[u][i-1]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        scanf("%d",&a[i]);
        add(i,a[i]);
        add(a[i],i);
    }
    dfs(1,0);
    // dfs(1);
    printf("%d",f[1][2]);
}