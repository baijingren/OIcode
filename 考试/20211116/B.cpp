#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
int a[qwe],l[qwe],r[qwe],k[qwe];
// int f[qwe];
bool vis[qwe];
struct Node{
    int w,id;
    // bool operator< (const Node d) const { return w < d.w; }
    Node(int a,int b){
        id=a;
        w=b;
    }
};
bool operator< (const Node a,const Node b){
    return a.w<b.w;
}
void del(int i){
    l[r[i]]=l[i];
    r[l[i]]=r[i];
    vis[i]=1;
}
priority_queue<Node> q;
// queue<Node> q;
void init(bool mode){
    while(!q.empty()){
        q.pop();
    }
    memset(vis,0,sizeof(vis));
    memset(k,0,sizeof(k));
    int kkksc03=mode?n-1:n;
    int chen_zhe=mode?1:2;
    for(int i=chen_zhe;i<=kkksc03;i++){
        l[i]=i-1;
        r[i]=i+1;
    }
    for(int i=chen_zhe;i<=kkksc03;i++){
        k[i]=a[i];
        q.push(Node(i,k[i]));
    }
    k[chen_zhe-1]=k[kkksc03+1]=-0x3f3f3f3f;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(m>n/2){
        printf("Error!");
        return 0;
    }
    // for(int i=1;i<=n*2;i++){
        // for(int j=1;j<=m;j++){
            // f[i][j]=max(f[i-1][j],f[i-2][j-1]+a[j]);
        // }
    // }
    init(0);
    int ans=0;
    for(int i=1;i<=m;i++){
        int t=q.top().id;
        q.pop();
        if(vis[t]){
            i--;
            continue;
        }
        ans+=k[t];
        k[t]=k[l[t]]+k[r[t]]-k[t];
        del(l[t]);
        del(r[t]);
        q.push(Node(t,k[t]));
    }
    init(1);
    int anss=0;
    for(int i=1;i<=m;i++){
        int t=q.top().id;
        q.pop();
        if(vis[t]){
            i--;
            continue;
        }
        anss+=k[t];
        k[t]=k[l[t]]+k[r[t]]-k[t];
        del(l[t]);
        del(r[t]);
        q.push(Node(t,k[t]));
    }
    printf("%d",max(ans,anss));
    return 0;
}