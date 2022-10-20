#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e6+5;
int n,q,t,ans;
int rt;
ll _ans;
vector<int> e[qwe];
queue<int> p;
int dep[qwe];
int f[qwe][32];
int query(int x,int y){
    int t=y;
    for(int i=::t;i>=0;i--){
        int temp=abs(dep[f[x][i]]-dep[x]);
        if(temp<=t){
            t-=temp;
            x=f[x][i];
        }
    }
    // for(;t;t-=(t&-t)){
    //     x=f[x][(int)log2(t&-t)];
    // }
    return x;
}
#define ui unsigned int
ui s;
inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x; 
}
int main(){
    freopen("/home/bai/code/test.in","r",stdin);
    freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d%d%u",&n,&q,&s);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x==0){
            rt=i;
        }
        else{
            e[i].push_back(x);
            e[x].push_back(i);
        }
    }
    p.push(rt);
    dep[rt]=1;
    t=log2(n);
    while(!p.empty()){
        int u=p.front();
        p.pop();
        for(auto v:e[u]){
            if(dep[v]){
                continue;
            }
            dep[v]=dep[u]+1;
            f[v][0]=u;
            p.push(v);
            for(int i=1;i<=t;i++){
                f[v][i]=f[f[v][i-1]][i-1];
            }
        }
    }
    // }
    // for(int i=1;i<=n;i++){
    //     cerr<<dep[i]<<' ';
    // }
    for(int i=1;i<=q;i++){
        int x=(get(s)^ans)%n+1;
        int y=(get(s)^ans)%dep[x];
        ans=query(x,y);
        // cout<<x<<' '<<y<<' '<<ans<<endl;
        // printf("%d",ans);
        // _ans=(_ans^(i*ans));
        _ans^=(1ll*i*ans);
    }
    printf("%lld",_ans);
}