#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int qwe=1e6+5;
int mod=1e6+3;
int n,l,r;
int jc[qwe],jd[qwe];
ll pw(int x,int y){
    
}
void init(){
    int jc[1]=1;
    for(int i=1;i<mod;i++){
        jc[i]=jc[i-1]*i;
        jd[i]=pw(jc[i-2],mod-1);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    init();
    while(T--){
        scanf("%d%d%d",&n,&l,&r);
    }
}