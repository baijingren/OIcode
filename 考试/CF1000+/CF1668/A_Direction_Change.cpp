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
        scanf("%d%d",&m,&n);
        if(n==1 && m>2){
            printf("%d\n",-1);
            continue;
        }
        if(m==1 && n>2){
            printf("%d\n",-1);
            continue;
        }
        if(n>m){
            int ans=m+m-2;
            n=n-m;
            if(n%2==1){
                ans+=n*2+1;
            }
            else{
                ans+=n*2;
            }
            printf("%d\n",ans);
        }
        else if(m>n){
            int ans=n+n-2;
            m=m-n;
            if(m%2==1){
                ans+=m*2-1;
            }
            else{
                ans+=m*2;
            }
            printf("%d\n",ans);
        }
        else{
            printf("%d\n",n+m-2);
        }
    }
    return 0;
}