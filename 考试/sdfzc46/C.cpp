#include<bits/stdc++.h>
using namespace std;
#define ll __int128_t
const int qwe=1e6+5;
// int n;
ll n,ans;
ll a[qwe];
int v[qwe],r[qwe];
ll read(){
    ll x=0,y=1;
    char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-'){
            y=-1;
        }
        c=getchar();
    }
    while(c>='0' && c<='9'){
        x=(x*10)+c-'0';
        c=getchar();
    }
    return x*y;
}
void print(ll x){
    while()
}
void shai(int x){
    int cnt=0;
    for(int i=2;i<=x;i++){
        if(v[i]==0){
            v[i]=i;
            r[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++){
            if(r[j]>v[i]||r[j]>x/i) break;
            v[r[j]*i]=r[j];
        }
    }
}
ll pw(int x,int y){
    int res=x;
}
int main(){
    shai(1000);
    n=read();
    // scanf("%d",&n);
    // cin<<n;
    for(int i=1;i<=n;i++){
        for(int j=1;i<=n;j++){
            for
        }
    }
    print(ans);
}