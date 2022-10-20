#include<bits/stdc++.h>
using namespace std;
int a,b;
void exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    int tmp=x;
    x=y;
    y=tmp-(a/b)*y;
}
    int x,y;
int main(){
    scanf("%d%d",&a,&b);
    exgcd(a,b,x,y);
    // while(x<0){
    x=(x%b+b)%b;
    // }
    printf("%d\n",x);
}