#include<bits/stdc++.h>
using namespace std;
const int N=25;
const int M=410;
int n,m,k;
int b[N];
int a[N][N];
int vis[N][N];
struct Node{
    int x,y;
    int b[10];
    Node(){}
    Node(int a,int c){
        x=a,y=c;
    }
};
Node nw;
queue<Node> q;
int mp[][]={
    {},
    {}
};
bool chk(int x){
    int num=0;
    int tmp=1;
    int x=nw.x,y=nw.y;
    for(int i=1;i<k;i++){
        int vx=x+mp[0][nw.b[i]];
        int vy=y+mp[1][nw.b[i]];
        if(vx==nw.x && vy==nw.y){
            return 0;
        }
        num+=
    }
}
void bfs(){
    for(int i=1;i<k;i++){
        nw.b[i]=b[i];
    }
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    int lu,lv;
    for(int i=1;i<=k;i++){
        int u,v;
        cin>>u>>v;
        if(u==lu+1){
            b[i]=0;
        }
        else if(u==lu-1){
            b[i]=1;
        }
        else if(v==lv+1){
            b[i]=2;
        }
        else if(v==lv-1){
            b[i]=3;
        }
        lv=v,lu=u;
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        a[u][v]=0;
    }
    return 0;
}