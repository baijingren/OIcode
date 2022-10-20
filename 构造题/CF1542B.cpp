#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int T;
int n,a,b;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&a,&b);
        if(a==1){
            if((n-1)%b==0){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else{
            long long f=1;
            int flag=0;
            while(f<=n){
                if((f%b)==(n%b)){
                    flag=1;
                    break;
                }
                f*=a;
            }
            if(flag==1){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
    return 0;
}