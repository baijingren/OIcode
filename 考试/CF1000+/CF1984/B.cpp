#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e6+5;
ll T,n;
// int a[qwe];
bool chk(ll x){
    if(x >= 10 && x <= 18+(x!=n)){
        return 1;
    }
    if(x<10){
        return 0;
    }
    if(chk(x/10)){
        ll a=x-((x/10)/2)*20;
        // cerr<<"err:"<<x<<endl;
        if(a >= 10 && a <= 18+(x!=n)){
            return 1;
        }
        if((x/10)%10 >= 1){
            a+=10;
            if(a>=10 && a<=18+(x!=n)){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        // ll temp=n/2;
        bool ans = chk(n);
        cout<< (ans?"YES":"NO") << endl;
    }
    return 0;
}