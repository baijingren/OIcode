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
        if(n>0){
            printf("%d\n",n+m*2+1);
        }
        else{
        //     // printf("%d\n",n+n*2+1);
            printf("1\n");
        }
    }
    return 0;
}