#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
double k,ans;
int cnt=0,hd[qwe];
struct Edge{
    int u,v;
    double w;
} edge[qwe];
int fa[qwe];
int find(int x){
    if(fa[x]==x){
        return x;
    }
    return fa[x]=find(fa[x]);
}
int main(){
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }
    if(n==1 && k!=0){
        cout<<"-1.000000\n";
        return 0;
    }
    sort(edge+1,edge+m+1,[](Edge a,Edge b){
        return a.w>b.w;
    });
    double mn=1e9;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        int x=find(edge[i].u),y=find(edge[i].v);
        if(x==y){
            continue;
        }
        fa[y]=x;
        cnt++;
        // cerr<<ans<<endl;
        ans+=edge[i].w;
        mn=min(mn,edge[i].w);
    }
    if(cnt<n-1){
        if(k==0){
            ans=-1;
        }
        else{
            ans+=k;
        }
    }
    else if(cnt==n-1){
        ans=ans-min(mn,k)+k;
    }
    else{
        ans+=k;
    }
    cout<<std::fixed<<setprecision(6)<<ans<<'\n';
    return 0;
}