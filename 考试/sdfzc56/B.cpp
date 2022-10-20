#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m,ans=0;
unsigned long long k;
int a[qwe],d[qwe];
int tth[]={1,10,100,1000};
bool vis[qwe];
set<unsigned long long> s;
void dfs(int x){
    if(x==m){
        // cout<<k<<endl;
        if(s.count(k)){
            return;
        }
        else{
            ans++;
            s.insert(k);
            return;
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vis[i]=1;
        k=tth[d[i]]*k+a[i];
        dfs(x+1);
        k/=tth[d[i]];
        vis[i]=0;
    }
    
}
int mur(int x){
    int cnt=0;
    while(x){
        cnt++;
        x/=10;
    }
    return cnt;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        d[i]=mur(a[i]);
    }
    dfs(0);
    printf("%d",ans);
}