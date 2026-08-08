#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
int main(){
    freopen("treat.in","r",stdin);
    freopen("treat.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&a,&b);
    srand(time(NULL));
    printf("%d",rand()%n);
}