#include<bits/stdc++.h>
using namespace std;
int n,k,a[10000],s,ans,j[10005];
bool su(int y){
    int cnt=sqrt(double(y));
    for (int i = 2; i <= cnt; i++)
    {
        if (y%i==0)
        {
            return false;
        }
    }
    return true;
}
void dfs(int x,int sum,int bgn){
    if (x==k)
    {
        if(su(sum)) s++;
        return;
    }
    for (int i = bgn; i < n; i++)
    {
        if (j[i]==1)
        {
            continue;
        }
        j[i]=1;
        dfs(x+1,sum+a[i],i+1);
        j[i]=0;
    }
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    dfs(0,0,0);
    printf("%d",s);
    return 0;
}