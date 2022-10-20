#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int a[qwe],v[qwe];

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        v[a[i]]++;
    }
    // sort(a+1,a+n+1,[](int a,int b){
    //     return a<b;
    // });
    int i=0;
    while(v[i]!=0){
        i++;
    }
    printf("%d",i);
    return 0;
}