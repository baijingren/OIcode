#include<bits/stdc++.h>
using namespace std;
const int N=3e5+2,M=6e5+2;
int n,m,cnt=0,t;
int hd[N],d[N],dist[N],s[N];
int f[N][25];
bool vis[N];
struct EDGE{
    int to,nxt,w;
} edge[M];
struct TASK{
    int fom,to,lca,dis;
} task[N];
void add(int u,int v,int w){
    cnt++;
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].nxt=hd[u];
    hd[u]=cnt;
}
queue<int> q;
int lca(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	for(int i=t;i>=0;i--){
		if(d[f[x][i]]>=d[y]) x=f[x][i];
	}
	if(x==y) return x;
	for(int i=t;i>=0;i--){
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
void dfs(int u){//
	for(int i=hd[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[v]) continue;
		vis[v]=1;
		dfs(v);
		s[u]+=s[v];
	}
	return;
}
bool chk(int x){
	int cnt=0,ans=INT_MIN;
	// bool vv=0;
	memset(s,0,sizeof(s));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++){
		if(task[i].dis>x){
			s[task[i].fom]++;
			s[task[i].to]++;
			s[task[i].lca]-=2;
			ans=max(ans,task[i].dis);
			// vv=1;
			cnt++;
		}
	}
	if(cnt==0) return true;
	vis[1]=1;
	dfs(1);
	for(int i=1;i<=n;i++){
		if(s[i]==cnt&&ans-(dist[i]-dist[f[i][0]])<=x) return 1;
	}
	return 0;
}
int main(){
    freopen("/home/bai/code/test.in", "r", stdin);
    scanf("%d%d",&n,&m);
    t=log2(n);
    for(int i=1;i<=n-1;i++){
        int u,v,w;
        scanf("%d%d%d", &u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    q.push(1);
	d[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=hd[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(d[v]) continue;
			q.push(v);
			f[v][0]=u;
			dist[v]=dist[u]+edge[i].w;
			d[v]=d[u]+1;
			for(int j=1;j<=t;j++){
				f[v][j]=f[f[v][j-1]][j-1];
			}
		}
	}
	int mx=INT_MIN;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&task[i].fom,&task[i].to);
        // if()
		task[i].lca=lca(task[i].fom,task[i].to);
		task[i].dis=dist[task[i].fom]+dist[task[i].to]-2*dist[task[i].lca];
		mx=max(mx,task[i].dis);
    }
    int l=1,r=mx;
	while(l<r){
		int mid=(l+r)/2;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d",l);
	/*
	*/
}