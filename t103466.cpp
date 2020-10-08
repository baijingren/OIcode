#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,a[1000005];
int lei(int x){
    if(x==1) return 1;
    if(a[x]==0&&a[x-1]==0&&a[x+1]==0&&x+1<=n&&x-1>0) return 3;
    return lei(x-1)+lei(1);
}
int main(){

    return 0;
}