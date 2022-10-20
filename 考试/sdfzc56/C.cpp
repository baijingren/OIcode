#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define MP make_pair
#define ll long long
const int qwe=1e6+5;
const int mod=1e9+7;
int n;
ll ans=0;
PII a[qwe];
ll f[qwe][2];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a+1,a+n+1,[](PII x,PII y){
        // return x.second>y.second;
        return x.first<y.first;
    });
    for(int i=1;i<=n;i++){
        f[i][0]=f[i][1]=1;//
        for(int j=i-1;j>=1;j--){
            if(a[j].second>a[i].second){
                f[j][1]=(f[j][1]+f[i][0])%mod;
            }
            else{
                f[i][0]=(f[i][0]+f[j][1])%mod;
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=(ans+f[i][0]+f[i][1])%mod;
    }
    printf("%lld",(ans-n+mod)%mod);//初始值为1，故要减去n
}
//![](https://gitee.com/baijingren/markdown/raw/master/202202131450240.png)
//![](https://gitee.com/baijingren/markdown/raw/master/202202131457365.png)