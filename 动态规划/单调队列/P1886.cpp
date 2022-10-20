#include<bits/stdc++.h>
using namespace std;
const int qwe=10005;
int n,k;
int a[qwe],mx[qwe],mn[qwe];
deque<int> qmax,qmin;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        while(qmax.size()&&a[i]>=a[qmax.back()]){
            qmax.pop_back();
        }
        qmax.push_back(i);
        while (qmin.size()&&a[i]<a[qmin.back()])
        {
            qmin.pop_back();
        }
        qmin.push_back(i);
        if(qmax.front()<(i-k+1)){
            qmax.pop_front();
        }
        if(qmin.front()<(i-k+1)){
            qmin.pop_front();
        }
        if(i>=k){
            mx[i]=a[qmax.front()];
            mn[i]=a[qmin.front()];
        }
    }
    for(int i=k;i<=n;i++){
        printf("%d ",mn[i]);
    }
    printf("\n");
    for(int i=k;i<=n;i++){
        printf("%d ",mx[i]);
    }
    printf("\n");
    return 0;
}