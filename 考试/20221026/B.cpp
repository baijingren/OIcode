#include<bits/stdc++.h>
using namespace std;
const int qwe=2e6+5;
int n,m,T;
int a[qwe];
int s[qwe];
int dp[qwe][2];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>T;
	while(T--){
		cin>>n>>m;
		int ans=0;
		int tmp=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s[i]=s[i-1]+a[i];
			if(a[i]>=0){
				tmp++;
			}
		}
		if(tmp<=m){
			sort(a+1,a+n+1,[](int a,int b){
				return a>b;
			});
			for(int i=1;i<=m;i++){
				ans+=a[i];
			}
			cout<<ans<<endl;
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=m;i++){
			int nw=i&1;
			for(int j=1;j<=n;j++){
				dp[j][nw]=max(dp[j-1][nw^1],dp[j-1][nw])+a[j];
			}
			for(int j=1;j<=n;j++){
				dp[j][nw]=max(dp[j][nw],dp[j-1][nw]);
			}
		}
		ans=dp[n][m&1];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			dp[i][0]=s[i];
		}
		for(int i=1;i<=m;i++){
			int nw=i&1;
			for(int j=1;j<=n;j++){
				dp[j][nw^1]=max(dp[j][nw^1],dp[j-1][nw^1]);
			}
			for(int j=1;j<=n;j++){
				dp[j][nw]=max(dp[j-1][nw^1],dp[j-1][nw])+a[j];
			}
		}
		cout<<max(ans,dp[n][m&1])<<endl;
	}
	return 0;
}