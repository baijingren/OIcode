#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100005],n;
int main(){
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int m=0;
    for (int i = 1; i <= n; i++)
    {
        if(a[i]==a[i+1])
        {
        a[i]=0;
        m++;
        }
    }
    sort(a+1,a+n+1);
    printf("%d\n",n-m);
    for (int i = 1+m; i <= n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}