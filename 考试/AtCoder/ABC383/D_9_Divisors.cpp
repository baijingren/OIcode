#include<bits/stdc++.h>
using namespace std;
const int qwe = 2e6+5;
#define ll long long
ll n;
int m;
int r[qwe], v[qwe], cnt = 0;
int vis[qwe];
void shai(int n){
    for(int i = 2; i <= n; i++){
        if(!v[i]){
            r[++cnt] = i;
        }
        for(int j = 1; j <= cnt; j++){
            if(i * r[j] > n){
                break;
            }
            v[i * r[j]] = 1;
            if(i % r[j] == 0){
                break;
            }
        }
    }
}
int main(){
    cin >> n;
    // p1 ^2  * p2 ^2
    // p ^8
    int ans = 0;
    m = (int)sqrt(n);
    shai(m);
    // cerr << cnt << ' ' << m << endl;
    // for(int i = 1; i <= cnt; i++){
    //     // cerr <<  r[i] << endl;
    //     if(r[i] > (m / 2)){
    //         cnt = i;
    //         break;
    //     }
    // }
    // cerr << cnt << endl;
    for(int i = 1; i <= cnt; i++){
        for(int j = i + 1; j <= cnt; j++){
            if(r[j] * r[i] > m){
                cnt = j;
                break;
            }
            // if(r[i] * r[j] <= m){
                ans++;
                // cerr << 1ll * (r[i] * r[j]) * (r[i] * r[j]) << ' ' << r[i] << ' ' << r[j] << endl;
            // }
        }
    }
    for(int i = 1; i <= cnt; i++){
        if((long long)pow(r[i] * 1ll, 8ll) > n){
            break;
        }
        ans++;
    }
    cout << ans << endl;
}