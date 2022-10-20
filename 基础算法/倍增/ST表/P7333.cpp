#include<bits/stdc++.h>
using namespace std;
const int qwe = 5000005;
int n,m;
int a[qwe],b[qwe];
int f[qwe][55];
int chk(int u,int v){
    int k=(int)log2(v-u+1);
    // printf("%d\n",max(f[u][k],f[v-(1<<k)+1][k]));
    return max(f[u][k],f[v-(1<<k)+1][k]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i+n*2]=a[i+n]=a[i];
        f[i+2*n][0]=f[i+n][0]=f[i][0]=a[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    n=2*n;
    int t=log2(n);
    for(int j=1;j<=t+1;j++){
        for(int i=1;i<=n-(1<<j)+1;i++){
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=n/2;i++){
        int l=1,r=n;
        if(chk(l,r)<b[i]){
            printf("-1");
            continue;
        }
        while(l<r){
            int mid=(l+r+1)/2;
            if(b[i]<chk(l,mid)){
                r=mid-1;
            }else{
                l=mid;
            }
        }
        // printf("%d ",min(l-i,i+n-l));
        printf("%d ",l);
    }
    return 0;
}