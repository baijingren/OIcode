#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[10000005];
int jud(int x){
    long long f=0;
    for (int i = 1; i <= n; i++)
    {
        if(a[i]>x) f+=a[i]-x;
    }
    return f;
}
int main(){
    scanf("%d %d",&n,&m);
    for (int i = 1; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int l=0,r=a[n];
    while (l<r)
    {
        int mid=(l+r+1)/2;
        if(jud(mid)>=m) l=mid;
        else r=mid-1;
    }
    printf("%d",l);
    return 0;
}