#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,a[500005],aa[500005],shang;
long long ans;
int main(){
	freopen("rrads2.in","r",stdin);
	freopen("rrads.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){ scanf("%d",&a[i]);aa[a[i]]=i;}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&l,&r);
		shang=0;ans=0;
		for(int j=1;j<=n;++j){
			if(aa[j]>=l&&aa[j]<=r){
				if(shang) ans+=abs(aa[j]-shang);
				shang=aa[j];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//5 2
//5 4 2 3 1
//3 4
//2 5