#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int a,b,c;
int f(int m,int n){
    if(m<n) return f(m,m);
    if(n==1||m==0) return 1;
    return f(m-n,n)+f(m,n-1);
}
int main(){
    scanf("%d",&a);
    for(int i =1;i <= a;i++)
    {
    scanf("%d %d",&b,&c);
    printf("%d\n",f(b,c));
    }
    return 0;
}