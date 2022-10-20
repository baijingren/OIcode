#include<bits/stdc++.h>//错排
using namespace std;
const int qwe=1e7+5;
const int P=20070601;
// inline void gen(int n, int seed, int *a){
// 	srand(seed);
// 	for(int i=1; i<=n; ++i) a[i]=i;
// 	random_shuffle(a+1, a+1+n);
// }
int T,n,seed,ans=1;
int a[qwe],f[qwe],inv[qwe];
void ni(){
    inv[1]=1;
    for(int i=2;i<=qwe;i++){
        inv[i]=(P-P/i)*inv[P%i]%P;
    }
    for()
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&seed);
        // gen(n,seed,a);
        f[1]=0;
        f[2]=1;
        for(int i=1;i<=n;i++){
            f[i]=f[i-1]*(i-1)+f[i-2]*(i+1);
        }
        ans*=f[n];
    }
}