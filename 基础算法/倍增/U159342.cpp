#include<bits/stdc++.h>
using namespace std;
const int qwe=100005;
int n,p;
int a[qwe],s[qwe];
int main(){
    freopen("/home/bai/code/test.in", "r", stdin);
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=p;i++){
        int m;
        scanf("%d",&m);
        int l=0,r=n;
        while(l<r){
            int mid=(l+r+1)/2;
            if(s[mid]>m){
                r=mid-1;
            }
            else{
                l=mid;
            }
        }
        printf("%d\n",l);
    }
}