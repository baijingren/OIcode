#include<bits/stdc++.h>
using namespace std;
int m,n,a[105][105],ans;
bool b[105][105];
int xy[4][2]={0,1,1,0,-1,0,0,-1};
void dfs(int x,int y){
    int cnt=0;
    if(x<1||y<1||x>n||y>m) {
        return ;
    }
    if (!b[x][y])
    {
        dfs(x+1,y);
        return;
    }
    
    if(b[x][y+1]) {
        dfs(x,y+1);
    }
    if(b[x][y-1]) {
        dfs(x,y-1);
    }
    if(b[x+1][y]) {
        dfs(x+1,y);
    }
    if(b[x-1][y]) {
        dfs(x-1,y);
    }
    if (cnt==4)
    {
        ans++;
    }
    dfs(x+1,y);
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d%d",&m,&n);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%1d",&a[m][n]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[m][n]!=0)
            {
                b[m][n]=true;
            }
        }
    }
    dfs(1,1);
    printf("%d",ans);
    return 0;
}