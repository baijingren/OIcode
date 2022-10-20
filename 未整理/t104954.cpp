#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[1000005],cnt=0;
bool f(int x){
    int suma=0,sumb=0,s[1000005];
    for (int i = 1; i <= n; i++)
    {
        s[i]=a[i];
    }
    s[x]=0;
    for (int i = 1; i < x; i+=2)
    {
        suma+=s[i];
        sumb+=s[i+1];
    }
    if(x%2==1)
    {
        for (int i = x+1; i <= n; i+=2)
        {
            suma+=s[i];
            sumb+=s[i+1];
        }
    }
    else
    {
        for (int i = x; i <= n; i+=2)
        {
            suma+=s[i];
            sumb+=s[i+1];
        }
    }
    if(suma==sumb) return true;
    else return false;
}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if(f(i)==true) cnt++;
    }
    printf("%d",cnt);
    return 0;
}