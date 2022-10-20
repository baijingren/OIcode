#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=2e6+5;
int n,q,rt,t,cnt;
int ans;
ll _ans;
int pos[qwe],id[qwe],top[qwe],dep[qwe],h[qwe],up[qwe];
int son[qwe];
int Log[qwe];
int f[qwe][32];
#define ui unsigned int
ui s;
inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x; 
}
vector<int> e[qwe];
void dfs(int u){
    for(int i=1;i<=19;i++){
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(int v:e[u]){
        // if(dep[v]){
        //     continue;
        // }
        dep[v]=dep[u]+1;
        h[v]=dep[v];
        // cerr<<u<<' '<<v<<' '<<son[u]<<endl;
        dfs(v);
        h[u]=max(h[u],h[v]);
        if(h[v]>h[son[u]]){
            son[u]=v;
        }
    }
}
void dfs2(int u,int fa){
    id[u]=++cnt;
    pos[cnt]=u;
    up[cnt]=fa;
    if(son[u]){
        top[son[u]]=top[u];
        dfs2(son[u],f[fa][0]);
    }
    for(int v:e[u]){
        if(v==son[u]){
            continue;
        }
        top[v]=v;
        dfs2(v,v);
    }
}
int query(int x,int y){
    if(!y){
        return x;
    }
    x=f[x][Log[y]];
    y-=(1<<Log[y]);
    y-=dep[x]-dep[top[x]];
    x=top[x];
    if(y>=0){
        return up[id[x]+y];
    }
    return pos[id[x]-y];
}
int main(){
    freopen("/home/bai/code/test.in","r",stdin);
    freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d%d%u",&n,&q,&s);
    Log[0]=-1;
    for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        f[i][0]=x;
        if(!x){
            rt=i;
        }
        else{
            e[x].push_back(i);
            // e[i].push_back(x);
        }
    }
    t=log2(n);
    dep[rt]=1;
    dfs(rt);
    top[rt]=rt;
    dfs2(rt,rt);
    for(int i=1;i<=n;i++){
        cerr<<dep[i]<<' ';
    }
    for(int i=1;i<=q;i++){
        int x=(get(s)^ans)%n+1;
        int y=(get(s)^ans)%dep[x];
        ans=query(x,y);
        cerr<<x<<' '<<y<<' '<<ans<<endl;
        _ans^=(1ll*i*ans);
    }
    printf("%lld",_ans);
    return 0;
}
//25 11 93 173 !2