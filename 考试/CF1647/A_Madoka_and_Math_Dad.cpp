#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int a[qwe];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n%3==0){
            int ans=0;
            for(int i=2;ans<n;i++,ans+=i%2==0?2:1){
                // ans+=i%2==0?2:1;
                printf("%d",i%2==0?2:1);
            }
            printf("\n");
            continue;
            // printf("%d",ans);
        }
        else if(n%3==2){
            int ans=2;
            printf("%d",ans);
            for(int i=1;ans<n;i++,ans+=i%2==0?2:1){
                printf("%d",i%2==0?2:1);
            }
            printf("\n");
            continue;
        }
        else{
            int ans=1;
            printf("%d",ans);
            for(int i=2;ans<n;i++,ans+=i%2==0?2:1){
                printf("%d",i%2==0?2:1);
            }
            printf("\n");
            continue;
        }
    }
    return 0;
}