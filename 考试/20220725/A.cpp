#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
const int qwe=1e6+5;
const int mod=1e9+7;
int n,m,q,k,T,t;
struct Node{
    int l,r;
} a[qwe];
int L[qwe],R[qwe],pos[qwe],sum[qwe];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
        m=max(a[i].r,m);
    }
    sort(a+1,a+n+1,[](Node a,Node b){
        return a.l==b.l?a.r<b.r:a.l<b.l;
    });
    init();
    for(int i=1;i<=n;i++){

    }
    return 0;
}