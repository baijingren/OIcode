#include<bits/stdc++.h>
using namespace std;
//用pair存点
#define x first
#define y second
typedef long long ll;
typedef pair<int,int> pr;
const int qwe=1e3+5;
int n,m,q;
pr p[qwe],c[qwe];
int r[qwe];
bitset<qwe> st[qwe];
ll sqr(ll x){
    return x*x;
}
int chk(int a,int b){
    ll dx=p[a].x-c[b].x;
    ll dy=p[a].y-c[b].y;
    if(sqr(dx)+sqr(dy)>sqr(r[b])) return 1;
    return 0;
}
int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&r[i],&c[i].x,&c[i].y);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            st[i][j]=chk(i,j);
        }
    }
    for(int i=1;i<=q;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%ld\n",(st[a]^st[b]).count());
    }
    return 0;
}