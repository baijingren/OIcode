#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a[15][15],n;
void pit(int X,int Y){
    for (int i = 0; i < n; i++)
    {
        a[i][Y]=2;
    }
    for (int i = 0; i < n; i++)
    {
        a[]
    }
    
        a[X][Y]=1;
}
void dfs(int x){
    for (int i = 0; i < n; i++)
    {
        pit(x,i);
        dfs(x+1);
        a[x][i]=0;
    }
    
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    printf("%d",&n);
    dfs(1);
    return 0;
}