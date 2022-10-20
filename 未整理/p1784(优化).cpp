#include<bits/stdc++.h>
using namespace std;
struct node
{
    int id,cnt;
};
node lin[55];
int nex[10];
int a[15][15],t=81;
int h[10][10],l[10][10],g[10][10];
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
bool cmp(node x,node y){
    return x.cnt>y.cnt;
}
void print(){
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return;
}
void dfs(int x,int y,int z){
    if (x==0)
    {
        print();
        exit(0);
    }
    if(z == 10) y = nex[y], z=1;
    if(a[y][z]) dfs(x,y,z+1);
    else{
      int tc=block[y][z];
      for(int i=1;i<=9;i++) 
  		if(!h[y][i] && !l[z][i] && !g[tc][i])
        {
            a[y][z]=i;
            h[y][i]=1;
      		l[z][i]=1;
      		g[tc][i]=1;
            dfs(x-1, y, z+1);
            h[y][i]=0;
      		l[z][i]=0;
      		g[tc][i]=0;
            a[y][z]=0;
     		}
    }
}
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    for (int i = 1; i < 10; i++)
    {
        int sum=0;
        lin[i].id=i;
        for (int j = 1; j < 10; j++)
        {
            scanf("%d",&a[i][j]);
            if (a[i][j]>0)
            {
                h[i][a[i][j]]=1; 
                l[j][a[i][j]]=1; 
                g[block[i][j]][a[i][j]]=1;
                t--;
                sum++;
            }
        }
        lin[i].cnt=sum;
    }
    sort(lin+1,lin+10,cmp);
    for (int i = 1; i < 10; i++)
    {
        nex[lin[i].id]=lin[i+1].id;
    }
    dfs(t,lin[1].id,1);//t→x是剩下的空位，lin【1】.id→y是数据最多的行的ID，1→z是列
}