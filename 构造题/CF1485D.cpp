#include<bits/stdc++.h>
using namespace std;
const int qwe=5e2+5;
const int N=720720;
int n,m;
// int a[qwe][qwe];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // scanf("%d",&a[i][j]);
            int k=0;
            scanf("%d",&k);
            if((i+j)%2==1){
                printf("%d\n",N+k*k*k*k);
            }
            else{
                printf("%d\n",N);
            }
        }
    }
    return 0;
}

