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
        int s=-3,ans=0;
        for(int i=1;i<=n;i++){
            scanf("%1d",a+i);
            if(!a[i]){
                if(s+1==i){
                    ans+=2;
                }
                else if(s+2==i){
                    ans+=1;
                }
                s=i;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}