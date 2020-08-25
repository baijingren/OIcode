#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int x[10000],y[10000],n,d;
int main(){
    scanf("%d %d",&n,&d);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if(y[i]>d)
        {
            printf("-1");
            return 0;
        }
    }
    
    return 0;
}