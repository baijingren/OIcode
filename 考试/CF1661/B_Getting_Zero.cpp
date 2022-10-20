#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int a[qwe];
int t[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int ans=INT_MAX;
        // int k=lower_bound(t,t+16,n)-t-1;
        for(int i=0;i<15;i++){
            m=n+i;
            // cout<<m<<endl;
            for(int j=14;j>=0;j--){
                // cout<<m*j<<' ';
                if((m*t[j])%t[15]==0){
                    ans=min(ans,i+j);
                }
            }
            // cout<<endl;
        }
        printf("%d ",ans);
    }
    return 0;
}