#include<bits/stdc++.h>
using namespace std;
const int qwe=1005;
int n,p,cnt,ans;
int hd[qwe],s[qwe],du[qwe],fa[qwe],d[qwe],mx[qwe];
bool vis[qwe];
struct EDGE{
    int nxt,to;
} edge[qwe];
void add(int u,int v){
    cnt++;
    edge[cnt].to=v;
    edge[cnt].nxt=hd[u];
    hd[u]=cnt;
}
void dfs(int u,int fat,int dep){
    d[u]=dep;
    fa[u]=fat;
    s[u]=1;
    for(int i=hd[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fat) continue;
        dfs(v,u,dep+1);
        s[u]+=s[v];
    }
}
void dfss(int u,int fat){
    vis[u]=1;
    for(int i=hd[u];i;i=edge[i].nxt){
        int v=edge[i].to;
        if(v==fat) continue;
        dfss(v,u);
    }
}
void dfsss(int u){
        
}
int main(){
    scanf("%d%d",&n,&p);
    ans=n;
    for(int i=1;i<=p;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        // add(v,u);
        fa[v]=u;
        du[u]++;
    }
    /*
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!du[i]){
            q.push(i);
            // vis[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        s[i]=1;
    }
    // q.push(1);
    // // vis[1]=1;
    // while(!q.empty()){
    //     int u=q.front();
    //     q.pop();
    //     // vis[u]=1;
    //     for(int i=hd[u];i;i=edge[i].nxt){
    //         int v=edge[i].to;
    //         s[v]+=s[u];
    //         // if(vis[v]) continue;
    //         q.push(v);
    //         vis[v]=1;
    //     }
    //     int v=fa[u];
    //     s[v]+=s[u];
        
    //     if(!vis[v]){
    //         q.push(v);
    //         vis[v]=1;
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     // cout<<mx[i]<<endl;
    //     cout<<d[i]<<endl;
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<' ';
    //     cout<<s[i]<<endl;
    // }
    // for(int i=1;)
    // memset(vis,0,sizeof(vis));
    q.push(1);
    vis[1]=1;
    // int mxid=0;
    // s[0]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        // if(u==mxid){
        //     continue;
        // }
        for(int i=hd[u];i;i=edge[i].nxt){
            int v=edge[i].to;
            if(vis[v]) continue;
            q.push(v);
            // if(s[mxid]<s[v]){
            //     cout<<mxid<<' '<<s[mxid]<<' '<<v<<' '<<s[v]<<' '<<ans<<endl;
            //     mxid=v;
            // }
            d[v]=d[u]+1;
            fa[v]=u;
            
            // mx[d[v]]=max(s[v],mx[d[v]]);
        }
        // ans-=s[mxid];
        // mxid=0;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<' '<<d[i]<<' '<<mx[i]<<endl;
    // }
    */
    printf("%d",ans);
    return 0;
}
