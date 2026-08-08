#include <bits/stdc++.h>
using namespace std;
#define LOG(...)                                      \
    do {                                              \
        fprintf(stderr, "\033[31m");                 \
        fprintf(stderr, __VA_ARGS__);                 \
        fprintf(stderr, "\033[0m\n");                \
    } while (0)
const int qwe = 1e6+5;
int T;
int n, a[qwe];
int st[qwe], cnt = 0;

int sol(int a, int b){
    
}
void init(){
    for(int i = 0; i <= cnt; i++){
        hsh[i].clear();
        hsh2[i].clear();
    }
    cnt = 0;
}
int main(){
    cin >> T;
    while(T--){
        init();
        cin >> n;
        int mn = 0x3f3f3f3f;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            a[i + n] = a[i];
            mn = min(mn, a[i]);
        }
        int cntt = 0, nw = 0;
        for(int i = 1; i <= 2 * n; i++){
            if(a[i] == mn){
                nw++;
                if(nw == cntt){
                    cnt++;
                    st[cnt] = i - nw + 1;
                }
                else if(nw > cntt){
                    cnt = 1;
                    cntt = nw;
                    st[cnt] = i - nw + 1;
                }
            }
            else if(a[i] != mn && i > n){
                // cout << a[i] << ' ' << i << endl;
                // cout << st[1] << ' ' << cnt << endl;
                break;
            }
            else{
                nw = 0;
            }
        }
        if(cnt == 1){
            int mx = 0;
            for(int i = st[cnt]; i < st[cnt] + n; i++){
                cout << (mx = max(mx, a[i])) << ' ';
                // cout << a[i] << endl;
            }
            cout << endl;
            continue;
        }
        int base = 131;
        int mod = 1e9+7;
        int mod2 = 998244353;
        for(int i = 1; i <= cnt; i++){
            int mx = 0;
            for(int j = st[i]; j < min(st[i + 2], 2 * n); j++){
                int has = 0;
                mx = max(mx, a[j]);
                if(hsh[i].size() == 0){
                    has = 0;
                }
                else{
                    has = ((1ll * hsh[i][hsh[i].size() - 1] * base) % mod + mx) % mod;
                }
                hsh[i].push_back(has);
                if(hsh[i].size() == 0){
                    has = 0;
                }
                else{
                    has = ((1ll * hsh[i][hsh[i].size() - 1] * base) % mod2 + mx) % mod;
                }
                hsh2[i].push_back(has);
            }
        }
        int mnid = 1;
        for(int i = 2; i <= cnt; i++){
            mnid = sol(mnid, i);
        }
        // cerr << "mnid=" << mnid << endl;
        int mx = 0;
        for(int i = st[mnid]; i < st[mnid] + n; i++){
            cout << (mx = max(mx, a[i])) << ' ';
        }
        cout << endl;
    }
}