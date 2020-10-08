#include<bits/stdc++.h>
using namespace std;
int h,w,cnt=0;
char a;
int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d%d",&h,&w);
    for (int i = 1; i <= h*w; i++)
    {
            cin>>a;
            if (a=='#')
            {
                cnt++;
            }
    }
    if (cnt==h+w-1)
    {
        printf("Possible");
    }
    else
    {
        printf("Impossible");
    }
    return 0;
}