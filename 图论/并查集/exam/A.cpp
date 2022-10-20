#include<bits/stdc++.h>
using namespace std;
const int qwe=50005;
int n,ans,m;
int fa[qwe*3];
int fnd(int u){
	if(fa[u]==u) return u;
	return fa[u]=fnd(fa[u]);
}
void add(int u,int v){
	int x=fnd(u),y=fnd(v);
	// if(x==y) return;
	fa[x]=y;
}
int b[qwe];
int main(){
	scanf("%d%d",&n,&m);
	int tot=0;
    for(int i=1;i<=3*n;i++){
        fa[i]=i;
    }
	for (int i=1;i<=m;++i){
        int u,v,e;
		scanf("%d%d%d",&e,&u,&v);
        // cout<<'a';
        if(u>n||v>n){
            ans++;
            continue;
        }
        // cout<<'a';
		if(e==1){
            if(fnd(u+n)==fnd(v)||fnd(v+n)==fnd(u)){
                ans++;
                // continue;
            }else{
            add(u,v);
            add(u+n,v+n);
            add(u+2*n,v+2*n);
            }
        }else{
            if(fnd(u)==fnd(v)||fnd(u)==fnd(v+n)){
                ans++;
                // continue;
            }else{
            add(u+n,v);
            add(u+2*n,v+n);
            add(u,v+2*n);
            }
        }
	}
    printf("%d",ans);
	return 0;
}