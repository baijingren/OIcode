#include<bits/stdc++.h>
using namespace std;
int a,b,p;
int main(){
    int  mnp=INT_MAX;
    for(int i=1;i<=4;i++){
        scanf("%d",&p);
        mnp=min(mnp,p);
    }
    // cout<<mnp<<endl;
    scanf("%d%d",&a,&b);
    if(a>b) swap(a,b);
    if(mnp>b){
        printf("%d",b-a+1);
        return 0;
    }
    int ans=mnp-a;
    if(ans<=0){
        printf("0");
        return 0;
    }
    printf("%d",ans);
}