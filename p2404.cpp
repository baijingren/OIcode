#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[11]={1},sum,m;
void print(int y){
    for(int i=1;i<y;i++)
    {
       printf("%d+",a[i]);
    }
    printf("%d\n",a[y]);
    return;
}
void dfs(int x){
    for(int i=a[x-1];i<=m;i++)
    {
        if(i==n) continue;
        a[x]=i;
        m-=i;
        if(m==0)
        {
            print(x);
        }
        else dfs(x+1);
        m+=i;
    }
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&n);
    m=n;
    dfs(1);
    return 0;
}