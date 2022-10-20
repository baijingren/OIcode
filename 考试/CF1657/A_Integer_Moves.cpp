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
        scanf("%d%d",&n,&m);
        if(n==0 && m==0){
            printf("0\n");
            continue;
        }
        if(sqrt(n*n+m*m)-floor(sqrt(n*n+m*m))<1e-6){
            printf("1\n");
            continue;
        }
        else{
            printf("2\n");
            continue;
        }
    }
    return 0;
}