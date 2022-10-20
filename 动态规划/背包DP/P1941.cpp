#include<bits/stdc++.h>
using namespace std;
// #define {a[i].x} x[i]
// #define a[i].y y[i]
const int qwe=1e6+5;
const int INF=0x3f3f3f3f;
int n,m,k;
// struct act{
//     int x,y;
// } a[qwe];
int x[qwe],y[qwe];
struct B{
    bool p;
    int l,h;
} b[qwe];
int f[10005][2005];
bool cmp(B x,B y){
    return x.p<y.p; 
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
        // a[i].pos=i;
    }
    for(int i=1;i<=n;i++){
        b[i].h=m;
        b[i].l=1;
        b[i].p=0;
    }
    for(int i=1;i<=k;i++){
        // scanf("%d%d%d",&b[i].p,&b[i].l,&b[i].h);
        int p,l,h;
        scanf("%d%d%d",&p,&l,&h);
        b[p].p=1,b[p].h=h-1,b[p].l=l+1;
    }
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=m;i++){
        f[0][i]=0;
    }
    // sort(b+1,b+k+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=x[i]+1;j<=m+x[i];j++){//正常的部分
            f[i][j]=min(f[i-1][j-x[i]]+1,f[i][j-x[i]]+1);
        }
        for(int j=m+1;j<=m+x[i];j++){//超出上端的部分
            f[i][m]=min(f[i][m],f[i][j]);
        }
        for(int j=1;j<=m-y[i];j++){
            f[i][j]=min(f[i][j],f[i-1][j+y[i]]);
        }
    // for(int i=1;i<=k;i++){
        for(int y=1;y<b[i].l;y++){
            f[i][y]=INF;
        }
        for(int y=b[i].h+1;y<=m;y++){
            f[i][y]=INF;
        }
    // }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         printf("%10d ",f[i][j]);
    //     }
    //     printf("\n");
    // }
    int ans=INF;
    for(int i=1;i<=m;i++){
        ans=min(f[n][i],ans);
    }
    if(ans<INF){
        printf("1\n%d",ans);
        return 0;
    }
    int i,j;
    for(i=n;i>=1;i--){
        for(j=1;j<=m;j++){
            if(f[i][j]<f[0][0]) break;
        }
        if(j<=m) break;
    }
    ans=0;
    for(j=1;j<=i;j++){
        if(b[j].p){
            ans++;
        }
    }
    printf("0\n%d",ans);
}