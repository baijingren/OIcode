#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int s[qwe];
bitset<qwe> a,b;

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        memset(s,0,sizeof(s));
        // memset(a,0,sizeof(a));
        a.none();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            int x;
            scanf("%1d",&x);
            if(x==1){
                a[i]=1;
            }
            else{
                a[i]=0;
            }
        }
        for(int i=1;i<=n;i++){
            b[i]=1;
        }
        // for(int i=1;i<=m;i++){
        //     a^=b;
        // }
        if(m%2==1){
            a^=b;
        }
        int j=1,i=1;
        // for(int i=1;i<=m;i++){
            while(i<=m){
                // j++;
                if(a[j]!=1){
                    a[j]=a[j]^1;
                    s[j]++;
                    i++;
                }
                j++;
                // cout<<'a';
                while(j==n){
                    if(i>m){
                        break;
                    }
                    a[j]=a[j]^1;
                    i++;
                    s[j]++;
                }
                // continue;
            }
            for(int i=1;i<=n;i++){
                printf("%d",a[i]==1?1:0);
            }
            printf("\n");
            for(int i=1;i<=n;i++){
                printf("%d ",s[i]);
            }
            printf("\n");
        // }
    }
    return 0;
}