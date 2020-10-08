#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int x,a[2][25],pit[25],total;
void dfs(int n){
    if (n==x+1)
    {
        total++;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        if (pit[a[i][n]]==1)
        {
            continue;
        }
        pit[a[i][n]]=1;
        dfs(n+1);
        pit[a[i][n]]=0;
    }
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&x);
    if (x==0)
    {
        printf("0");
        return 0;
    }
    
    for (int i = 1; i <= x; i++)
    {
        scanf("%d %d",&a[0][i],&a[1][i]);
    }
    dfs(1);
    printf("%d",total);
    return 0;
}