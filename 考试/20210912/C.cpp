#include<bits/stdc++.h>
using namespace std;
const int qwe=100005;
int n;
int a[qwe],d[qwe];
int ed[qwe][5],f[qwe][21],ans[qwe][5];
bool v[qwe];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d%d",&ed[i][1],&ed[i][2]);
    }
    queue<int> q;
    q.push(1);
    v[1]=1;
    d[1]=1;
    f[0][0]=0;
    int t=log2(n);
    while(q.size()){
        int u=q.front();
        q.pop();
        if(u==0){
            continue;
        }
        int vl=ed[u][1],vr=ed[u][2];
        // fa[vl]=u;
        // fa[vr]=u;
        f[vl][0]=u;
        f[vr][0]=u;
        d[vl]=d[vr]=d[u]+1;
        for(int i=1;i<=t;i++){
            f[vl][i]=f[f[vl][i-1]][i-1];
            f[vr][i]=f[f[vr][i-1]][i-1];
        }
        q.push(vl);
        q.push(vr);
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=t;j++){
            cout<<f[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        int l=i;
        if(a[i]>d[i]) continue;
        for(int j=t;j>=1;j--){
            if(d[f[l][j]]-d[l]<=a[l]-1&&d[f[l][j]]-d[l]>=0){
                l=f[l][j];
            }
        }
        int v=f[l][0];
        if(ed[v][1]==l){
            ans[v][1]++;
        }
        else{
            ans[v][2]++;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d %d\n",ans[i][1],ans[i][2]);
    }
}