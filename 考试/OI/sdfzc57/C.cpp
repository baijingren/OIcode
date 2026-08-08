#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,mn=INT_MAX,cnt=0;
int a[qwe],m[qwe];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(mn==a[i]){
            m[++cnt]=i;
        }
        else if(mn>a[i]){
            cnt=0;
            m[++cnt]=i;
            mn=a[i];
        }
        a[i+n]=a[i];
    }
    for(int i=1;i<=n;i++){
        
    }
}