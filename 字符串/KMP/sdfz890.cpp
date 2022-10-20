#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
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
        scanf(" %s",b+1);
        m=strlen(b+1);
        if(b[1]=='.' && m==1){
            break;
        }
        work();
        ans=m-nxt[m];
        if(m%(m-nxt[m])==0){
            ans=m/ans;
        }
        else{
            ans=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}