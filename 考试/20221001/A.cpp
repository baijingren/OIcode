#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e3+5;
int n,m,Q;
// int a[qwe];
// void init(){

// }
ll chk(int x){
    int t=sqrt(x);
    ll sum=0;
    int f1=min(t,n),f2=min(t,m);
    for(int i=1;i<=f1;i++){
        sum+=x/i;
    }
    for(int i=1;i<=f2;i++){
        sum+=x/i;
    }
    return sum-t*t;
}
int main(){
    freopen("kth.in","r",stdin);
    freopen("kth.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>Q;
    // init();
    for(int i=1;i<=Q;i++){
        int x;
        cin>>x;
        int l=1,r=x,ans;
        while(l<=r){
            int mid=(l+r)>>1;
            if(chk(mid)>=x){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}