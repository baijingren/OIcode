#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
ll n,m,mx,mn;
int a[qwe];
bool F[qwe];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        mn=0,mx=0;
        memset(F,0,sizeof(F));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        mn+=a[1];
        bool f=0;
        for(int i=2,j=n;i<=j;i++,j--){
            if(F[i] || F[j]){
                continue;
            }
            mx+=a[j];
            mn+=a[i];
            F[i]=F[j]=1;
            if(mx>mn){
                printf("YES\n");
                f=1;
                break;
            }
        }
        if(!f)
            printf("NO\n");
    }
    return 0;
}