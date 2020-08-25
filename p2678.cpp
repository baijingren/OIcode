#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int l,n,m,a[1000005];//a是坐标，l是全程长度，n是石头个数，m是移走的石头
int jud(int x){//x是间隔
    int sum=0,f=0;//sum是满足间隔下走过的石头数，f是当前的坐标（石头）
    for (int i = 1; i <= n; i++)
    {
        if (a[i]-f>=x)
        {
            sum++;
            f=a[i];
        }
    }
    return n-sum;
}
int main(){
    scanf("%d %d %d",&l,&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    int lt=1,rt=l;
    while (lt<rt)
    {
        int mid=(lt+rt+1)/2;
        if(jud(mid)<=m) lt=mid;
        else rt=mid-1;
    }
    printf("%d",lt);
    return 0;
}