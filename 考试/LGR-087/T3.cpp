#include<bits/stdc++.h>
using namespace std;
const int qwe=805;
int n;
int ans[qwe];
int a[qwe][qwe];
void dfs(int l,int id){
    if(l==1){
        
    }
    if(l-1==0){
        return;
    }
    int C=a[l][id];
    int A=a[l-1][id],B=a[l-1][id+1];
    if(A!=B){
        if(A==C){
            ans[id]=A;
        }else if(B==C){
            ans[l+id-1]=B;
        }
        dfs(l-1,id-1);
    }else{
        dfs(l-2,id+1);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    // dfs(n,1);
    for(int i=1;i<=n;i++){
        
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
}