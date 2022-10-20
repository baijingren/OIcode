#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=125;
const int mod=1e9+7;
// int n,m;
int T;
struct Matrix{
    int n,m;
    ll a[qwe][qwe];
    Matrix() { memset(a, 0, sizeof a); }
    Matrix operator*(const Matrix &x)const
    {
        Matrix ans;
        ans.n=n;
        ans.m=x.m;
        for(int i=1;i<=ans.n;i++){
            for(int j=1;j<=ans.m;j++){
                for(int k=1;k<=m;k++){
                    ans.a[i][j]=(ans.a[i][j]+(a[i][k]*x.a[k][j])%mod)%mod;
                }
            }
        }
        return ans;
    }
};
Matrix _pow(Matrix a,ll b){
    Matrix ans;
    ans.n=2;
    ans.m=2;
    ans.a[1][1]=1;
    ans.a[2][2]=1;
    ans.a[1][2]=0;
    ans.a[2][1]=0;
    while(b){
        if(b & 1){
            ans=ans*a;
        }
        a=a*a;
        b>>=1;
    }
    return ans;
}
ll n;
ll f[qwe][2][2];
// int ans[qwe],ans;
bitset<30> S;
int main(){
    // init();
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        S=n;
        f[0][0][0]=1;
        int j=1;
        for(ll i=n;i>=1;i>>=1,j++){
            if(i&1){
                f[j][0][0]=f[j-1][0][0]+f[j-1][1][0]+f[j-1][0][1]+f[j-1][1][1];
                f[j][0][1]=0;
                f[j][1][0]=f[j-1][0][0];
                f[j][1][1]=f[j-1][0][1];
            }
            else{
                f[j][0][0]=f[j-1][0][0]+f[j-1][1][0];
                f[j][0][1]=f[j-1][0][1]+f[j-1][1][1];
                f[j][1][0]=0;
                f[j][1][1]=f[j-1][0][0]+f[j-1][0][1];
            }
        }
        j--;
        // printf("%lld",f[0][0][0]);
        printf("%lld\n",f[j][0][0]+f[j][1][0]-1);
        Matrix a,ans,s;
        a.n=2;
        a.m=2;
        a.a[1][1]=0;
        a.a[2][2]=1;
        a.a[1][2]=1;
        a.a[2][1]=1;
        ans=_pow(a,n);
        // s.n=1;
        // s.m=2;
        // s.a[1][1]=1;
        // s.a[1][2]=1;
        // ans=s*ans;
        printf("%lld\n",(ans.a[1][2]+ans.a[2][2])%mod);
    }
}