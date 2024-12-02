#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
string a,b;
int nxt[qwe],ans[qwe],cnt=0;
void work(){
    for(int i=2,j=0;i<=m;i++){
        while(j && b[j+1]!=b[i]){
            j=nxt[j];
        }
        if(b[j+1]==b[i]){
            j++;
        }
        nxt[i]=j;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a;
    cin>>b;
    n=a.length();
    m=b.length();
    a=" "+a;
    b=" "+b;
    work();
    for(int i=1,j=0;i<=n;i++){
        while(j && a[i]!=b[j+1]){
            j=nxt[j];
        }
        if(a[i]==b[j+1]){
            j++;
        }
        if(j==m){
            cout<<i-j+1<<endl;
            j=nxt[j];
        }
    }
    // for(int i=1;i<=cnt;i++){
    //     cout<<ans[i]<<'\n';
    // }
    for(int i=1;i<=m;i++){
        cout<<nxt[i]<< ' ' ;
    }
    cout<<'\n';
    return 0;
}