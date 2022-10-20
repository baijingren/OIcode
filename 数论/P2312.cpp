#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll qwe=1e6+5;
const ll P=1000000007;
ll n,m,cnt=0;
ll a[qwe],ans[qwe];
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            y=-1;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x*=10;
        x+=(ll)(ch-'0');
        x%=P;
        ch=getchar();
    }
    return x*y;
}
ll calc(ll x){
    ll sum=0;
    for(int i=n;i>=1;i--){
        sum=((a[i]+sum)*x)%P;
    }
    sum=(a[0]+sum)%P;
    return sum;
}
int main(){
    // scanf("%lld%lld",&n,&m);
    n=read();
    m=read();
    for(int i=0;i<=n;i++){
        // scanf("%lld",&a[i]);
        a[i]=read();
    }
    int cntt=0;
    for(int i=1;i<=m;i++){
        // cout<<calc(i)<<endl;
        if(!calc(i)){
            cnt++;
            ans[++cntt]=i;
        }
    }
    printf("%lld\n",cnt);
    if(cnt==0){
        return 0;
    }
    for(int i=1;i<=cntt;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}