#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e6+5;
int n;
unsigned ll ans=0;
unsigned ll a[qwe];
// int p[55];
vector<unsigned ll> p;
void insert(unsigned ll x){
    for(auto b:p){
        x=min(x,b^x);
    }

    for(auto &b:p){
        b=min(b,x^b);
    }
    if(x){
        p.push_back(x);
    }

}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%llu",&a[i]);
        insert(a[i]);
    }
    sort(p.begin(),p.end());
    for(auto i=p.rbegin();i!=p.rend();i++){
        // cout<<p[i]<<' ';
        // printf("%d ",*i);
        if(((*i)^ans)>ans){
            ans^=(*i);
        }
    }
    printf("%llu",ans);
    return 0;
}
/*
10 
10 23 14 5 33 76 83 99 121 897
*/