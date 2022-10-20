#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    int x=k%n;
    if(x==0){
        x=n;
    }
    int y=k/n;
    printf("%d %d %d",x,y,x*y);
    return 0;
}