#include<bits/stdc++.h>
using namespace std;
const int qwe=10005;
int Q,foy,y;
int date[]={-4713,1,1};
int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    freopen("/home/bai/code/test.in", "r", stdin);
    freopen("/home/bai/code/test.out", "w", stdout);
    scanf("%d", &Q);
    for(int i=1;i<=Q;i++){
        unsigned int a;
        scanf("%d",&a);
        // cout<<a<<endl;
        foy=a/1461;
        a%=1461;
        date[0]+=4*foy;
        y=a/365;
        if(y == 4&&a%365==0){
            y--;a-=3*365+1;
        }else{
            a%=365;
        }
        date[0]+=y;
        for(int i=1;i<=12;i++){
            if(a>=mon[i]){
                // cout<<1<<' '<<a<<endl;
                if(date[0]%4==0||(date[0]<0&&(date[0]+1)%4==0)){
                    if(i==2){
                        a-=(mon[i]+1);date[1]++;continue;
                    }
                }
                a-=mon[i];
                date[1]++;
            }
        }
        date[2]+=a;
        // cout<<foy<<' '<<date[0]<<' '<<a<<endl;
        printf("%d %d %d",date[0],date[1],date[2]);
        if(date[0]<0){
            printf(" BC");
        }
        printf("\n");
    }
    return 0;
}
