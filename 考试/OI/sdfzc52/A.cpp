#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
// const int qwe=1e6+5;
int n;
ll ans;
int w[35];
ld f[1<<21],p[35];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%Lf%d",&p[i],&w[i]);
        ans+=w[i];
    }
    int _n=(1<<n)-1;
    f[_n]=0;
    for(int i=_n-1;i>=0;i--){
        ld pos=0.0;
        for(int j=1;j<=n;j++){
            if(i&(1<<(j-1))){
                continue;
            }
            f[i]+=f[i|(1<<(j-1))]*p[j];
            pos+=p[j];
        }
        f[i]=f[i]+1.0;
        f[i]=f[i]*1.0/pos;
    }
    printf("%lld\n%.3Lf\n",ans,f[0]);
}