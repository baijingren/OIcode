#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e6+5;
int n;
map<ll,bool> mp;
map<ll,ll> fnd;
int main(){
    scanf("%d ",&n);
    for(int i=1;i<=n;i++){
        char c;
        ll x;
        scanf("%c %lld ",&c,&x);
        if(c=='+'){
            mp[x]=1;
        }
        else{
            if(fnd[x] && !mp[fnd[x]]){
                    cout<<fnd[x]<<'\n';
                    continue;
            }
            for(int i=1;i<=LONG_LONG_MAX/x-1;i++){
                if(!mp[x*i]){
                    cout<<x*i<<'\n';
                    fnd[x]=x*i;
                    break;
                }
            }
        }
    }
    return 0;
}