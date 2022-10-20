#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,mx;
int s[qwe],a[qwe];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
    }
    for(int i=0;i<=s[1];i++){
        for(int j=0;j<=s[1];j++){
            a[1]=i,a[2]=j;
            for(int i=3;i<=n+2;i++){
                a[i]=s[i-2]-a[i-1]-a[i-2];
                // cout<<a[i]<<' '<<i<<endl;
                if(a[i]<0){
                    a[i]=0;
                    break;
                }
            }
            if(a[n+2]!=0){
                printf("Yes\n");
                for(int i=1;i<=n+2;i++){
                    printf("%d ",a[i]);
                }
                exit(0);
            }
        }
    }
    printf("No");
    return 0;
}