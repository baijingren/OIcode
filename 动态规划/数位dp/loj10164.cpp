#include<bits/stdc++.h>
using namespace std;
int a,b;
int f[15][15];
int dfs(int x,int y,int num){
    if(num>b){
        return;
    }
    if(y==1){
        return 1;
    }
    // for(int i=x;i<=9;i++){
        
    //     dfs(x,y+1,num*10+i);
    // }
}
int main(){
    scanf("%d%d",&a,&b);
    dfs(1,1);
    return 0;
}