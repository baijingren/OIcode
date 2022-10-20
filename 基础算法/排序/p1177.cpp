#include<bits/stdc++.h>
using namespace std;
const int qwe=100005;
int n,a[qwe];
void quicks(int l, int r){
    if(l>=r) return;
    int i = l, j = r;
    int mid=a[(l+r)/2];
    while(i<=j){
        while(a[i]<mid){
            i++;
        }
        while(a[j]>mid){
            j--;
        }
        if(i <= j){
            swap(a[i],a[j]);
            i++,j--;
        }
    }
    quicks(l,j),quicks(i,r);
    return;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    quicks(1,n);
    for(int i = 1;i<=n;i++){
        printf("%d ", a[i]);
    }
    return 0;
}