#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe = 1e6+5;
int n;

int a[qwe];
ll f[qwe];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
    }
    f[0]=0;
    f[1]=1*a[1];
    for(int i=2;i<=1e5+5;i++){
        f[i]=max(f[i-1],f[i-2]+1ll * i*a[i]);
    }
    cout<<f[int(1e5+5)]<<endl;
}