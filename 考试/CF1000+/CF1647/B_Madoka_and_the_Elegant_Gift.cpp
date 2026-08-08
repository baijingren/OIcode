#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e3+5;
int T;
int n,m;
int a[qwe][qwe];

int main(){
    scanf("%d",&T);
    while(T--){
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%1d",&a[i][j]);
            }
        }
        int flag=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int ans=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
                if(ans==3){
                    flag=1;
                }
            }
        }
        if(flag){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}