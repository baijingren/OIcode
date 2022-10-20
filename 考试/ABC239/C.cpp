#include<bits/stdc++.h>
using namespace std;
#define ll long long
int xa,xb,ya,yb;
int mp[2][8]={
    {1,2,2,1,-1,-2,-2,-1},
    {2,1,-1,-2,-2,-1,1,2}
};
ll calc(int a,int b,int c,int d){
    ll x=(ll)(a-c)*(ll)(a-c);
    ll y=(ll)(b-d)*(ll)(b-d);
    return x+y;
}
int main(){
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    for(int i=0;i<8;i++){
        int xx=xa+mp[0][i],yy=ya+mp[1][i];
        if(abs(calc(xx,yy,xb,yb))==5){
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}