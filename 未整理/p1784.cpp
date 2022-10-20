#include<bits/stdc++.h>
int a[10][10];
bool h[10][10],l[10][10],g[10][10];
void print()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    exit(0);
}
void dfs(int x,int y) 
{
    if(a[x][y]!=0)
    {
        if(x==9&&y==9) 
            print(); 
        if(y==9) 
            dfs(x+1,1); 
        else 
            dfs(x,y+1);
    }
    if(a[x][y]==0)
    {
        for(int i=1;i<=9;i++)
        { 
            if(h[x][i]&&l[y][i]&&g[(x-1)/3*3+(y-1)/3+1][i])
            {
                a[x][y]=i;
                h[x][i]=false; 
                l[y][i]=false; 
                g[(x-1)/3*3+(y-1)/3+1][i]=false; 
                if(x==9&&y==9)                    
                    print();
                if(y==9) dfs(x+1,1); else dfs(x,y+1);
                a[x][y]=0;
                h[x][i]=true;
                l[y][i]=true;
                g[(x-1)/3*3+(y-1)/3+1][i]=true;
            }
        } 
    }
}
int main()
{
    memset(h,true,sizeof(h));
    memset(l,true,sizeof(l));
    memset(g,true,sizeof(g));
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]>0)
            {
                h[i][a[i][j]]=false; 
                l[j][a[i][j]]=false; 
                g[(i-1)/3*3+(j-1)/3+1][a[i][j]]=false;
            }
        }
    } 
    dfs(1,1);
    return 0;
}