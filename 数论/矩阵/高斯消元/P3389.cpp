#include<bits/stdc++.h>
#define ld double
using namespace std;
const int qwe=1e3+5;
const double eps=1e-6;
int n,m;
ld a[qwe][qwe];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        int mx=i;
        for(int j=i;j<=n;j++){
            if(fabs(a[j][i])>fabs(a[mx][i])){
                mx=j;
            }
        }
        if(fabs(a[mx][i])<eps){
            printf("No Solution");
            return 0;
        }
        a[mx][n+1]/=a[mx][i];
        swap(a[i],a[mx]);
        for(int j=n;j>=i;j--){
            a[i][j]/=a[i][i];
            // swap(a[i][j],a[mx][j]);
        }
        for(int j=1;j<=n+1;j++){
            if(i!=j){
                a[j][n+1]-=a[i][n+1]*a[j][i];
                for(int k=n;k>=i;k--){
                    a[j][k]-=a[i][k]*a[j][i];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%.2lf\n",a[i][n+1]);
    }
    return 0;
}