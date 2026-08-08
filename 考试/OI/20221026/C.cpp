#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int qwe=1e6+5;
int n,m;
vector<int> e[qwe];
struct Edge{
	int u,v,w;
	Edge()=default;
	Edge(int a,int b,int c){
		u=a,v=b,w=c;
	}
};
struct SegmentTree{
	int c[qwe];
	void add(int p,int x){
		while(p<qwe){
			c[p]+=x;
			p+=(p&-p);
		}
	}
	int query(int x){
		int ans=0;
		while(x){
			ans+=c[x];
			x-=(x&-x);
		}
		return ans;
	}
} t;
vector<Edge> edge[qwe];
int siz[qwe],fa[qwe];
int dfn[qwe],id[qwe],cnt=0,dep[qwe];
int tp[qwe],son[qwe];
int f[qwe],g[qwe];
void dfs(int u,int fa){
	siz[u]=1;
	::fa[u]=fa;
	dep[u]=dep[fa]+1;
	for(auto v:e[u]){
		// int v=V.first;
		if(v==fa){
			continue;
		}
		dfs(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}
void dfss(int u,int fa,int tp){
	dfn[++cnt]=u;
	id[u]=cnt;
	::tp[u]=tp;
	if(son[u]){
		dfss(son[u],u,tp);
	}
	for(auto v:e[u]){
		// int v=V.first;
		if(v==fa || v==son[u]){
			continue;
		}
		dfss(v,u,v);
	}
}
int lth(int l,int r){
	int ans=0;
	while(tp[l]!=tp[r]){
		ans+=t.query(id[l])-t.query(id[tp[l]]-1);
		l=fa[tp[l]];
	}
	ans+=t.query(id[l])-t.query(id[r]);
	return ans;
}
void dfsss(int u){
	for(auto v:e[u]){
		// int v=V.first;
		if(v==fa[u]){
			continue;
		}
		dfsss(v);
		f[u]+=g[v];
	}
	g[u]=f[u];
	for(auto V:edge[u]){
		g[u]=max(g[u],lth(V.u,u)+lth(V.v,u)+f[u]+V.w);
	}
	t.add(id[u],f[u]-g[u]);
}
int lca(int x,int y){
	while(tp[x]!=tp[y]){
		if(dep[tp[x]]<dep[tp[y]]){
			swap(x,y);
		}
		x=fa[tp[x]];
	}
	if(dep[x]>dep[y]){
		swap(x,y);
	}
	return x;
}
int main(){
	freopen("paths.in","r",stdin);
	freopen("paths.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	dfs(1,0);
	dfss(1,0,1);
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		int tmp=lca(a,b);
		edge[tmp].emplace_back(a,b,c);
	}
	dfsss(1);
	cout<<g[1]<<endl;
	return 0;
}
