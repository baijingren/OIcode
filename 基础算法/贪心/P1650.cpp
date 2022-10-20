#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,ans;
int a[qwe],b[qwe];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int j,k,l,r;
    j=k=1,l=r=n;
    for(int i=1;i<=n;i++){
        if(a[l]>b[r]){
            ans++;
            l--,r--;
        }
        else if(a[l]<b[r]){
            ans--;
            j++,r--;
        }
        else if(a[j]>b[k]){
            ans++;
            j++,k++;
        }
        else{
            if(a[j]<b[r])
            ans--;
            j++,r--;
        }
    }   
    printf("%d",ans*200);
    return 0;
}