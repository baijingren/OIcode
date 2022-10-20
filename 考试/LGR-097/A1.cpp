#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,k,cnt=0;
int sum;
int a[qwe];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=2;i<=n;i++){
        while(n%i==0){
            a[++cnt]=i;
            sum+=i;
            n/=i;
        }
    }
    if(sum>k){
        printf("-1");
        return 0;
    }
    printf("%d\n",cnt+k-sum);
    for(int i=1;i<=cnt;i++){
        printf("%d ",a[i]);
    }
    for(int i=sum;i<k;i++){
        printf("1 ");
    }
    return 0;
}