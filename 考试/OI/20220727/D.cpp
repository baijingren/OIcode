#include<bits/stdc++.h>
using namespace std;
const int qwe=1e3+500;
int n,m,q;
int a[qwe][qwe/10];
int s[qwe];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    if(n==1){
        for(int i=1;i<=m;i++){
            s[i]=s[i-1]+(a[i]!=a[i-1]);
        }
        for(int i=1;i<=q;i++){
            int l,r,L,R;
            cin>>l>>r;
            R=s[r];
            L=s[l-1]-1;
            if(s[l]!=s[l-1]){
                L=s[l-1];
            }
            cout<<R-L<<'\n';
        }
        return 0;
    }
    else{
        return 0;
    }
    return 0;
}