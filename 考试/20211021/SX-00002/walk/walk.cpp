#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,k;
int w[qwe],I[10],C[qwe],D[qwe];
int dfs(int a,int b,int c,int d,int e,int t,int s){
    // if()
    if(a>w[1]||b>w[2]||c>w[3]||d>w[4]||e>w[5]){
        return t;
    }
    if(s>n){
        s=1;
    }
    switch (C[s])
    {
        case 1:
            dfs(a+D[s],b,c,d,e,t+1,s+1);
            break;

        case 2:
            dfs(a,b+D[s],c,d,e,t+1,s+1);
            break;

        case 3:
            dfs(a,b,c+D[s],d,e,t+1,s+1);
            break;

        case 4:
            dfs(a,b,c,d+D[s],e,t+1,s+1);
            break;

        case 5:
            dfs(a,b,c,d,e+D[s],t+1,s+1);
            break;
    }
}
int main(){
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d%d",&C[i],&D[i]);
    }
    for(int i=1;i<=w[1];i++){
        for(int j=1;j<=(w[2]?w[2]:1);j++){
            for(int l=1;l<=(w[3]?w[3]:1);l++){
                for(int o=1;o<=(w[4]?w[4]:1);o++){
                    for(int p=1;p<=(w[5]?w[5]:1);p++){
                        printf("%d\n",dfs(i,j,l,o,p,0,1));
                    }
                }
            }
        }
    }
}