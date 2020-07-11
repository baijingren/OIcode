#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int n,nn,s,x,m,b;
int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        nn=nn*10;
    }
    nn=nn-1;
    for (int i = 1; i <= nn; i++)
    {
        while (s>0)
        {
            x[i]=s%10;
                s=s/10;
        }
        for (int j = 0; j < nn; j++)
        {
            if(x[j]==3)
                m++;
        }
        if (m%2==0)
        {
            b++;
        }
    }
    printf("%d",b);
    return 0;
}