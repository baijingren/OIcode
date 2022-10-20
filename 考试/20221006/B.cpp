#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
string s;
struct BigIntenger{
    static const int mod=1e8;
    int s[10005],len;
    explicit BigIntenger(){
        len=1;
        memset(s,0,sizeof(s));
    }
    BigIntenger operator+(const BigIntenger &a) const{
        BigIntenger ans;
        ans.len=max(len,a.len);
        for(int i=1;i<=ans.len;i++){
            ans.s[i]+=s[i]+a.s[i];
            if(ans.s[i]>mod){
                ans.s[i+1]+=ans.s[i]/mod;
                ans.s[i]%=mod;
            }
        }   
        if(ans.s[len+1]>0){
            ans.len++;
        }
        return ans;
    }
    BigIntenger operator*(const int a) const{
        BigIntenger ans;
        ans.len=len;
        for(int i=1;i<=ans.len;i++){
            ans.s[i]+=s[i]*a;
            if(ans.s[i]>mod){
                ans.s[i+1]+=ans.s[i]/mod;
                ans.s[i]%=mod;
            }
        }
        if(ans.s[len+1]>0){
            ans.len++;
        }
        return ans;
    }

};
int pow(int x,int y){
    int a=x,b=1;
    while(y){
        if(y&1){
            b*=a;
        }
        a*=a;
        y>>=1;
        
    }
    return b;
}
int main(){
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    // cerr<<s<<'\n';
    BigIntenger ans,k;
    ans.s[1]=1;
    k.s[1]=1;
    n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            ans=ans*2;
        }
        else if(s[i]=='R'){
            ans=ans*2+k;
        }
        else if(s[i]=='*'){
            ans=ans*5+k;
            k=k*3;
        }
    }
    printf("%d",ans.s[ans.len]);
    for(int i=ans.len-1;i>=1;i--){
        printf("%08d",ans.s[i]);
    }
    printf("\n");
    return 0;
}