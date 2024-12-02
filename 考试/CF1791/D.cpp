#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int T;
int n;
char c[qwe];
int f[qwe],g[qwe];
bool v[35];
void init(){
    memset(v,0,sizeof(v));
}
int main(){
    cin>>T;
    while(T--){
        init();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>c[i];
            c[i]=c[i]-'a'+1;
        }
        f[0]=g[n+1]=0;
        for(int i=1;i<=n;i++){
            f[i]=f[i-1]+(!v[c[i]]);
            v[c[i]]=1;
        }
        init();
        for(int i=n;i>=1;i--){
            g[i]=g[i+1]+(!v[c[i]]);
            v[c[i]]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,f[i]+g[i+1]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}