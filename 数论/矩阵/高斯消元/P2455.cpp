#include<bits/stdc++.h>
#define ld double
using namespace std;
const int qwe=1e2+5;
const double eps=1e-6;
int n;
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
        for(int j=i+1;j<=n;j++){
            if(fabs(a[j][i])>fabs(a[mx][i])){
                mx=j;
            }
        }
        for(int j=1;j<=n+1;j++){
            swap(a[i][j],a[mx][j]);
        }
        if(fabs(a[i][i])<eps){
            // if(a[i][n+1]){
            //     printf("-1");
            //     return 0;
            // }
            // else if(!a[i][n+1]){
            //     printf("0");
            //     return 0;
            // }
            // return 0;
            continue;
        }
        for(int j=1;j<=n;j++){
            if(j!=i){
                ld tmp=a[j][i]/a[i][i];
                for(int k=i+1;k<=n+1;k++){
                    a[j][k]-=a[i][k]*tmp;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        // printf("%.2lf %.2lf\n",a[i][n+1],a[i][i]);
        a[i][n+1]=a[i][n+1]/a[i][i];
        if(fabs(a[i][n+1])<eps){
            a[i][n+1]=0.00;
        }
    }
    bool flag=0;
    for(int i=1;i<=n;i++){
        if(fabs(a[i][i])<eps){
            flag=1;
            for(int j=n;j>i;j--){
                if(fabs(a[i][j])>eps){
                    flag=0;
                    break;
                }
            }
            if(!flag){
                continue;
            }
            if(fabs(a[i][n+1])>eps){
                printf("-1");
                return 0;
            }
        }
    }
    if(flag){
        printf("0");
        return 0;
    }
    for(int i=1;i<=n;i++){
        printf("x%d=%.2lf\n",i,a[i][n+1]);
    }
    return 0;
}