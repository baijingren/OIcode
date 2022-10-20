#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int a[qwe],b[qwe],c[qwe];

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        int ans=0;
        scanf("%d%d",&n,&m);
        for(int i=n;i<=m;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<=17;i++){
            b[i]=c[i]=0;
        }
        for(int i=0;i<=17;i++){
            for(int j=n;j<=m;j++){
                b[i]+=(a[j]&(1<<i));
                c[i]+=(j&(1<<i));
            }
            if(b[i]!=c[i]){
                ans+=(1<<i);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}