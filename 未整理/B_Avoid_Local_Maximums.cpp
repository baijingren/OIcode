#include<bits/stdc++.h>
#define int long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int a[qwe];

signed main(){
    scanf("%lld",&T);
    while(T--){
        int ans=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        a[0]=a[n+1]=a[n+2]=INT_MAX;
        for(int i=1;i<=n-1;i++){
            bool v=0,flag=0;
            if(a[i]>a[i-1] && a[i]>a[i+1]){
                v=1;
                if(a[i+2]>a[i+1] && a[i+2]>a[i+3]){
                    flag=1;
                }
            }
            if(flag==1){
                a[i+1]=max(a[i],a[i+2]);
                ans++;
            }
            if(v==1 && flag==0){
                a[i]=max(a[i-1],a[i+1]);
                ans++;
            }
        }
        printf("%lld\n",ans);
        for(int i=1;i<=n;i++){
            printf("%lld ",a[i]);
        }
        printf("\n");
    }
    return 0;
}