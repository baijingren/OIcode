#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
float l[10005];
int n,k;
int str(int x){
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        if (l[i]*100>=x)
        {
            cnt+=l[i]*100/x;
        }
        
    }
    return cnt;
}
int main(){
    scanf("%d %d",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&l[i]);
    }
    sort(l+1,l+n+1);
    int ls=0,rs=l[1]*100;
    while(ls<rs)
    {
        int mid=(ls+rs)/2;
        if(str(mid)>=k) ls=mid;
        else if(str(mid)<k) rs=mid;
    }
    printf("%.2f",rs/100);
    return 0;
}