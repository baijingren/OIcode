#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int qwe=1e3+5;
int n,k;
int tw[qwe],fv[qwe];
void chk(ll x,int id){
    ll xx=x;
    while(xx>0){
        if(xx%2==0){
            xx/=2;
            tw[id]++;
        }
        else{
            break;
        }
    }
    xx=x;
    while(xx>0){
        if(xx%5==0){
            xx/=5;
            fv[id]++;
        }
        else{
            break;
        }
    }
}
struct Node{
    int te,to,fi;
// } f[qwe][qwe];
} f[qwe];
Node node(int x,int y){
    Node kk;
    kk.to=y;
    kk.fi=x;
    kk.te=min(x,y);
    return kk;
}
Node max(Node x,Node y){
    // printf("%d %d %d %d\n",x.fi,x.to,y.fi,y.to);
    return (x.te>=y.te)?x:y;
}
Node operator+(Node x,Node y){
    x.fi+=y.fi;
    x.to+=y.to;
    x.te=min(x.fi,x.to);
    return x;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        ll x;
        scanf("%lld",&x);
        chk(x,i);
    }
    // f[0][0]={0,0,1};
    for(int i=1;i<=n;i++){
        for(int j=k;j>=1;j--){
        // for(int j=1;j<=k;j++){
            // f[i][j]=max(f[i-1][j],f[i-1][j-1]+node(fv[i],tw[i]));
            f[j]=max(f[j],f[j-1]+node(fv[i],tw[i]));
        }
    }
    // for(int i=1;i<=k;i++){
    //     // printf("%d ",f[n][i].te);
    //     printf("%d ",f[k].te);
    // }
    printf("%d",f[k].te);
}