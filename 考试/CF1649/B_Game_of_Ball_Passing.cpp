#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int a[qwe];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ll mx=0,sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            mx=max(mx,(ll)a[i]);
            sum+=a[i];
        }
        if(sum==0){
            printf("0\n");
            continue;
        }
        if(sum>=mx*2){
            printf("1\n");
        }
        else{
            printf("%lld\n",mx*2-sum);
        }
    }
    return 0;
}