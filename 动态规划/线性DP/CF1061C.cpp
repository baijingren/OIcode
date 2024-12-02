#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
const int md = 1e9+7;

int n;
int a[qwe];
int f[qwe];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        f[1]=n;
        f[0]=1;
    }
    
    cout<<f[n]<<endl;
    return 0;
}