#include<bits/stdc++.h>
using namespace std;
const int qwe=30001;
int n,m,u,v;
char c;
int f[qwe],d[qwe],num[qwe];
int fnd(int x){
    if(f[x]==x)return x;
    int fa=fnd(f[x]);
    d[x]+=d[f[x]];
    return f[x]=fa;
}
void merge(int u,int v){
    int x=fnd(u),y=fnd(v);
    f[x]=y;
    d[x]=num[y];
    num[y]+=num[x];
}
int main(){
    freopen("/home/bai/code/test.in", "r", stdin);
    int T=0;
    scanf("%d\n",&T);
    for(int i=1;i<=30000;i++){
        f[i]=i;
        d[i]=0;
        num[i]=1;
    }
    for(int i=1;i<=T;i++){
        scanf("%c %d %d\n",&c,&u,&v);
        if(c=='M'){
            merge(u,v);
        }
        if(c=='C'){
            int x=fnd(u),y=fnd(v);
            if(x==y){
                printf("%d\n",abs(d[u]-d[v])-1);
            }
            else{
                printf("-1\n");
            }
        }
    }
    return 0;
}