#include <bits/stdc++.h>
//#include<vector>
using namespace std;
const int qwe=2e6+5;
int n,m,T;
int ans=0;
int a[qwe],s[qwe];
//vector<int> e;
int main() {
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
//	freopen("sum.log","w",stderr);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>T;
	while(T--){
		cin>>n>>m;
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int st=0,tmp=0;
		for(int i=1;i<=10;i++){
			cerr<<a[i]<<' ';
		}
		cerr<<endl;
		for(int i=1;i<=n;i++){
			if(a[i]<0 && a[i+1]>0 && st==0){
//				cerr<<a[i]<<' '<<a[i+1]<<endl;
				st=i;
			}
			if(a[i]>=0){
				tmp++;
			}
		}
		cerr<<st<<endl;
		cerr<<a[st]<<' '<<a[st+1]<<endl;
		if(tmp<=m){
			sort(a+1,a+n+1,[](int a,int b){
				return a>b;
			});
			for(int i=1;i<=m;i++){
				ans+=a[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			a[n+i]=a[i];
		}
		int cnt=0;
		for(int i=st;i<=n*2;i++){
			if(a[i]<0){
				if(i>n){
					break;
				}
				cnt++;
//				s[cnt]=a[i];
			}
			else{
				s[cnt]+=a[i];
			}
		}
		sort(s+1,s+cnt+1,[](int a,int b){
			return a>b;
		});
		if(cnt>m){
			for(int i=1;i<=m;i++){
				ans+=s[i];
			}
		}
		else{
			for(int i=1;i<=cnt;i++){
				ans+=s[i];
			}
		}
		cout<<ans<<'\n';
	}
}