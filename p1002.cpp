#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int m,n,o[25][25],x,y,a,b;
int main(){
    scanf("%d %d %d %d",&m,&n,&x,&y);
    
    for (int i = 0; i <= m; i++)
    {
        o[i][0]=1;
    }
    for (int i = 0; i <= n; i++)
    {
        o[0][i]=1;
    }
    o[x][y]=0;
    o[x-1][y-2]=0;
    o[x-2][y-1]=0;
    o[x-2][y+1]=0;
    o[x-1][y+2]=0;
    o[x+1][y-2]=0;
    o[x+2][y-1]=0;
    o[x+2][y+1]=0;
    o[x+1][y+2]=0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            o[i][j]=o[i-1][j]+o[i][j-1];
        }
    }
    printf("%d",o[m][n]);
    return 0;
}
