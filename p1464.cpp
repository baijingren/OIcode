#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int s[100][100][100],m,n,o;
int f(int a,int b,int c)
{
    int ss;
    if (a<=0||b<=0||c<=0)
    {
        return 1;
    }
    else if (a>20||b>20||c>20)
    {
        if(s[20][20][20]!=0) return s[20][20][20];
        else{
        s[20][20][20]=f(20,20,20);
        }
    }
    else if (a<b&&b<c)
    {
        ss=s[a][b][c-1]+s[a][b-1][c-1]-s[a][b-1][c-1];
        if(ss!=0) return ss;
        else{
        s[a][b][c-1]=f(a,b,c-1);
        s[a][b-1][c-1]=f(a,b-1,c-1);
        s[a][b-1][c-1]=f(a,b-1,c);
        }
    }
    else
    {
        ss=s[a-1][b][c]+s[a-1][b-1][c]+s[a-1][b][c-1]-s[a-1][b-1][c-1];
        if(ss!=0)   return ss;
        else
        {
            s[a-1][b][c]=f(a-1,b,c);
            s[a-1][b-1][c]=f(a-1,b-1,c);
            s[a-1][b][c-1]=f(a-1,b,c-1);
            s[a-1][b-1][c-1]=f(a-1,b-1,c-1);
        }
        
    }
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    long long a,b,c;
    while(scanf("%lld%lld%lld",&a,&b,&c)==3){
        memset(s,0,sizeof(s));
        if(a==-1&&b==-1&&c==-1) break;
        printf("w(%lld, %lld, %lld) = ",a,b,c);
        if(a>20) a=21;
        if(b>20) b=21;
        if(c>20) c=21;
        printf("%lld\n",f(a,b,c));
    }
    return 0;
}