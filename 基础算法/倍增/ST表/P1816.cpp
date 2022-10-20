#include<bits/stdc++.h>
using namespace std;
const int qwe = 5000005;
int n,m;
int a[qwe],s[qwe];
// const int N=(int)(log2(qwe)*2);
int f[qwe][105];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        f[i][0]=a[i];
    }
    int t=log2(n);
    // for(int i=1;i<=n;i++){
        // int num=log2(j-i+1);
        // for(int j=1;j<=num;j++){
            // 
        // }
    // }
    for(int j=1;j<=t+1;j++){
        for(int i=1;i<=n-(1<<j)+1;i++){
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=m;i++){
        // scanf("%d",&k);
        int u,v;
        scanf("%d%d",&u,&v);
        int k=(int)log2(v-u+1);
        printf("%d ",min(f[u][k],f[v-(1<<k)+1][k]));
    }
    return 0;
}