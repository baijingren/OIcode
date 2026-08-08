#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,T;
int a[qwe],b[qwe*2];
int main(){
    b[1]=2;
    int k=2,cnt=1,num=3,l=0;//k:个数，cnt：计算是否达到2，num：加几次，l:已经加了几次
    for(int i=2;i<=qwe-5;){
        for(int j=1;j<=k;i++,j++){
            b[i]=num;
        }
        for(int j=1;j<=k;i++,j++){
            b[i]=num+1;
        }
        k++;
        num+=2;
    }
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d",&n);
        printf("%d\n",b[n]);
        // scanf("%d",&a[i]);
        // n=max(n,a[i]);
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d",b[i]);
    // }
}
/*
1/1
2/1 2/2
3/1 3/2 3/3
*/