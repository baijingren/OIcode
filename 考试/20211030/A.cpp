#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int qwe = 1e6 + 5;
int n,ans;
ll P;
ll a[qwe], b[qwe], c[qwe];
ll fpow(int x, int al)
{
    ll tmp = x;
    ll ans=1;
    while(al){
        if(al&1){
            ans = (ans * tmp) % P;
        }
        tmp = (tmp * tmp) % P;
        al >>= 1;
    }
    return ans % P;
}
int main(){
    scanf("%d%d",&n,&P);
    for(int i=1;i<=n;i++){
        scanf("%lld", &a[i]);
    }
    for(int i=1;i<=n;i++){
        b[i] = fpow(i, a[i]) % P;
        c[i] = fpow(a[i], i) % P;
    }
    for(int i=1;i<=n;i++){
        for (int j = i + 1; j <= n;j++){
            if(b[i]>c[j]){
                ans++;
            }
        }
    }
    printf("%d", ans);
}