#include<bits/stdc++.h>
using namespace std;
const int qwe=1e3+5;
int n,cnt=0;
int a[qwe][qwe];
int mp[2][4]={
    {1,0,-1,0},
    {0,1,0,-1}
};
bool chk(int x,int y){
    return x>0 && y>0 && x<=n && y<=n;
}
void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int vx=x+mp[0][i];
        int vy=y+mp[1][i];
        if(chk(vx,vy) && !a[vx][vy]){
            a[vx][vy]=1;
            dfs(vx,vy);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!a[i][j]){
                cnt++;
                dfs(i,j);
            }
        }
    }
    printf("%d",cnt);
}