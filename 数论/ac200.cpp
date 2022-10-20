#include<bits/stdc++.h>
using namespace std;
const int qwe=100005;
int n,cnt,aa,ab,ba,bb;
int r[qwe],v[qwe];
void shai(int n){
    cnt=0;
    for(int i=2;i<=n;i++){
        if(v[i]==0){
            v[i]=r[cnt++]=i;
        }
        for(int j=0;j<cnt;j++){
            if(r[j]>v[i]||r[j]>n/i) break;
            v[r[j]*i]=r[j];
        }
    }
}
int gcd(int x,int y){
    if(y==0){
        return 
    }
}
int main(){
    shai(sqrt(2e9));
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&aa,&ab,&ba,&bb);
        for(int i=1;i<=n;i++){
            
        }
    }
}