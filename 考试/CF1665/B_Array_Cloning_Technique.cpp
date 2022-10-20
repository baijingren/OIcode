#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int a[qwe];
map<int,int> mp;

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        mp.clear();
        int ans=0,mx=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            mp[a[i]]++;
            if(mp[a[i]]>mx){
                mx=mp[a[i]];
            }
        }
        ans=n-mx;
        if(ans==0){
			printf("%d\n",ans);
			continue;
		}
        int i=1,x=ans;
        if(mx>=ans) ans++;
		else {
			x-=mx;
			i=2;
            while(1){
				mx*=2;
				if(mx>=x) break;
				x-=mx;
                i++;
			}
			ans+=i;
		}
        printf("%d\n",ans);
    }
    return 0;
}