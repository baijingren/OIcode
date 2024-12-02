#include<bits/stdc++.h>
using namespace std;
const int qwe=1e5+5;
const int mod=1e9+7;
int n,k;
int a[qwe];
int f[qwe][105][2][2],tmp[105][2][2];
vector<int> e[qwe];
int siz[qwe];
void dfs(int u,int fa){
    siz[u]=f[u][0][0][0]=f[u][1][1][0]=1;
    for(int v:e[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
        for(int i=0;i<=min(siz[u],k);i++){
            tmp[i][0][0]=f[u][i][0][0];
            tmp[i][0][1]=f[u][i][0][1];
            tmp[i][1][0]=f[u][i][1][0];
            tmp[i][1][1]=f[u][i][1][1];
            f[u][i][0][0]=0;
            f[u][i][0][1]=0;
            f[u][i][1][0]=0;
            f[u][i][1][1]=0;
        }
        for(int i=0;i<=min(siz[u],k);i++){
            for(int j=0;j<=min(siz[v],k-i);j++){
                f[u][i+j][0][0]=(f[u][i+j][0][0]+(1ll*tmp[i][0][0]*f[v][j][0][1]%mod)%mod)%mod;
                f[u][i+j][0][1]=(f[u][i+j][0][1]+(1ll*tmp[i][0][1]*(f[v][j][0][1]+f[v][j][1][1])%mod)%mod)%mod;
                f[u][i+j][0][1]=(f[u][i+j][0][1]+(1ll*tmp[i][0][0]*f[v][j][1][1]%mod)%mod)%mod;
                f[u][i+j][1][0]=(f[u][i+j][1][0]+(1ll*tmp[i][1][0]*(f[v][j][0][1]+f[v][j][0][0])%mod)%mod)%mod;
                f[u][i+j][1][1]=(f[u][i+j][1][1]+(1ll*tmp[i][1][0]*(f[v][j][1][0]+f[v][j][1][1])%mod)%mod)%mod;
                f[u][i+j][1][1]=(f[u][i+j][1][1]+(1ll*tmp[i][1][1]*(1ll*f[v][j][0][0]+1ll*f[v][j][0][1]+1ll*f[v][j][1][0]+1ll*f[v][j][1][1])%mod)%mod)%mod;
            }
        }
        siz[u]+=siz[v];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    cout<<(f[1][k][0][1]+f[1][k][1][1])%mod<<'\n';
    return 0;
}