#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;

const int qwe=1e6+5;
int n;
int a[qwe];

ll ans=0;

int main(){
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }

        sort(a+1,a+n+1);
        if(n==1){
            printf("%d\n",a[1]);
            continue;
        }
        if(a[1]>0){
            a[1]=-a[1];
        }
        else if(a[n]<0){
            for(int i=1;i<n;i++){
                a[i]=-a[i];
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if(a[i]<0){
                    a[i]=-a[i];
                }
            }
        }
        // for(int i=1;i<=floor(n/2);i++){
        //     a[i]=-a[i];
        // }
        // for(int i=1;i<=n;i++){
        //     cout<<a[i]<<' ';
        // }
        // cout<<endl;
        for(int i=1;i<=n;i++){
            ans+=a[i];
        }

        printf("%lld\n",ans);
    }
    return 0;
}