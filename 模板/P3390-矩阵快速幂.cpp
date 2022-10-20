#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe=1e2+5;
const int mod=1e9+7;
int n;
struct Matrix{
    ll a[qwe][qwe];
    Matrix(){
        memset(a,0,sizeof(a));
    }
    Matrix operator* (const Matrix &b)const{
        Matrix c;
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                ll r=a[i][k];
                for(int j=1;j<=n;j++){
                    c.a[i][j]+=(b.a[k][j]*r);
                    c.a[i][j]%=mod;
                }
            }
        }
        return c;
    }
};
Matrix a;
ll k;
Matrix pw(Matrix x,ll b){
    Matrix ans,temp=x;
    for(int i=1;i<=n;i++){
        ans.a[i][i]=1;
    }
    while(b){
        if(b & 1){
            ans=ans*temp;
        }
        temp=temp*temp; 
        b>>=1;
    }
    return ans;
}
int main(){
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&a.a[i][j]);
        }
    }
    Matrix ans=pw(a,k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%lld ",ans.a[i][j]);
        }
        printf("\n");
    }
    return 0;
}