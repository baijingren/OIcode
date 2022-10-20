#include<bits/stdc++.h>
using namespace std;
const int qwe=1000005;
int n;
int fa[qwe];
struct A{
	int v,u,e;
} a[qwe];
int fnd(int u){
	if(fa[u]==u) return u;
	return fa[u]=fnd(fa[u]);
}
void add(int u,int v){
	int x=fnd(u),y=fnd(v);
	if(x==y) return;
	fa[x]=y;
}
bool cmp(A x,A y){
	return x.e>y.e;
}
int b[qwe];
int main(){
    freopen("/home/bai/code/test.in", "r", stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		memset(fa,0,sizeof(fa));
		scanf("%d",&n);
		int tot=0;
		for (int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].e);
			b[++tot]=a[i].u;
			b[++tot]=a[i].v;
		}
		sort(b+1,b+1+tot);
		int tott=unique(b+1,b+1+tot)-b;
		for (int i=1;i<=n;++i){
			a[i].u=lower_bound(b+1,b+1+tott,a[i].u)-b;
			a[i].v=lower_bound(b+1,b+1+tott,a[i].v)-b;
		}
		for(int i=1;i<=tott;i++) fa[i]=i;
		sort(a+1,a+n+1,cmp);
		bool p=0;
		for(int i=1;i<=n;i++){
			if(a[i].e==1){
				add(a[i].u,a[i].v);
			}
			else{
				int x=fnd(a[i].u),y=fnd(a[i].v);
				if(x==y){
					p=1;
					break;
				}
			}
		}
		if(p!=1){
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}