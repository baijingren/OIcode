#include<bits/stdc++.h>
using namespace std;
int n,m,cnta,cntb;
int a[10],b[5];
int main(){
    scanf("%d%d%d%d",&a[1],&a[2],&a[4],&a[3]);
    scanf("%d%d%d%d",&b[1],&b[2],&b[4],&b[3]);
    for(int i=1;i<=4;i++){
        if(a[i]==0){
            cnta++;
        }
    }
    if(cnta==0){
        for(int i=1;i<=4;i++){
            if(a[i]!=b[i]){
                printf("No\n");
                return 0;
            }
        }
        printf("Yes");
        return 0;
    }
    if(cnta==2||cnta==3){
        printf("Yes\n");
        return 0;
    }
    for(int i=1;i<4;i++){
        if(!a[i]){
            swap(a[i],a[i+1]);
        }
        if(!b[i]){
            swap(b[i],b[i+1]);
        }
    }
    for(int i=1;i<=3;i++){
        a[i+3]=a[i];
    }
    for(int i=0;i<3;i++){
        cntb=0;
        for(int j=1;j<=3;j++){
            if(a[j+i]==b[j]){
                cntb++;
            }
        }
        if(cntb==3){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No");
    return 0;
}