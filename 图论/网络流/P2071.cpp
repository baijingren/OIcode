#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n;
int cnt=1,hd[qwe];
struct Edge{
    int to,nxt;
} edge[qwe];
void add(int u,int v,int w){
    cnt++;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d",&x,&y);
        add(x,y,1);
        add(y,x,0);
    }
    while(bfs()){
        int flow=0;
        while(flow=dinic(s,INT_MAX)){
            mxflow+=flow;
        }
    }
}