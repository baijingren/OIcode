#include<bits/stdc++.h>
using namespace std;
int m=0,s,chu,y[17];
int main(){
    for (int i = 1; i <=12; i++)
    {
        scanf("%d",&y[i]);
    }
    for (int i = 1; i <=12; i++)
    {
        m+=300;
        m=m-y[i];
        if(m<0)
        {
            printf("-%d",i);
            return 0;
        }
        if (m>=100)
        {
            s=s+m/100;
            m=m%100;
        }
    }
    printf("%d",(s*120+m));
    return 0;
}