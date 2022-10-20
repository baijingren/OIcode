#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
int ans;
struct Node{
    int x,y;
} a[qwe],b[qwe];
int len(Node a,Node b){
    int x=a.x-b.x,y=a.y-b.y;
    double l=sqrt(x*x+y*y);
    return (int)l;
}
bool clc(Node a,Node c,Node b){
    if(len(a,c)+len(c,b)<=len(b,a)*2){
        return 1;
    }
    return 0;
}
bool vis[qwe];
int dep[qwe];
bool bfs(){
    memset(dep,0,sizeof(dep));
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&b[i].x,&b[i].y);
        for(int i=1;i<=n;i++){
            // if(clc(a[i],b[i],a[i+1]) && !vis[i]){
            //     ans++;
            //     break;
            // }

        }
    }
    printf("%d",ans);
}