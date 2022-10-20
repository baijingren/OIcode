#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int ans;
int a[qwe];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int p=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]==0 && p==0){
                p=i;
            }
        }

        if(p==0){
            printf("0\n");
            continue;
        }
        // cout<<p<<' ';
        for(int i=n;i>=1;i--){
            if(a[i]==0){
                // cout<<i<<' '<<'a'<<endl;
                printf("%d\n",i-p+2);
                break;
            }
        }
    }
    return 0;
}