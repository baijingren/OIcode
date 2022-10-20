#include<bits/stdc++.h>
using namespace std;
const int qwe=1e7+5;
int n,mxn,cnt=0,num=0,tot=0,tott=0;
long long a,s[qwe],w[qwe],vis[qwe],o[qwe];
struct Node{
    int num,ji,ou,l;
};
bool chk(long long x){
    if(x<2) return 0;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a);
        if(a%2==1){
            if(a==1){
                num++;
            }
            else{
                s[++tot]=a;
            }
        }
        else{
            o[++tott]=a;
        }
        // mxn=max(mxn,a[i]);
        // w[i]=w[i-1]+a[i];
    }
    sort(s+1,s+tot+1);
    sort(o+1,o+tott+1);
    Node max;
    if(num<=1){
        max.l=2;
        for(int i=tot;i>=1;i--){
            for(int j=tott;j>=1;j--){
                if(s[i]+o[j]>max.num && chk(s[i]+o[j])){
                    max.num=s[i]+o[j];
                    max.ji=s[i];
                    max.ou=o[j];
                }
            }
        }
        if(max.ji>max.ou){
            // swap(max.ji,max.ou);
            long long c=max.ji;
            max.ji=max.ou;
            max.ou=c;
        }
        printf("%d\n%lld %lld",max.l,max.ji,max.ou);
    }
    else{
        max.l=num+1;
        for(int j=tott;j>=1;j--){
            if(o[j]+1>max.num && chk(o[j]+1)){
                max.num=o[j]+1;
                max.ji=1;
                max.ou=o[j];
                break;
            }
        }
        printf("%d\n",max.l);
        for(int i=1;i<=num;i++){
            printf("1 ");
        }
        printf("%d",max.ou);
    }
}
//不能同时存在2个及以上的偶数
//不能同时存在2个及以上的大于一的奇数