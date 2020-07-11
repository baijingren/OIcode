#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1005],b[1005],c[1005];
char aa[1005],ba[1005];
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%s%s",aa,ba);
    int al=strlen(aa),bl=strlen(ba);
    for (int i = 0; i < al; i++)
    {
        a[al-i-1]=al[i]-48;
    }
    for (int i = 0; i < bl; i++)
    {
        b[bl-i-1]=ba[i]-48;
    }
    int m=
    return 0;
}