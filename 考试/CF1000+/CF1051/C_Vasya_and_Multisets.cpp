#include<bits/stdc++.h>
using namespace std;
const int qwe=1e2+5;
int n;
int a[qwe];
int cnt[qwe];
bool ans[qwe];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int A=0,b=0,cntt=0;
    for(int i=1;i<=n;i++){
        if(cnt[a[i]]==1){
            ans[i]=b;
            b^=1;
            cntt++;
        }
    }
    if(cntt%2==1){
        bool f=0;
        for(int i=1;i<=n;i++){
            if(cnt[a[i]]>2){
                ans[i]=1;
                f=1;
                break;
            }
        }
        if(!f){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            for(int i=1;i<=n;i++){
                cout<<(ans[i]?'A':'B');
            }
            cout<<'\n';
        }
    }
    else{
        cout<<"YES\n";
        for(int i=1;i<=n;i++){
            cout<<(ans[i]?'A':'B');
        }
        cout<<'\n';
    }
    return 0;
}