#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[105];
map<int,int> mp;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        bool f=0;
        mp.clear();
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(mp[a[i]]){
                f=1;
            }
            mp[a[i]]=1;
        }
        cout<<(f?"NO\n":"YES\n");
    }
    return 0;
}