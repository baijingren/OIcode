#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=2e3+5;
int T;
int n,m,k;
int a[qwe][qwe];
bool b[qwe][qwe];
void dfs(int x,int y){
    if(a[x][y]){
        b[]
    }
}
int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&n,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==n*n){
                a[i][j]=1;
                continue;
            }
            dfs(i,j);
        }
    }
    return 0;
}