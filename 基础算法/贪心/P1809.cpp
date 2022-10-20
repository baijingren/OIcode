#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,ans=0;
int a[qwe],f[qwe];
// void sloa(){
//     for(int i=2;i<=n;i++){
//         ans+=(a[i]+a[1]);
//     }
//     ans-=a[1];
//     return;
// }
// void slob(){
//     for(int i=4;i<=n;i+=2){
//         ans+=a[1]+a[2]*2+a[i];
//     }
//     return;
// }
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    f[1]=a[1];
    f[2]=a[2];
    f[3]=a[3]+a[2]+a[1];
    for(int i=4;i<=n;i++){
        f[i]=min(f[i-1]+a[i]+a[1],f[i-2]+a[i]+a[2]*2+a[1]);
    }
    // if(a[n]+a[n]>=a[2]*2){
    //     sloa();
    // }
    // else{
    //     slob();
    // }
    printf("%d",f[n]);
    return 0;
}