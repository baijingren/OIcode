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
        int mx=0,ms=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]>=mx){
                ms=mx;
                mx=a[i];
                // cout<<mx<<' ';
            }
            else if(a[i]>=ms){
                ms=a[i];
            }
        }
        if(mx-ms>=2){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}