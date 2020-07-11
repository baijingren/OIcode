#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int n,r,a[100];
void f(int x){
    if (x==r+1)
    {
        for (int i = 1; i <= r; i++)
        {
            printf("%3d",a[i]);
        }
        printf("\n");
        return;
    }
    
    for (int i = a[x-1]+1; i <= n; i++)
    {
        a[x]=i;
        f(x+1);
    }
}
int main(){
    scanf("%d %d",&n,&r);
    f(1);
    return 0;
}