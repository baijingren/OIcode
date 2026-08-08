#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define MP make_pair
const int qwe=1e6+5;
int n,m,X,t;
vector<PII> e[qwe];
int fa[qwe],dep[qwe],f[qwe][21];
queue<int> q;
int lca(int x,int y){
    if(dep[x]<dep[y]){
        swap(x,y);
    }
    for(int i=t;i>=0;i--){
        if(dep[f[x][t]]>=dep[y]){
            x=f[x][t];
        }
    }
    if(x==y){
        return x;
    }
    for(int i=t;i>=0;i--){
        if(dep[f[x][t]]!=dep[f[y][t]]){
            x=f[x][t],y=f[y][t];
        }
    }
    return f[x][0];
}
int sol(int op,int x,int y,char *c){
    if(X==1){
        if(op==1){
            
        }
        else{
            
        }
    }
}
int a[qwe],nxt[qwe];
char b[qwe];
void work(char *c){
    int n=strlen(c+1);
    for(int i=2,j=0;i<n;i++){
        while(j>0 && c[j]!=c[i+1]){
            j=nxt[j];
        }
        if(c[j]==c[i+1]){
            j++;
        }
        nxt[i]=j;
    }
}
void sol1(){
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        int op,x,y;
        scanf("%d%d%d%s",&op,&x,&y,b+1);
        if(op==1){
            for(int j=0;j<y-x;j++){
                a[j+x]=(b[j+1]-'0');
            }
        }
        else{
            work(b);
            for(int i=1,j=0;i<=y-x;i++){
                while(j>0 && (b[j]-'0')!=a[i+1]){
                    j=nxt[j];
                }
                if((b[j]-'0')==a[i+1]){
                    j++;
                }
            }
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&X);
    bool flag=1;
    for(int i=1;i<n;i++){
        // int x;
        scanf("%d ",&fa[i]);
        if(fa[i]!=i-1){
            flag=0;
        }
    }
    if(flag){
        sol1();
        return 0;
    }
    for(int i=2;i<=n;i++){
        int x;
        scanf("%1d",&x);
        e[i].push_back(MP(fa[i],x));
        e[fa[i]].push_back(MP(i,x));
    }
    q.push(1);
    dep[1]=1;
    t=log2(n);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto V:e[u]){
            int v=V.first;
            if(dep[v]){
                continue;
            }
            dep[v]=dep[u]+1;
            f[v][0]=u;
            for(int i=1;i<=t;i++){
                f[v][i]=f[f[v][i-1]][i-1];
            }
        }
    }
    for(int i=1;i<=m;i++){
        int op,x,y;
        scanf("%d%d%d%s",&op,&x,&y,b+1);
        sol(op,x,y,b);
    }
    return 0;
}