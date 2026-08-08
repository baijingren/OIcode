#include<bits/stdc++.h>//前缀差分
using namespace std;
const int qwe=1e6+5;
int n;
int a[qwe],b[qwe],h[qwe],s[qwe];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            h[i]=h[i-1]+a[i];
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        for(int i=1;i<=n;i++){
            s[i]=h[i];
        }
        for(int i=1;i<=n;i++){
            cout<<h[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}0