#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int v[1000];
int main(){
    // scanf("%d",&T);
    // while(T--){
    //     scanf("%d",&n);
        
    // }
    for(int i=1;i<=200;i++){
        int a=i,b=i*2,c=i*3;
        if(!v[a] && !v[b] && !v[c]){
            printf("%d %d %d ",a,b,c);
            v[a]=v[b]=v[c]=1;
            if(a%3==0){
                printf("a");
            }
        }
    }
}