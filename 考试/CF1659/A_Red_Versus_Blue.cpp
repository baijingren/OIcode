#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int r,b;
int a[qwe];

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&r,&b);
        int j=1,k=r/(b+1),l=0;
        int s=r-k*b;
        if(s==k){
            for(int i=1;i<=n;i++){
                printf("%c",j>0?'R':'B');
                j++;
                if(j>k && l<b){
                    j=0;
                    l++;
                }
            }
            printf("\n");
        }
        else{
            int mx=r%(b+1);
            for(int i=1;i<=b;i++){
                for(int j=1;j<=(i<=mx?k+1:k);j++){
                    printf("R");
                }
                printf("B");
            }
            for(int i=1;i<=k;i++){
                printf("R");
            }
            printf("\n");
        }
    }
    return 0;
}