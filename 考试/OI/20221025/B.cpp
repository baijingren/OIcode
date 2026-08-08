#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
struct Edge{
    int u,v,l,r;
} e[qwe];
int cnt=0;
// int ans,num;
pair<int,int> ans;
void add(int u,int v,int l,int r){
    e[++cnt]={u,v,l,r};
}
int fa[qwe];
int fnd(int x){
    if(fa[x]==x){
        return x;
    }
    else return fa[x]=fnd(fa[x]);
}
int tmp[qwe];
void calc(int x){
    sort(e+1,e+x+1,[](Edge a,Edge b){
        return a.r>b.r;
    });
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=x;i++){
        int tempa=fnd(e[i].u);
        int tempb=fnd(e[i].v);
        if(tempa==tempb){
            continue;
        }
        fa[tempa]=tempb;
        if(fnd(1)==fnd(n)){
            ans=max(ans,make_pair(e[i].r-tmp[x]+1,-tmp[x]));
            return;
        }
    }
}
int main(){
    freopen("silence.in","r",stdin);
    freopen("silence.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,l,r;
        cin>>u>>v>>l>>r;
        add(u,v,l,r);
        // add(v,u,l,r);
    }
    // for(int i=1;i<=n;i++){
    //     fa[i]=i;
    // }
    sort(e+1,e+m+1,[](Edge a,Edge b){
        return a.l<b.l;
    });
    for(int i=1;i<=m;i++){
        tmp[i]=e[i].l;
    }
    for(int i=1;i<=m;i++){
        calc(i);
    }
    // for(int i=1;i<=num;i++){
    //     cout<<i-ans-1;
    // }
    cout<<ans.first<<'\n';
    for(int i=1;i<=ans.first;i++){
        cout<<i-ans.second-1<< ' ';
    }
    cout<<endl;
    return 0;
}