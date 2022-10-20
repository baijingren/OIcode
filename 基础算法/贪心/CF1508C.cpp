#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
const int qwe=2e5+5;
int n,m;
int x=0;
ll ans=0;
ll cnt=0;
struct Edge{
    int u,v,w;
    Edge(){}
    Edge(int a,int b,int c){
        u=a,v=b,w=c;
    }
} edge[qwe];
int t[qwe];
// vector<int> p;
// void insert(int x){
//     for(int b:p){
//         x=min(x,x^b);
//     }
//     for(int &b:p){
//         b=min(b,x^b);
//     }
//     if(x){
//         p.emplace_back(x);
//     }
// }
int fa[qwe];
int fnd(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=fnd(fa[x]);
}
int vis[qwe];
queue<int> q;
set<int> temp,e[qwe];
// vector<int> e[qwe];
void work(){
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            q.emplace(i);
            vis[i]=1;
            fa[i]=i;
            temp.erase(i);
            while(!q.empty()){
                int u=q.front();
                q.pop();
                // for(int v:temp){
                for(auto it=temp.begin();it!=temp.end();){
                    int v=*it;
                    it++;
                    if(e[u].count(v)){
                        continue;
                    }
                    temp.erase(prev(it));
                    fa[v]=u;
                    vis[v]=1;
                    q.emplace(v);
                    cnt--;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    cnt=1ll*n*(n-1)/2-m;
    for(int i=1;i<=n;i++){
        temp.insert(i);
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[i]={u,v,w};
        e[u].insert(v);
        e[v].insert(u);
        x^=w;
    }
    sort(edge+1,edge+1+m,[](Edge a,Edge b){
        return a.w<b.w;
    });
    work();
    // for(int i=1;i<=n;i++){
    //     fa[i]=i;
    // }
    for(int i=1;i<=m;i++){
        int x=fnd(edge[i].u),y=fnd(edge[i].v);
        if(x==y){
            continue;
        }
        fa[y]=x;
        ans+=edge[i].w;
        t[i]=1;
    }
    if(cnt>0){
        cout<<ans<<'\n';
        return 0;
    }
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    int mn=INT_MAX;
    for(int i=1;i<=m;i++){
        int x=fnd(edge[i].u),y=fnd(edge[i].v);
        if(x==y){
            continue;
        }
        fa[y]=x;
        if(!t[i]){
            mn=edge[i].w; 
            break;
        }
    }
    cout<<ans+min(x,mn)<<'\n';
    return 0;
}
/*
4 4
2 1 14
1 4 14
3 2 15
4 3 8
*/
/*
g++ 'CF1508C.cpp' -o 'CF1508C' -g -std=c++14 -O2 -fsanitize=address,undefined && "/home/bai/code/基础算法/贪心/"CF1508C
cd "/home/bai/code/基础算法/贪心/" && g++ 'CF1508C.cpp' -o 'CF1508C' -Wall -g -std=c++14 -lm -O2 -fsanitize=address,undefined && "/home/bai/code/基础算法/贪心/"CF1508C
*/