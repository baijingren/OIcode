#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
using namespace std;
const int qwe=1e6+5;    
const int mod=1e9+7;
int n,m,q,k,T,t;
int a[qwe],p[qwe];
vector<int> e[qwe];
bool chk(int x){
    ll l,r,L,R;
    l=k-1;
    r=n-k+1;
    L=1LL*x*(x-1)/2;
    R=1ll*x*(x+1)/2;
    if(x-l>0)
        L=l*(x+x-l)/2;
    if(x-r+1>0)
        R=r*(x+x-r+1)/2;
    if(L+R>m){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    m-=n;
    int l=0,r=m;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(chk(mid)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout<<l+1<<endl;
    return 0;
}