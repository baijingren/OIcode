#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int qwe = 1e6+5;

int n;
int pos[qwe],val[qwe];
int now[qwe];

int cnt = 0,hd[qwe];
struct Edge{
    int to,nxt;
} edge[qwe];
void add(int u,int v){
    edge[++cnt].to = v;
    edge[cnt].nxt = hd[u];
    hd[u] = cnt;
    return;
}

int fa[qwe],son[qwe];
void dfs1(int u,int f){
    for(int i=hd[u];i;i=edge[i].nxt){
        int v = edge[i].to;
        if(!fa[v]){
            fa[v] = u;
            dfs1(v,u);
            if(!son[u]){
                son[u]=v;
            }
        }
    }
}

int ans[qwe],cntt = 0;
void dfs2(int u,int f){
    ans[++cntt] = u;
    if(son[u])
        dfs2(son[u],u);
    for(int i=hd[u];i;i=edge[i].nxt){
        int v = edge[i].to;
        if(son[u] != v){
            dfs2(v,u);
        }
    }
}

void init(){
    cnt = 0,cntt = 0;
    memset(hd,0,sizeof(hd));
    memset(now,0,sizeof(now));
    memset(fa,0,sizeof(fa));
    memset(son,0,sizeof(son));
    return;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        init();

        for(int i=1;i<=n;i++){
            scanf("%d%d",&pos[i],&val[i]);
            add(now[pos[i]],val[i]);
            now[pos[i]+1] = val[i];
        }

        dfs1(0,0);
        dfs2(0,0);

        for(int i=2;i<=cntt;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }

    return 0;
}