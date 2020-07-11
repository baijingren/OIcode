#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int a,x[1005];
int f(int n){
    if(x[n]!=0) return x[n];
    int sum=1;
    if(n==1) return 1;
    for (int i = 1; i <= n/2; i++)
    {
        int ss=f(i);
        sum+=ss;
    }
    x[n]=sum;
    return x[n];
}
int main(){
    scanf("%d",&a);
    printf("%d",f(a));
    return 0;
}