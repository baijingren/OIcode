#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,ll>
#define ll long long
const int qwe=1e6+5;
namespace INPUT_SPACE{
	const int S=(1<<20)+5;char B[S],*H,*T;inline int gc() { if(H==T) T=(H=B)+fread(B,1,S,stdin);return (H==T)?EOF:*H++; }
	inline unsigned int inn() { unsigned int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';while((ch=gc())>='0'&&ch<='9') x=x*10+(ch^'0');return x; }
}using INPUT_SPACE::inn;
int n;
ll a[qwe];
vector<PII> e[qwe];
int siz[qwe];
ll f[qwe],g[qwe];
void dfs(int u,int fa){
	siz[u]=1;
	for(auto V:e[u]){
		int v=V.first;
		if(v==fa){
			continue;
		}
		dfs(v,u);
		siz[u]+=siz[v];
		f[u]+=(f[v]+siz[v]*V.second);
	}
	f[u]-=(siz[u]-1)*a[u];
}
void dfss(int u,int fa){
	for(auto V:e[u]){
		int v=V.first;
		if(v==fa){
			continue;
		}
		g[v]=g[u]-siz[v]*(V.second-a[u])+(n-siz[v])*(V.second-a[v]);
		//9-2*(3-2)+(4-2)*(3-1)
		dfss(v,u);
	}
}
int main(){
//	cerr<<'a';
	freopen("fryderyk.in","r",stdin);
	freopen("fryderyk.out","w",stdout);
	n=inn();
	for(int i=1;i<=n;i++){
		a[i]=inn();
	}
//	cerr<<'b';
	for(int i=1;i<n;i++){
		int u,v;
		ll w;
		u=inn();
		v=inn();
		w=inn();
		e[u].emplace_back(v,w);
		e[v].emplace_back(u,w);
	}
	dfs(1,0);
	g[1]=f[1];
	dfss(1,0);
	int ans=1;
	for(int i=1;i<=n;i++){
		// cerr<<g[i]<<' ';
		if(g[i]<g[ans]){
			ans=i;
		}
	}
	cout<<ans<<endl<<g[ans]<<endl;
	return 0;
}
