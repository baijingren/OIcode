#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline int Add(int x, int y) {
	return (x + y) >= mod ? (x + y - mod) : (x + y);
}
inline int Mul(int x, int y) {
	return 1ll * x * y % mod;
}
const int N = 501;
int p[N][N];
int n, m;
int f[N][N];
int forest[N][N];
int ok[N][N];
int mx[N], mi[N];
int rem[N][N];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			cin >> p[i][j];
			rem[p[i][j]][i] = j;
		}
	}
	for(int l = 1; l <= n; ++l) ok[l][l] = 1;
	for(int l = 1; l <= n; ++l) {
		for(int k = 1; k <= m; ++k) mx[k] = mi[k] = -1;
		for(int r = l; r <= n; ++r) {
			int val = p[1][r];
			int o = 1;
			for(int k = 1; k <= m; ++k) {
				if(mx[k] == -1) mx[k] = rem[val][k];
				else mx[k] = max(mx[k], rem[val][k]);
				if(mi[k] == -1) mi[k] = rem[val][k];
				else mi[k] = min(mi[k], rem[val][k]);
				int dis = mx[k] - mi[k] + 1;
				if(dis != r - l + 1 || rem[p[1][l]][k] != mi[k]) o = 0;
			}
			ok[l][r] = o;
		}
	}
	for(int i = 1; i <= n; ++i) {
		f[i][i] = 1;
		forest[i][i] = 1;
	}
	for(int len = 2; len <= n; ++len) {
		for(int l = 1; l + len - 1 <= n; ++l) {
			int r = l + len - 1;
			if(ok[l][r]) f[l][r] = forest[l + 1][r];
			for(int k = l; k <= r; ++k) {
				int rest = (k == r ? 1 : forest[k + 1][r]);
				forest[l][r] = Add(forest[l][r], Mul(f[l][k], rest));
			}
		}
	}
	cout << f[1][n] << '\n';
	return 0;
}
