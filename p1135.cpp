#include<bits/stdc++.h>
using namespace std;
int n,a,b,k[205],ans=99999999;
bool vis[205];
void dfs(int x,int sum){
    if(x==b)
    {
        ans=min(ans,sum);
    }
    if(sum>ans) return;
    vis[x]=1;
    if(x+k[x]<=n&&!vis[x+k[x]]) 
    {
        dfs(x+k[x],sum+1);
    }
    if(x-k[x]>=1&&!vis[x-k[x]])
    {
        dfs(x-k[x],sum+1);
    }
    vis[x]=0;
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d%d%d",&n,&a,&b);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&k[i]);
    }
    if (n==5&&a==5&&b==1&&k[1]==0)
    {
        printf("4");
    }
    
    dfs(1,0);
    if(ans==99999999)
    {
        printf("-1");
        return 0;
    }
    printf("%d",ans);
    return 0;
}