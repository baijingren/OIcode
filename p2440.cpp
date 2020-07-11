#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,a[1000005],sum;
int f(int x){
    int cnt=0;
    for (int i=1; i<=n; i++)
    {
        if (a[i]>=x)
        {
            cnt=cnt+a[i]/x;
        }
        
    }
    return cnt;
}
int main(){
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    int l=0,r=sum/n;
    while (l<r)
    {
        int mid=(l+r+1)/2;
        if(f(mid)>=k) l=mid;
        else r=mid-1;
    }
    printf("%d",l);
    return 0;
}