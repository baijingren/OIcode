#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int a[qwe];
int l[qwe],r[qwe];
int ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        if(n%2==1){
            cout<<"-1\n";
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            continue;
        }
        int cnt=1;
        for(int i=1;i<=n;i+=2){
            cin>>a[i]>>a[i+1];
            if(a[i]==a[i+1]){
                l[++cnt]=i;
                r[cnt]=i+1;
            }
            else{
                cnt++;
                l[cnt]=r[cnt]=i;
                cnt++;
                l[cnt]=r[cnt]=i+1;
            }
        }
        cout<<cnt-1<<endl;
        for(int i=2;i<=cnt;i++){
            cout<<l[i]<<' '<<r[i]<<'\n';
        }
    }
    return 0;
}