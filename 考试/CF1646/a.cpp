#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10; 
ll n,m;
ll a[N],p[N];
bool b[N];
ll power(ll a,int b){
	ll ans=1;
	for(;b;b>>=1){
		if(b&1) ans*=a;
		a*=a;
	}
	return ans;
}
ll ans=1;
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=2;i<=n;i++){
		if(!b[i]){
			ll tmp=1;
			ans+=m;
			for(ll j=1;j<=m;j++){
				tmp*=i;
				if(tmp>n) break;
				b[tmp]=1;
//				a[tmp]=i;
//				p[tmp]=j;
				a[tmp]=max(a[tmp],(m*1ll)/(j*1ll));
			}
		}
		else{
			ans+=m-a[i];
			ll tmp=power(i,a[i]);
			for(ll j=a[i]+1;j<=m;j++){
				tmp*=i;
				if(tmp>n) break;
				b[tmp]=1;
//				a[tmp]=i;
//				p[tmp]=j;
				a[tmp]=max(a[tmp],(m*1ll)/(j*1ll));
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}