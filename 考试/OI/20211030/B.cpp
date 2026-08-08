#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int qwe = 1e6 + 5;
int n,m,q;
ll a[qwe],s[qwe],d[qwe];
int main(){
    scanf("%d%d%d", &n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    int l, r, k;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &l, &r, &k);
        s[l] += k, s[r + 1] -= k;
    }
    for(int i=1;i<=n;i++){
        s[i] += s[i - 1];
    }
    for(int i=1;i<=n;i++){
        a[i] += s[i];
    }
    for(int i=1;i<=n;i++){
        d[i] = d[i - 1] + a[i];
    }
    for (int i = 1;i<=q;i++){
        scanf("%d%d", &l, &r);
        printf("%lld\n", d[r] - d[l - 1]);
    }
    return 0;
}