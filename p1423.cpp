#include<bits/stdc++.h>
using namespace std;
int a;
double m,v,c;
int main(){
    scanf("%lf",&m);
    c=2;
    for (int i = 1; v<=m; i++)
    {
        v=v+c;
        c=c*0.98;
        a=i;
    }
    printf("%d",a);
}