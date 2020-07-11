#include<bits/stdc++.h>
using namespace std;
int n,c,a[1000005];
int jud(int x){//x是间隔
    int sum=1,f=a[1];//sum是满足间隔下可以放的牛头数，f是当前的坐标（牛棚）
    for (int i = 1; i <= n; i++)
    {
        if (a[i]-f>=x)
        {
            sum++;
            f=a[i];
        }
    }
    return sum;
}
int main(){
    scanf("%d %d",&n,&c);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int l=1,r=a[n];
    while (l<r)
    {
        int mid=(l+r+1)/2;
        if(jud(mid)>=c) l=mid;
        else r=mid-1;
    }
    printf("%d",l);
    return 0;
}