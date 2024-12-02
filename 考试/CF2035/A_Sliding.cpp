#include<bits/stdc++.h>
using namespace std;
int T, n, m, r, c;
int main(){
    cin >> T;
    while(T--){
        cin>>n>>m>>r>>c;
        long long ans = 1ll * (n - r) * m + 1ll * (m - 1) * (n - r) + (m - c);
        cout << ans << endl;
    }
    return 0;
}