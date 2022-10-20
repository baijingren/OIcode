#include<bits/stdc++.h>
using namespace std;
#define ld double
const int qwe=2e2+5;
int n,l,K;
ld f[qwe][qwe][qwe];
struct Node{
    int a;
    ld p;
} p[qwe];
int main(){
    scanf("%d%d%d",&n,&l,&K);
    f[0][0][min(K,n)]=1;
    for(int i=1;i<=n;i++){
        scanf("%lf",&p[i].p);
        p[i].p*=0.01;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i].a);
    }
    sort(p+1,p+n+1,[](Node x,Node y){
        return x.a>y.a;
    });
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<=n;k++){
                f[i][j][k]+=f[i-1][j][k]*(1-p[i].p);
                if(p[i].a==-1 && k>0){
                    f[i][j+1][k-1]+=f[i-1][j][k]*p[i].p;
                }
                if(p[i].a>=0){
                    f[i][j+1][min(k+p[i].a,n)]+=f[i-1][j][k]*p[i].p;
                }
            }
        }
    }
    ld ans=0;
    for(int i=l;i<=n;i++){
        for(int j=0;j<=n;j++){
            ans+=f[n][i][j];
        }
    }
    printf("%lf",ans);
}