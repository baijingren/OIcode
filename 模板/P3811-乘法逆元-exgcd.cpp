#include<bits/stdc++.h>
using namespace std;
int n,p;
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int t=y;
    x=y;
    y=t-(a/b)*y;
    return d;
}

int main(){
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++){
        
    }
}