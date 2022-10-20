#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
int n;
struct Matrix{
    ll a[10][10];
    Matrix(){
        memset(a,0,sizeof(a));
    }
    Matrix operator* (const Matrix &b)const{
        Matrix c;
        for(int i=1;i<=3;i++){
            for(int k=1;k<=3;k++){
                ll r=a[i][k]%mod;
                for(int j=1;j<=3;j++){
                    c.a[i][j]+=(b.a[k][j]%mod*r);
                    c.a[i][j]%=mod;
                }
            }
        }
        return c;
    }
};
Matrix pw(Matrix a,int b){
    Matrix ans,temp=a;
    for(int i=1;i<=3;i++){
        ans.a[i][i]=1;
    }
    while(b){
        if(b&1){
            ans=ans*temp;
        }
        temp=temp*temp;
        b>>=1;
    }
    return ans;
}
int T;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        Matrix a;
        a.a[1][1]=a.a[1][3]=a.a[2][1]=a.a[3][2]=1;
        Matrix ans= pw(a,n);
        printf("%lld\n",ans.a[2][1]);
    }
    return 0;
}