#include<bits/stdc++.h>
using namespace std;
const int qwe=3e3+5;
int n;
int ans=INT_MAX;
struct Book{
    int h,t;
    Book()=default;
    Book(int a,int b){
        h=a,t=b;
    }
} b[qwe];
int dp[2][qwe][qwe];
int sum[qwe];
int main(){
    freopen("book.in","r",stdin);
    freopen("book.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i].h>>b[i].t;
    }
    sort(b+1,b+n+1,[](Book a,Book b){
        return a.h>b.h;
    });
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+b[i].t;
    }
    for(int i=1;i<=n;i++){
        int nw=i&1;
        int ls=!nw;
        memset(dp[nw],0x3f,sizeof(dp[nw]));
        for(int j=0;j<=sum[i-1];j++){
            for(int k=0;k<=sum[i-1];k++){
                int tmp=sum[i-1]-j-k;
                if(tmp<0){
                    continue;
                }
                if(dp[ls][j][k]==0x3f3f3f3f){
                    continue;
                }
                if(j==0){
                    dp[nw][j+b[i].t][k]=min(dp[nw][j+b[i].t][k],dp[ls][j][k]+b[i].h);
                }
                else{
                    dp[nw][j+b[i].t][k]=min(dp[nw][j+b[i].t][k],dp[ls][j][k]);
                }
                if(k==0){
                    dp[nw][j][k+b[i].t]=min(dp[nw][j][k+b[i].t],dp[ls][j][k]+b[i].h);
                }
                else{
                    dp[nw][j][k+b[i].t]=min(dp[nw][j][k+b[i].t],dp[ls][j][k]);
                }
                if(tmp==0){
                    dp[nw][j][k]=min(dp[nw][j][k],dp[ls][j][k]+b[i].h);
                }
                else{
                    dp[nw][j][k]=min(dp[nw][j][k],dp[ls][j][k]);
                }
            }
        }
    }
    for(int i=1;i<=sum[n];i++){
        for(int j=1;j<=sum[n];j++){
            int tmp=sum[n]-i-j;
            if(tmp<=0){
                continue;
            }
            if(dp[n&1][i][j]==0x3f3f3f3f){
                continue;
            }
            tmp=max(tmp,i);
            tmp=max(tmp,j);
            ans=min(ans,tmp*dp[n&1][i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}