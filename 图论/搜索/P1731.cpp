#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, m, ans=0, V,prt=INT_MAX;
int r[qwe],h[qwe],mv[qwe],ms[qwe];
struct Node{
    int id, r, h;
    Node(int a,int b,int c){
        id = a, r = b, h = c;
    }
};
void dfs(int x,int R,int H)
{
    if(x==m+1){
        if(V!=n){
            return;
        }
        if(V==n){
            prt=min(prt,ans);
            return;
        }
    }
    if(V>n){
        return;
    }
    if(s+2*(n-V)/R>ans){

    }
//    int sqrtn=sqrt(n);
    for (int i = R-1; i > x-1; i--)
    {
        if(x==1){
            ans = i * i;
        }
        for (int j = R-1; j > x-1;j--) {
            // r[x+1]=i;
            // h[x+1]=j;
            ans+=i*j*2;
            V+=i*i*j;
            dfs(x+1,i,j);
            ans-=i*j*2;
            V-=i*i*j;
            // r[x+1]=0;
            // h[x+1]=0;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        mv[i]=mv[i-1]+i*i*i;
        ms[i]=ms[i-1]+2*i*i;
    }
    dfs(1,sqrt(n),n);
    printf("%d",prt);
}