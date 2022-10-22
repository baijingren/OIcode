#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
const int mod=998244353;
int n;
int a[qwe];
long long f[qwe][2];
long long g[qwe][2];
deque<int> q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[0][0]=g[0][0]=1;
    for(int i=1;i<=n;i++){
        while(!q.empty() && a[q.back()]>=a[i]){
            q.pop_back();
        }
        for(int j=0;j<=1;j++){
            f[i][j]=((q.size()?f[q.back()][j]:0)+(g[i-1][j^1]-(q.size()?g[q.back()-1][j^1]:0))*a[i])%mod;
            g[i][j]=(g[i-1][j]+f[i][j])%mod;
        }
        q.push_back(i);
    }
    cout<<((f[n][0]-f[n][1])*(n&1?-1:1)%mod+mod)%mod<<endl;
    return 0;
}