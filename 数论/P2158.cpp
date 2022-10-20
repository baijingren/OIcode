#include<bits/stdc++.h>
using namespace std;
const int qwe=100005;
int n,q,cnt,ans=3;
int v[qwe],r[qwe],e[qwe];
void eular(int x){
    cnt=0;
    for(int i=2;i<x;i++){
        if(v[i]==0){
            v[i]=i;
            r[++cnt]=i;
            e[i]=i-1;
        }
        ans+=e[i]*2;
        for(int j=1;j<=cnt;j++){
            if(r[j]>v[i]||r[j]>x/i) break;
            v[r[j]*i]=r[j];
            if(i%r[j]!=0){
                e[r[j]*i]=e[r[j]]*e[i];
            }else{
                e[r[j]*i]=r[j]*e[i];
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    e[1]=1;
    if(n==1){
        printf("%d",0);
    }else{
        eular(n);
        printf("%d",ans);
    }
    return 0;
}