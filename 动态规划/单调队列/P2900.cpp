#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n;
// int w[qwe],l[qwe];
#define PII pair<int,int>
#define W first
#define L second
#define MP make_pair
PII a[qwe];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].W,&a[i].L);
    }
    sort(a+1,a+n+1,[](PII x,PII y){
        return x.L>y.L;
    });
    for(int i=1;i<=n;i++){
        if()
    }
}