#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e3+5;
int T,cnt=0;
int n,m;
int a[qwe][qwe];
int ans[100005][5];

int main(){
    scanf("%d",&T);
    while(T--){
        cnt=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%1d",&a[i][j]);
                // if(a[i][j]){
                //     cnt++;
                // }
            }
        }
        if(a[1][1]==1){
            printf("-1\n");
            continue;
        }
        // printf("%d\n",cnt);
        for(int i=n;i>=1;i--){
            for(int j=m;j>=2;j--){
                if(a[i][j]==1){
                    ans[++cnt][3]=i;
                    ans[cnt][4]=j;
                    ans[cnt][1]=i;
                    ans[cnt][2]=j-1;
                    // for(int k=1;k<=4;k++){
                    //     for
                    // }
                }
            }
        }
        for(int i=n;i>=2;i--){
            if(a[i][1]==1){
                ans[++cnt][3]=i;
                ans[cnt][4]=1;
                ans[cnt][1]=i-1;
                ans[cnt][2]=1;
            }
        }
        printf("%d\n",cnt);
        for(int i=1;i<=cnt;i++){
            for(int j=1;j<=4;j++){
                printf("%d ",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}