#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
// int T;
int n,x;
int a[qwe];
int cnt[qwe];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
        // cout<<1<<endl;
    cin>>n>>x;
    bool flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<x;i++){
        // cerr<<cnt[i]<<endl;
        if(cnt[i]%(i+1)==0){
            cnt[i+1]+=cnt[i]/(i+1);
            cnt[i]=0;
        }
        else{
            flag=1;
        }
    }
    cout<<(flag?"No\n":"Yes\n");
    return 0;
}