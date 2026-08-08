#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int a[qwe];

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int cnt1=0;
        int f=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]==1){
                cnt1++;
            }
        }
        if(cnt1!=1){
            cout<<"NO"<<endl;
            // break;
            continue;
        }
        for(int i=2;i<=n;i++){
            if(a[i]-a[i-1]>1){
                // cout<<"NO"<<endl;
                f=1;
            }
        }
        if(a[1]-a[n]>1){
            f=1;
        }
        if(f){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}