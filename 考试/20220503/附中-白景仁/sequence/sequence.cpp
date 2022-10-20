#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    while(1){
        scanf("%d",&n);
        if(n==0){
            break;
        }
        if(n==1){
            printf("1\n");
            continue;
        }
        int k=0;
        while(n){
            if(n==2){
                printf("%d %d",1<<k,1<<(k+1));
            }
            else if(n==3){
                printf("%d %d %d",1<<k,1<<k,1<<(k+1))
            }
            if(n%2==0){
                for(int i=1;i<=n/2;i++){
                    printf("%d ",1<<k);
                }
                n/=2;
            }
            else{
                for(int i=1;i<=n/2+1;i++){
                    printf("%d ",1<<k);
                }
                n/=2;
            }
            k++;
        }
        printf("\n");
    }
    // printf("%d",1/2);
    return 0;
}