#include<bits/stdc++.h>
using namespace std;
const int qwe=1e2+5;
int n;
int a[qwe],b[qwe];
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<0){
            a[i]=-a[i];
        }
    }
    int x=0;
    for(int i=1;i<=n;i++){
        x=gcd(x,a[i]);
    }
    printf("%d",x);
    return 0;
}