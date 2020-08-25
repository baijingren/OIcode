#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[1000005];
int main(){
    cin>>n;
    for (int i = 0; i <= n; i++)
    {
        cin>>a[i];
    }
    if(a[0]!=0) printf("%dx^%d",a[0],n);
        for (int i = 1; i < n; i++)
        {
            if(a[i]==0) continue;
            if (a[i]==1)
            {
                printf("+");
            }
            else if (a[i]==-1)
            {
                printf("-");
            }
            else if (a[i]>0)
            {
                printf("+%d",a[i]);
            }
            else
            {
                printf("%d",a[i]);
            }
            printf("x^");
            printf("%d",n-i);
        }
        if(a[n]>0) printf("+%d",a[n]);
        else if (a[n]<0) printf("%d",a[n]);
    return 0;
}