#include<bits/stdc++.h>
using namespace std;
const int qwe=10005;
int n,q,cnt;
int v[qwe],r[qwe];
void shai(int x){
    cnt=0;
    for(int i=2;i<=x;i++){
        if(v[i]==0){
            v[i]=i;
            r[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++){
            if(r[j]>v[i]||r[j]>x/i) break;
            v[r[j]*i]=r[j];
            // cout<<r[j]*i<<endl;
        }
    }
}
int main(){
    scanf("%d%d",&n,&q);
    // scanf("%d",&n);
    // for(int i=1;i<=n;i++){
    //     v[i]=i;
    // }
    shai(n);
    // for(int i=1;i<=cnt;i++){
    //     cout<<r[i]<<endl;
    // }
    for(int i=1;i<=q;i++){
        int a;
        scanf("%d",&a);
        printf("%d\n",r[a]);
    }
    return 0;
}