#include<bits/stdc++.h>
using namespace std;
const int qwe=1005;
int n,m;
int a[qwe][qwe],l[qwe][qwe],r[qwe][qwe];
bool v[qwe][qwe];
int mp[2][4]={
    {0,-1,1,0},
    {-1,0,0,1}
};
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){
            y=-1;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x*=10;
        x+=(ch-'0');
        ch=getchar();
    }
    return x*y;
}
void dfs(int x,int y){
    // if(x<=0||x>n||y<=0||y>m){
    //     return;
    // }
    v[x][y]=1;
    for(int i=0;i<4;i++){
        int vx=x+mp[0][i],vy=y+mp[1][i];
        if(vx<=0||vx>n||vy<=0||vy>m) continue;
        if(a[x][y]<=a[vx][vy]) continue;
        // if(v[vx][vy]) continue;
        // dfs(vx,vy);
        if(!v[vx][vy]) dfs(vx,vy);
        l[x][y]=min(l[x][y],l[vx][vy]);
        r[x][y]=max(r[x][y],r[vx][vy]);
    }
}
int main(){
    freopen("/home/bai/code/ab.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=read();
        }
    }
    memset(l,0x3f,sizeof(l));
    for(int i=1;i<=m;i++){
        l[n][i]=r[n][i]=i;
    }
    for(int i=1;i<=m;i++){
        if(!v[1][i])
            dfs(1,i);
    }
    int num=0;
    for(int i=1;i<=m;i++){
        if(!v[n][i]) num++;
    }
    if(num){
        printf("0\n%d\n",num);
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<i<<' '<<j<<' ';
            cout<<'l'<<' '<<l[i][j]<<' '<<'r'<<' '<<r[i][j]<<endl;
        }
    }
    int lft=1;
    while (lft<=m){
        int mxr=0;
        for (int i=1;i<=m;i++)
            if (l[1][i]<=lft)
                mxr=max(mxr,r[1][i]);
        num++;
        lft=mxr+1;
    }
    printf("1\n%d\n",num);
    // queue<int> qx,qy;
    // qx.push(1);
    // qy.push(1);
    // v[1][1]=1;
    // while(!qx.empty()&&!qy.empty()){
    //     int ux=qx.front(),uy=qy.front();
    //     for(int i=0;i<4;i++){
    //         int vx=ux+mp[0][i],vy=uy+mp[1][i];
    //         if(v[vx][vy]) continue;
    //         if(a[vx][vy]>a[ux][uy]) continue;
    //         qx.push(vx);
    //         qy.push(vy);
    //         v[vx][vy]=v[ux][uy];
    //     }
    // }
    // int 
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=4;j++){
    //         int vx=ux+
    //     }
    // }
    return 0;
}