#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int w,n,a[300005];
int f(int x){
    int l=1,r=n,ans=0;
    while(l<=r)
    {
        if(a[l]+a[r]<=w)
          l++,r--,ans++;
        else
          r--,ans++;
    }
    return ans;
}
int main(){
    scanf("%d%d",&w,&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    printf("%d",f(w));
    return 0;
}