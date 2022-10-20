// #include<bits/stdc++.h>
// using namespace std;
// int n,ans=0;
// int a[15];
// int main(){
//     scanf("%d",&n);
//     int len=0,x=n;
//     while(x){
//         a[++len]=x%10;
//         x/=10;
//     }
//     for(int i=len;i>=0;i--){
//         if(a[i]>1 && a[i+1]<=1){
//             ans+=((1<<i)-1);
//         }
//         // cout<<ans<<' ';
//         if(a[i+1]==1 && a[i+2]<=1){
//             ans+=(1<<i);
//         }
//         // cout<<ans<<' ';
//     }
//     printf("%d",ans);
// }
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int res=0;
    for(int i=1;i<1<<10;i++){
        int x=0;
        for(int j=0;j<10;j++){
            x=x*10+(i>>j & 1);
        }
        if(x<=n) res++;
    }
    printf("%d",res);
    return 0;
}