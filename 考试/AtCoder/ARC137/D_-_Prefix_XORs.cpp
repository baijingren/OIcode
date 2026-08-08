#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
ll a[qwe];
vector<ll> p[qwe];
void insert(ll &x,int r){
    for(auto b:p[r]){
        x=min(x,x^b);
    }
    for(auto &b:p[r]){
        b=min(b,x^b);
    }
    if(x){
        p[r].push_back(x);
    }
    // return;
}

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        insert(a[i],0);
    }
    for(int i=1;i<=m;i++){
    // for(int i=1;i<=m;i++){
        for(auto b:p){
            // insert(b);
            insert(a[i],i);
        }
        cout<<a[n]<<' ';
    }
    // for(int i=1;i<=n;i++){
    //     // for(int )
    //     printf("%lld ",a[i]);

    // }
    return 0;
}