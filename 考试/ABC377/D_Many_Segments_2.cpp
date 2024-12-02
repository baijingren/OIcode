#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
#define MP make_pair
const int qwe = 2e5 +5;
int n, m;
PII a[qwe];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    a[n + 1] = MP(0, m+1);
    sort(a + 1, a + n + 2, [](PII a, PII b){
        return a.second < b.second;
    });
    int l = 0, r = a[1].second, rec = 1;;
    ll ans = 1ll * (r - 1 - l)  * (r - 1 - l - 1) / 2 + (r - 1 - l);
    // cerr<< l << ' ' << r << ' ' << ans << endl;
    // cerr << ans <<endl;
    for(int i = 2; i <= n + 1; i ++){
        if(l > a[rec].first){
            int tmp = a[i].second - r;
            ans += 1ll * tmp * (tmp - 1) / 2;
            ans += 1ll * tmp * (r - l);
            r = a[i].second;
            rec = i;
        }
        else{
            l = a[rec].first;
            r = a[i].second;
            int tmp = (r - l - 1);
            int minu = a[rec].second - a[rec].first - 1;
            ans += 1ll * tmp * (tmp - 1) / 2 + tmp;
            ans -= 1ll * (minu - 1) * minu / 2 + minu;
            rec = i;
        }
        // cerr<< l << ' ' << r << ' ' << ans << endl;
    }
    cout << ans;
    return 0;
}