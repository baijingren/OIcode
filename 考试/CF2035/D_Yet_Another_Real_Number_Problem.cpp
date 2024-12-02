#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
const int mod = 1e9+7;
typedef long long ll;
int T, n;
ll a[qwe];
ll pw2(ll w){
    ll a = 2;
    ll ans = 1;
    while(w){
        if(w & 1){
            ans = ans * a % mod;
        }
        a = a * a % mod;
        w >>= 1;
    }
    return ans % mod;
}
ll pw2nomod(ll a, ll w){
    ll ans = a;
    for(int i = 1; i <= w; i++){
        ans <<= 1;
        if(ans > 1e9){
            break;
        }
    }
    return ans;
}
int lowbit(int x){
    int ans = x & (-x);
    int cnt = 0;
    while(ans){
        ans >>=1;
        cnt++;
    }
    return cnt;
}
int cnt[qwe];
int mx[qwe];
ll s[qwe];
ll p[qwe];
ll cntt[qwe];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        stack<int> S;
        // cnt = 0;
        memset(cntt,0,(n+1)*sizeof(ll));
        memset(cnt,0,(n+1)*sizeof(ll));
        // ll mx = 0;
        // ll cntt = 0;
        for(int i = 1;i <= n; i++){
            cin>>a[i];
            p[i] = a[i];
            int tmp = lowbit(a[i]);
            a[i] /= (1 << (tmp - 1));
            cntt[i] = (cntt[i - 1] + a[i]) %mod;
            
            cnt[i] = (cnt[i-1] + tmp - 1) %mod;

            // cerr << a[i] << ' ' << tmp << endl;
        }
        // mx[0] = 0;
        // a[0] = INT_MAX;
        // for(int i = 1; i <= n; i++){
        //     if(a[i] >= a[i - 1]){
        //         mx[i] = mx[i - 1];
        //         int tmp = mx[i];
        //         while(a[i] >= a[tmp]){
        //             if(tmp == mx[tmp]){
        //                 break;
        //             }
        //             tmp = mx[tmp];
        //         }
        //         mx[i] = tmp;
        //     }
        //     else if(a[i] < a[i - 1]){
        //         mx[i] = i - 1;
        //     }
        // }
        // for(int i = 1; i <= n; i++){
        //     cerr << a[i] << ' ';
        // }
        // cerr<<endl;
        a[0] = 0;
        s[0] = 0;
        S.push(1);
        // cout << s[1] << ' ';
        for(int i = 1; i <= n; i++){
            // cerr<<"b";
            // cerr << mx[i] << ' ';
            // if(mx[i] == 0){
            // if(a[mx[i]] <= a[i] * pw2(cnt[i] - cnt[mx[i]]))
            // {
            //     s[i] = (pw2(cnt[i]) * a[i] % mod + cntt[i - 1])%mod;
            //     cout << s[i] << ' ';
            // }
            // else if(a[i] >= a[i -1]){
            //     s[i] = (pw2(cnt[i]) * a[i] % mod + cntt[i - 1])%mod;
            //     cout << s[i] << ' ';
            // }
            // else{

            // }
            // }
            // else{
                // s[i] = s[mx[i]] + pw2(cnt[i] - cnt[mx[i]]) * a[i] + cntt[i - 1] - cntt[mx[i]];
                // s[i] = (s[i - 1] + p[i])%mod;
                // cout << s[i] << ' ';
            // }
            int tmp = S.top();
            while(S.size() && (pw2nomod(a[i], cnt[i] - cnt[S.top()])) >= a[S.top()]){
                // cerr<<'a';
                S.pop();
                if(S.empty()){
                    tmp = 0;
                    break;
                }
                tmp = S.top();
            }
            S.push(i);
            s[i] = (s[tmp] + pw2(cnt[i] - cnt[tmp]) * a[i] % mod + cntt[i - 1] - cntt[tmp] + mod)%mod;
            // cerr << pw2(cnt[i] - cnt[tmp]) * a[i] << ' ' << cntt[i - 1] - cntt[tmp] << endl;
            // cerr << tmp << ' ';
            cout << s[i] << ' ';
        }
        cout << endl;
    }
}