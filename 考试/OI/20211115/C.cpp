#include<bits/stdc++.h>
using namespace std;
#define to(i) edge[i].to
#define nxt(i) edge[i].nxt
#define tc(i) edgec[i].to
#define nc(i) edgec[i].nxt
const int qwe=1e6+5;
int n,m,cnt=-1,num=0,root=0,cntc=-1,dcc=0;
int hd[qwe],low[qwe],dfn[qwe],bridge[qwe],hc[qwe],c[qwe];
struct Edge{
    int to,nxt;
} edge[qwe],edgec[qwe];
void add(int u,int v){
    cnt++;  
    to(cnt)=v;
    nxt(cnt)=hd[u];
    hd[u]=cnt;
}
void addc(int u,int v){
    cntc++;
    tc(cntc)=v;
    nc(cntc)=hc[u];
    hc[u]=cntc;
}
stack<int> s;
vector<int> dcc[qwe];
void tarjan(int u,int in_edge){
    dfn[u]=low[u]=++num;
    // s.push(u);
    // int flag=0;
    for(int i=1;i<=n;i++){
        int v=to(i);
        // if(dfn[v]){
            // continue;
        // }
        if(!dfn[v]){
            tarjan(v,i);
            low[u]=min(low[v],low[u]);
		    if (low[v]>dfn[u]) {
                bridge[i]=bridge[i^1]=1;
		    	// flag++;
		    	// if (u!=root||flag>1) cut[u]=true;
		    	// cnt++;
		    	// int z;
		    	// while (z != v){
                // do{
		    		// z = s.top();
                    // s.pop();
		    		// dcc[cnt].push_back(z);
		    	// }
                // }while (z != v);
		    	// dcc[cnt].push_back(u);
		    }
        }
        else if(i==(in_edge^1)){
            low[u] = min(low[u], dfn[v]);
        }
    }
}
void dfs(int u){
    c[u]=dcc;
    for(int i=hd[u];i<=n;i++){
        int v=to(i);
        if(c[v]||bridge[i]) continue;
        dfs(v);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    for(int i=1;i<=n;i++){
        if(dfn[i]) continue;
        // root=i;
        tarjan(i,0);
    }
    for(int i=1;i<=n;i++){
        if(!c[i]){
            dcc++;
            dfs(i);
        }
    }
    // num=cnt;
    // for(int i=2;i<=cnt;i+=2){
    //     if(bridge[i]){
    //         new_id[i]=++num;
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j< dcc[i].size();j++){
    //         int x=dcc[i][j];
    //         if(cut[x]){
    //             addc(i,)
    //         }
    //     }
    // }
    for(int i=0;i<=cnt;i++){
        int x=to(i^1),y=to(i);
        if(c[x]==c[y]) continue;
        addc(c[x],c[y]);
        addc(c[y],c[x]);
    }
    
}