#include<bits/stdc++.h>
using namespace std;
const int qwe=1e3+5;
char a[qwe],b[qwe];
int n,m,ans;
int nxt[qwe],f[qwe];
void work(){
    nxt[1]=0;
    for(int i=2,j=0;i<=m;i++){
        while(j>0 && b[i]!=b[j+1]){
            j=nxt[j];
        }
        if(b[i]==b[j+1]){
            j++;
        }
        nxt[i]=j;
    }
}
int main(){
    while(1){
        ans=0;
        memset(nxt,0,sizeof(nxt));
        memset(f,0,sizeof(f));
        scanf("%s",a+1);
        n=strlen(a+1);
        if(a[1]=='#' && n==1){
            break;
        }
        scanf(" %s",b+1);
        m=strlen(b+1);
        work();
        for(int i=1,j=0;i<=n;i++){
            while(j>0 && (j==m || a[i]!=b[j+1])){
                j=nxt[j];
            }
            if(a[i]==b[j+1]){
                j++;
            }
            // if(j==m){
                f[i]=j;
            // }
        }
        for(int i=1;i<=n;i++){
            if(f[i]==m){
                ans++;
                i+=m-1;
            }
        }
        printf("%d\n",ans);
    }
}