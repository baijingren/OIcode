#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
int q;
vector<int> e[qwe];
int w[qwe],cnt=0;
string s;
void dfs(int u){
    if(!u){
        return;
    }
    dfs(e[u][0]);
    w[++cnt]=s[u]-'a'+1;
    dfs(e[u][1]);
}
int tmp=0;
bool val[qwe],v[qwe];
int dfn[qwe];
void dfss(int u,int k){
    if(!u){
        return;
    }
    dfss(e[u][0],k+1);
    ++cnt;
    dfn[++tmp]=s[u]-'a'+1;
    if(val[e[u][0]]){
        val[u]=1;
        dfn[++tmp]=s[u]-'a'+1;
        dfss(e[u][1],1);
    }
    else if(v[cnt] && k<=m){
        val[u]=1;
        dfn[++tmp]=s[u]-'a'+1;
        m-=k;
        dfss(e[u][1],1);
    }
    else{
        dfss(e[u][1],1e9);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    cin>>s;
    s=" "+s;//s+1
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        e[i].push_back(l);
        e[i].push_back(r);
    }
    dfs(1);
    for(int i=n-1;i>=1;i--){
        if(w[i]==w[i+1]){
            v[i]=v[i+1];
        }
        else{
            if(w[i]<w[i+1]){
                v[i]=1;
            }
            else{
                v[i]=0;
            }
        }
    }
    cnt=0;
    dfss(1,1);
    for(int i=1;i<=tmp;i++){
        cout<<char(dfn[i]+'a'-1);
    }
    return 0;
}