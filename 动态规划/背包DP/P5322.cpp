#include<bits/stdc++.h>
using namespace std;
const int qwe=125;
int s,n,m;
int a[qwe][qwe];
int f[100005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s>>n>>m;
    for(int i=1;i<=s;i++){
        for(int j=1;j<=n;j++){
            cin>>a[j][i];
        }
    }
    for(int i=1;i<=n;i++){
        sort(a[i]+1,a[i]+s+1);
    }
    f[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int k=1;k<=s;k++){
                if(j>a[i][k]*2){
                    f[j]=max(f[j-a[i][k]*2-1]+k*i,f[j]);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=m;i++){
        ans=max(f[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}