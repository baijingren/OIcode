#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
const int qwe = 1e6 + 5;
typedef long long ll;
int T;
int n;
ll a[qwe];
unordered_set<ll> vis;
ll sol1()
{
    vis.clear();
	ll ans = 0;
	ll sum = 0;
    ll mx = a[n];
    ll mex = 0;
    a[0] = a[n];
    int nn = unique(a, a + n) - a;
    for(int i = 0; i < nn; i++){
        vis.insert(a[i]);
        while (vis.count(mex))
            mex++;
        // cerr << "\033[031m" << mex << "\033[0m" << endl;
        sum = mx + mex;
        ans += sum;
    }
    ans += sum * (n - nn);
    // cerr << "\033[033m" << ans << "\033[0m" << endl;
	return ans;
}
ll sol2(){
    vis.clear();
    ll ans = 0;
    ll sum = 0;
    ll mex = 0;
    ll mx = 0;
    int nn = unique(a + 1, a + n + 1) - a - 1;
    for(int i = 1; i <= nn; i++){
        mx = max(mx, a[i]);
        vis.insert(a[i]);
		while (vis.count(mex))
			mex++;
        // cerr << "\033[031m" << mex << "\033[0m" << endl;
        sum = mx + mex;
        ans += sum;
    }
    ans += sum * (n - nn);
    // cerr << "\033[032m" << ans << "\033[0m" << endl;
    return ans;
}
int main()
{
	cin >> T;
	while (T--) {
		cin >> n;
		vis.clear();
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		ll ans = 0;
		if (a[n] >= 2) {
            ans = sol1();
            ans = max(ans, sol2());
		} else {
			if (a[n] == 1) {
				ans = 3 * (n - 1) + 1;
			} else {
				ans = n;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
