#include<bits/stdc++.h>
using namespace std;
const int qwe=10005;
int n;
int f[qwe][2];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i][1]);
    }
    int ans=f[1][1];
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        f[y][0]+=max(f[x][0],f[x][1]);
        f[y][1]+=f[x][0];
        ans=max(ans,f[y][0]);
        ans=max(ans,f[y][1]);
    }
    printf("%d",ans);
    return 0;
}