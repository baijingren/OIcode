#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e6+5;
int n,m;
ll z;
struct Node{
    int a,b;
} a[qwe],ans;
ll ansc;
int b[qwe];
int main(){
    freopen("mannur.in","r",stdin);
    freopen("mannur.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>z;
    for(int i=1;i<=m;i++){
        int x;
        cin>>a[i].a>>a[i].b>>x;
        ansc+=x;
    }
    for(int i=1;i<=m;i++){
        b[a[i].a]++;
    }
    int mid=ceil(1.0*m/2);
    for(int i=1;i<qwe;i++){
        b[i]+=b[i-1];
        if(mid<=b[i]){
            ans.a=i;
            break;
        }
    }
    // cerr<<mid<<endl;
    for(int i=1;i<qwe;i++){
        b[i]=0;
    }
    for(int i=1;i<=m;i++){
        b[a[i].b]++;
    }
    for(int i=1;i<qwe;i++){
        b[i]+=b[i-1];
        if(mid<=b[i]){
            ans.b=i;
            break;
        }
    }
    for(int i=1;i<=m;i++){
        ll k=abs(a[i].a-ans.a)+abs(a[i].b-ans.b);
        // if(k==0){
        //     ans.c+=a[i].c;
        // }
        // else{
            ansc+=k*z;
        // }
    }
    cout<<ansc<<endl<<ans.a<<' '<<ans.b<<endl;
    return 0;
}