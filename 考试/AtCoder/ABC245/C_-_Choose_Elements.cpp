#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int a[qwe],b[qwe],x[qwe];
bool dfs(int u){
    if(u>n){
        return 1;
    }
    if(abs(x[u-1]-a[u])<=m){
        x[u]=a[u];
        if(dfs(u+1)){
            return 1;
        }
    }
    if(abs(x[u-1]-b[u])<=m){
        x[u]=b[u];
        dfs(u+1);
    }
}

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    x[1]=a[1];
    if(dfs(2));
    // x[n]=a[n];
    // x[1]=a[1];
    // int f=0;
    // for(int i=1;i<n;i++){
    //     if(abs(a[i+1]-x[i])<=m){
    //         x[i+1]=a[i+1];
    //     }
    //     if(abs(b[i+1]-x[i])<=m){
    //         x[i+1]=b[i+1];
    //     }
    //     else{
    //         f=1;
    //         break;
    //     }
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<x[i]<<' ';
    // }
    // if(f==0){
    //     printf("Yes\n");
    // }
    // else{
    //     f=0;
    //     // x[n]=b[n]
    //     x[1]=b[1];
    //     for(int i=1;i<n;i++){
    //         if(abs(a[i+1]-x[i])<=m){
    //             x[i+1]=a[i+1];
    //         }
    //         else if(abs(b[i+1]-x[i])<=m){
    //             x[i+1]=b[i+1];
    //         }
    //         else{
    //             f=1;
    //             break;
    //         }
    //     }
    //     if(f==0){
    //         printf("Yes\n");
    //     }
    //     else{
    //         printf("No\n");
    //     }
    // }
    return 0;
}