#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,cnt,x[4]={2,1,-1,-2},y[4]={1,2,2,1};
void dfs(int a,int b){
    if(a==n&&b==m)
    {
        ++cnt;
        return;
    }
    if(a<0||a>n||b>m) return;
    else for(int i=0;i<4;i++)
    {
        dfs(a+x[i],b+y[i]);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    dfs(0,0);
    printf("%d",cnt);
    return 0;
}