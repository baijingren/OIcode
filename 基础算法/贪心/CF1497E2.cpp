#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int K=25;
const int qwe=1e7+5;
int T,n,k;
int a[N];
int l[N][K];
int f[N][K];
int vis[qwe];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        // memset(f,0x3f,sizeof(f));
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            int tmp=a[i];
            a[i]=1;
            for(int j=2;j*j<=tmp;j++){
                if(tmp%j==0){
                    int cnt=0;
                    while(tmp%j==0){
                        cnt++;
                        tmp/=j;
                    }
                    if(cnt&1){
                        a[i]*=j;
                    }
                }
            }
            if(tmp>1){
                a[i]*=tmp;
            }
        }
        for(int i=0;i<=k;i++){
            int cnt=0;
            int r=1;
            for(int l=1;l<=n;l++){
                vis[a[l]]++;
                if(vis[a[l]]>=2){
                    cnt++;
                }
                while(cnt>i){
                    if(vis[a[r]]>=2){
                        cnt--;
                    }
                    vis[a[r]]--;
                    r++;
                }
                ::l[l][i]=r;
            }
            for(int j=1;j<=n;j++){
                vis[a[j]]=0;
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                f[i][j]=INT_MAX/3;
            }
        }
        f[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                for(int x=0;x<=j;x++){
                    f[i][j]=min(f[i][j],f[l[i][x]-1][j-x]+1);
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<=k;i++){
            ans=min(ans,f[n][i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}