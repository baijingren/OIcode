#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
long long a[100005],ss=1,b=1e9+7;
int n;
int main(){
    scanf("%d",&n);
    a[0]=1;
    for (int i = 1; i <= n; i++)
    {
        a[i]=a[i-1]*3;
        ss+=a[i]%b;
    }
    printf("%lld",ss%b);
    return 0;
}