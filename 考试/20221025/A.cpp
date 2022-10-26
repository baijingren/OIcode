#include<bits/stdc++.h>
using namespace std;
const int qwe=505;
int n,m;
int a[qwe][qwe];
int mp[2][5]={
    {0,-1,0,0,1},
    {0,0,-1,1,0}
};
struct Node{
    int x,y,dir;
    Node()=default;
    Node(int a,int b,int c){
        x=a,y=b,dir=c;
    }
};
queue<Node> q;
bool vis[qwe][qwe];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            switch (c)
            {
            case 'D':
                a[i][j]=1;
                break;
            
            case 'L':
                a[i][j]=2;
                break;
            
            case 'R':
                a[i][j]=3;
                break;

            case 'U': 
                a[i][j]=4;
                break;
            default:
                a[i][j]=0;
                break;
            }
        }
    }
    q.emplace(1,1,1);
    while(!q.empty()){
        auto u=q.front();
        if(a[u.x][u.y]==0){
            continue;
        }
        for(int i=1;i<=4;i++){
            if(a[u.x][u.y]==i){
                continue;
            }
            int vx=u.x+mp[0][i],vy=u.y+mp[1][i];
            if(vis[vx][vy] || vx>m || vy>n || vx<0|| vy<0){
                continue;
            }
            if()
            
        }
    }
}