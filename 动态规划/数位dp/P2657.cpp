#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
int a[15];
int f[15][15];
int sol(int x){
    int ans=0;
    while(x){
        a[++ans]=x%10;
        x/=10;
    }
    return ans;
}
void init(){
    for(int i=0;i<=9;i++){
        f[1][i]=1;
    }
    for(int i=2;i<=10;i++){
        for(int j=0;j<=9;j++){
            // for(int k=0;k<=9 && abs(j-k)>=2;k++){
            for(int k=0;k<=9;k++){
                if(abs(j-k)>=2){
                    f[i][j]+=f[i-1][k];
                }
            }
            // }
        }
    }
}
int work(int x){
    int len=sol(x),ans=0;
    for(int i=1;i<len;i++){
        for(int j=1;j<=9;j++){
            ans+=f[i][j];
        }
    }
    // cout<<ans<<endl;
    for(int i=1;i<a[len];i++){
        ans+=f[len][i];
    }
    // cout<<ans<<endl;
    for(int i=len-1;i>=1;i--){
        for(int j=0;j<a[i];j++){
            if(abs(j-a[i+1])>=2){
                ans+=f[i][j];
            }
        }
        // for(int j=0;j<a[i] && abs(j-a[i+1])>=2;j++){
        // }
        if(abs(a[i+1]-a[i])<2){
            break;
        }
    }
    // cout<<ans<<endl;
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    init();
    printf("%d",work(m+1)-work(n));
}