#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=2e6+5;
int n;
string s;
int cnt=0;
int ans=0;
int t[M][26];
char p[M];
bool  v[M];
void insert(int len){
    int nw=0;
    for(int i=1;i<=len;i++){
        if(!t[nw][p[i]-'a']){
            t[nw][p[i]-'a']=++cnt;
        }
        nw=t[nw][p[i]-'a'];
        // cerr<<(int)p[i]-'a'<<endl;

    }
    v[nw]=1;
}
int dp[M];
void dfs(int x){
    int fst=0,snd=0,tmp=0;
    for(int i=0;i<26;i++){
        int v=t[x][i];
        if(!v){
            continue;
        }
        dfs(v);
        if(::v[v]){
            tmp++;
        }
        if(dp[v]>fst){
            snd=fst;
            fst=dp[v];
        }
        else if(dp[v]>snd){
            snd=dp[v];
        }
    }
    if(::v[x]){
        dp[x]=fst+max(tmp-1,0)+1;
    }
    ans=max(ans,fst+snd+max(0,tmp-2)+::v[x]);
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        s=" "+s;
        int tmp=s.length();
        for(int i=1;i<=tmp+1;i++){
            p[i]=0;
        }
        for(int i=1;i<=tmp-1;i++){
            p[i]=s[tmp-i];
            // cerr<<p[i]<<' '<<s.length()-i<<endl;
        }
        insert(tmp-1);
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}