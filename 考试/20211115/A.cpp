#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int qwe=1e7+1e2+5;
ull n,m;
ll ans=0;
int cnt=0;
bool vis[qwe];
int s[qwe],mn[qwe],g[qwe];
ll sq[qwe];
void shai(){
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            s[++cnt]=i;
            mn[i]=cnt;
            g[i]=1;
        }
        for(int j=1;j<=cnt;j++){
            int k=s[j]*i;
            if(k>n) break;
            vis[k]=1;
            mn[k]=j;
            if(mn[i]==j) break;//?
            g[k]=g[i];
        }
    }
}
int main(){
    scanf("%llu%llu",&n,&m);
    mn[1]=vis[1]=g[1]=1;
    shai();
    ll pn,pm,t;
    pn=pm=t=ceil(sqrt(max(n,m)))+1;//n,m较大值的因数个数？
    for(int i=1;i<=t;i++){
        sq[i]=sq[i-1]+i*2-1;
    }
    for(int i=1;i<=n;i++){
        if(g[i]){
            ll l=n/i,r=m/i;
            while(sq[pn]>l) pn--;
            while(sq[pm]>r) pm--;
            if(pm%2==0){
                ans+=pn;
            }
            else{
                ans-=pn;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
//1~n n为奇数，结果奇数；n为偶数，结果偶数。