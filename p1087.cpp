#include<bits/stdc++.h>
using namespace std;
int mp[10][10];
int a[10][10],b[10][10],c[10][10];//a行b列c区块
int block[10][10]={
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,2,2,2,3,3,3},
    {0,1,1,1,2,2,2,3,3,3},
    {0,1,1,1,2,2,2,3,3,3},
    {0,4,4,4,5,5,5,6,6,6},
    {0,4,4,4,5,5,5,6,6,6},
    {0,4,4,4,5,5,5,6,6,6},
    {0,7,7,7,8,8,8,9,9,9},
    {0,7,7,7,8,8,8,9,9,9},
    {0,7,7,7,8,8,8,9,9,9},
};
void print(){
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
           printf("%d ",mp[i][j]);
        }
        printf("\n");
    }
    exit(0);
}
void dfs(int x,int y){
    if (y==10)
    {
        dfs(x+1,1);
    }
    if (x==10)
    {

    }
    if (mp[x][y]!=0)
    {
        dfs(x,y+1);
    }
    else{
    for (int i = 1; i <= 9; i++)
    {
        if (a[x][i]==0&&b[y][i]==0&&c[block[x][y]][i]==0)
        {
            mp[x][y]=i;
            a[x][i]=1;
            b[y][i]=1;
            c[block[x][y]][i]=1;
            if(x==9&&y==9)                   
                print();
            if(y==9) dfs(x+1,1); else dfs(x,y+1);
            a[x][i]=0;
            b[y][i]=0;
            c[block[x][y]][i]=0;
        }
        
    }
    }
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            scanf("%d",&mp[i][j]);
            a[j][mp[i][j]]=1;
            b[i][mp[i][j]]=1;
            c[block[j][i]][mp[i][j]]=1;
        }
    }
    dfs(1,1);
    return 0;
}