#include<bits/stdc++.h>
using namespace std;
int T,n,b[20];
bool a[20];
bool su(int X){
    int s=sqrt(X);
    for (int i = 2; i <= s; i++)
    {
        if (X%i==0)
        {
            return false;
        }
    }
    return true;
}
void dfs(int x,int y){
    if (x==n+1)
    {
        if(su(b[1]+b[n]))
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d",b[i]);
            }
        }
        return;
    }
    if(!su(y+b[x-1]))
    {
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
        {
            continue;
        }
        a[i]=true;
        b[x]=i;
        dfs(x+1,i);
        a[i]=false;
    }
}
int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    while(scanf("%d",&n)!=EOF)
    {
        if(T)printf("\n");
        printf("Case %d:\n",++T);
        dfs(1,0);
    }
    return 0;
}