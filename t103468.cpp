#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[1000005];
int mon(int x){
    int cnt=1,f=0;
    for (int i = 1; i <= n; i++)
    {
        if(f+a[i]>x)
        {
            cnt++;
            f=a[i];
        }
        else
        {
            f+=a[i];
        }
        
    }
    return cnt;
}
int main(){
    int sum=0;
    scanf("%d %d",&n,&m);
    m++;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    int l=a[n],r=sum;
    while (l<r)
    {
        int mid=(l+r+1)/2;
        if(mon(mid)>=m) l=mid;
        else r=mid-1;
    }
    printf("%d",l);
    return 0;
}