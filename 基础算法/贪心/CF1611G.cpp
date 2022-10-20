#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,T;
string a[qwe];
set<int> temp[qwe];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>m;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=1;j<=m;j++){
                if(a[i][j-1]=='1'){
                    temp[i+j].insert(i);
                }
            }
        }
        for(int i=1;i<=n+m;i++){
            if(temp[i+1].size()==0){
                continue;
            }
            int pos=i;
            ans++;
            for(int j=1;j<=n;j++){
                temp[j+pos].erase(j);
                if(temp[j+pos].rbegin()!=temp[j+pos].rend() && *temp[j+pos].rbegin()>j){
                    pos--;
                }
                else{
                    pos++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}