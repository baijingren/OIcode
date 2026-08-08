#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int a[qwe];

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int a,b,c,d;
        a=n-3;
        b=c=d=1;
        // c=d=1;
        // n-=2;
        // if(n<=3){
            // a=1,b=n-1;
        // }
        // else if(n%3!=0){
            // a=n-3;
            // b=3;
        // }
        // else{
            // n--;
            // c++;
            a=n-3;
            // b=3;
        // }
        printf("%d %d %d %d\n",a,b,c,d);
    }
    return 0;
}