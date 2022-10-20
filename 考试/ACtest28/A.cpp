#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int cnt=0,ans=0;
char s[qwe],c[4]={0,'Q','A','Q'};
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    int j=1;
    // for(int i=1;i<=n;i++){
    //     if(c[j]==s[i]){
    //         cnt++;
    //         j++;
    //     }
    //     else{
    //         cnt=0;
    //     }
    //     if(cnt==3){
    //         ans++;
    //         cnt=0;
    //     }
    // }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(s[i]==c[1] && s[j]==c[2] && s[k]==c[3]){
                    ans++;
                }
            }
        }
    }
    printf("%d",ans);
}