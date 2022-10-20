#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int v[qwe],r[qwe];
void shai(int x){
    int cnt=0;
    for(int i=2;i<=x;i++){
        if(v[i]==0){
            v[i]=i;
            r[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++){
            if(r[j]>v[i]||r[j]>x/i) break;
            v[r[j]*i]=r[j];
        }
    }
}
int main(){
    freopen("biao.out","w",stdout);
    shai(10000);
    for(int i=1;i<400;i++){
        printf("%d,",r[i]);
        printf("%d,",__builtin_popcount(i));
    }
    // printf("%d",__builtin_popcount(400));
    return 0;
}