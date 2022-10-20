#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,k;
int t[qwe],x[qwe],y[qwe];
bool chk(int x){
    int 
}
int main(){
    scanf("%d%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&t[i],&x[i],&y[i]);
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(chk(mid)){
            l=mid;
        }
        else{
            r=mid+1;
        }
    }
}