#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,T,k=0;
int tsx,tsy,tdx,tdy;
int a[qwe],b[qwe],d[qwe],f[qwe];
int p[qwe],t[qwe],c[qwe];
void init(){
    // n=0;
    for(int i=1;i<=n;i++){
        int x=1;
        while(d[i]){
            // n++;
            k++;
            // c[n]=c[i]*x;
            t[k]=a[i]*x;
            c[k]=b[i]*x;
            d[i]-=x;
            x*=2;
            if(d[i]<x){
                k++;
                t[k]=a[i]*d[i];
                c[k]=b[i]*d[i];
                break;
            }
        }
    }
}
int main(){
    scanf("%d:%d %d:%d",&tsx,&tsy,&tdx,&tdy);
    T=(tdx*60+tdy)-(tsx*60+tsy);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i],&b[i],&d[i]);
        if(d[i]==0){
            d[i]=9999999;
        }
    }
    init();
    for(int i=1;i<=k;i++){
        for(int j=T;j>=t[i];j--){
            // cout<<t[i]<<' ' <<c[i];
            f[j]=max(f[j],f[j-t[i]]+c[i]);
        }
    }
    printf("%d",f[T]);
    return 0;
}