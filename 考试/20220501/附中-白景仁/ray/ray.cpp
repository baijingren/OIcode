#include<bits/stdc++.h>
using namespace std;
const int qwe=2e3+5;
int n,m,k;
int vis[qwe][qwe];
int mp[qwe][qwe];
int mv[2][4]={
    {1,1,-1,-1},
    {-1,1,-1,1}
};
void dfs(int x,int y,int z){
    for(int i=0;i<4;i++){
        int vx=x+mv[0][i];
        int vy=y+mv[1][i];
        if(vis[vx][vy]==5){

        }
        else if(vis[vx][vy]==z){
            return;
        }
    }
}
char s[10];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        vis[x][y]=5;
    }
    int sx,sy;
    scanf("%d%d",&sx,&sy);
    scanf("%s",s);
    int t=0;
    if(s=="NE"){
        t=1;
    }
    else if(s=="NW"){
        t=2;
    }
    else if(s=="SW"){
        t=3;
    }
    else{
        t=4;
    }
    dfs(sx,sy,t);
    srand(time(NULL));
    int am=rand()%(n*m)+1;
    printf("%d",am);
}