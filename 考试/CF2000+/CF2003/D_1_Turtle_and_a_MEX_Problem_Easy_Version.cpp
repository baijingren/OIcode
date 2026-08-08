#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;

int T,n,m;

int a[qwe],l;
int u[qwe],v[qwe];

int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>l;
            u[i] = 0;
            v[i] = 1;
            for(int j = 1;j<=l; j++){
                cin>>a[j];
            }
            sort(a+1,a+l+1);
            for(int j=1;j<=l;j++){
                if(a[j] == u[i]){
                    u[i]++;
                    v[i]++; 
                }
                if(a[j] == v[i]){
                    v[i]++;
                }
            }
        }
        int tmp = 0;
        for(int i=1; i <= n; i++){
            tmp = max(v[i],tmp);
        }
        // cerr << tmp << endl;
        if(tmp>=m){
            cout << 1ll * tmp * (m + 1) << endl;
        }
        else{
            cout << 1ll * tmp * tmp + 1ll * (m + tmp) * (m - tmp + 1) /2 << endl;
        }
    }
    return 0;
}
