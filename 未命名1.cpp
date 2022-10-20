#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define N 1000005
using namespace std;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll T,n,m,k,Mod=1e9+7,a[N],dp[N],b[N];
ll pw(ll x,ll p){
	ll res=1;
	while(p){
		if(p&1)res=res*x%Mod;
		x=x*x%Mod;
		p>>=1;
	}
	return res;
}
ll C(ll x,ll y){
	if(x<y||x<0||y<0)return 0;
	return a[x]*b[y]%Mod*b[x-y]%Mod;
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read(),k=read();
		a[0]=1;
		rep(i,1,n)a[i]=a[i-1]*i%Mod;
		b[n]=pw(a[n],Mod-2);
		per(i,n-1,1)b[i]=b[i+1]*(i+1)%Mod;
		dp[0]=1;
		rep(i,1,n)dp[i]=dp[i-1]*((Mod+1)/2)%Mod;
		b[0]=1;
		ll ans=0;
		rep(i,1,n-1)ans=ans+C(n-i-1,m-i)*dp[n-i]%Mod*i%Mod,ans%=Mod;
		if(m==n)ans=n;
		printf("%lld\n",ans*k%Mod);
	}
	return 0;
}