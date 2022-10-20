#include<bits/stdc++.h>
using namespace std;
int n,h;
int ans;
int main(){
    scanf("%d%d",&n,&h);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x>h){
            ans+=2;
        }
        else{
            ans+=1;
        }
    }
    printf("%d",ans);
    return 0;
}