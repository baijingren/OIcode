#include<bits/stdc++.h>
using namespace std;
const int qwe=100005;
int n, a[qwe];
void merges(int l,int r){
    int i=l,j=r;
    int mid=(l+r)/2;
    merges(l,mid);
    merges(mid+1,r);
    
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    merges(1,n);
    for(int i = 1;i<=n;i++){
        printf("%d ", a[i]);
    }
    return 0;
}