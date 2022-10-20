#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int qwe=1e6+5;
int T;
ll ans=1;
int nxt[qwe],num[qwe],net[qwe];
char ch[qwe];
void work(int len){
    int j=0;
    for(int i=2;i<=len;i++){
        while(j>0&&ch[j+1]!=ch[i]){
            j=nxt[j];
        }
        if(ch[j+1]==ch[i]){
            j++;
        }
        nxt[i]=j;
        num[i]=num[j]+1;
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s",ch+1);
        memset(nxt,0,sizeof(nxt));
        ans=1;
        int k=strlen(ch+1);
        num[1]=1;
        work(k);

        for(int i=1;i<=k;i++){
            int n=i-nxt[i];
            // int j=nxt[i];
            int j=i;
            // while(j>0&&j>i/2){
            // while(j>i/2){
                // j=nxt[j];
                // j=((j-i/2)/n+1)*n;
                // if(i<2*n){
            j-=((i-i/2)/n)*n;
            while(j>i/2){
                j=nxt[j];
            }
                // }
                // else if(i>=2*n){
                    // j=((j-i/2)/n+1)*n;
                // }
            // cout<<endl<<i<<' '<<j<<endl;
                // Sleep(1);
                // getchar();
            // }
            if(j<=i/2){
                // num[i]=j;
                ans=(ans*(num[j]+1))%mod;
            }
        }
        // int ans=0;
        // cout<<endl<<T<<' ';
        // for(int i=1;i<=k;i++){
        //     cout<<num[i]<<' ';
        //     ans=(ans*(num[i]+1))%mod;
        // }
        // cout<<endl;
        printf("%d\n",ans);
    }
    return 0;
}