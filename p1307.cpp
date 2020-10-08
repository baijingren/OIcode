#include<bits/stdc++.h>
using namespace std;
int i,sa[15],o,sv,b;
int main(){
    scanf("%d",&i);
    sv=i;
    while (sv!=0)
    {
        sv=sv/10;
        b++;
    }
    sv=i;
    if (i>=0)
    {
        for (int j=1;j<=b;j++)
        {
            sa[b-j]=sv%10;
            sv=sv/10;
        }
        for (int j=b-1;j>=0;j--)
        {
            printf("%d",sa[j]);
        }
    }
    if (i<0)
    {
        sv=sv*(-1);
        for (int j=1;j<=b;j++)
        {
            sa[b-j]=sv%10;
            sv=sv/10;
        }
        printf("-");
        for (int j=b-1;j>=0;j--)
        {
            printf("%d",sa[j]);
        }
    }
    if(i==0)
        printf("0");
    return 0;
}