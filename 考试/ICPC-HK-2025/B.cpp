#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3 + 10;
const int inf = 1e17;
struct Node {
	int v, val;
	Node(int v_ = 0, int val_ = 0) {
		v = v_;
		val = val_;
	}
};
vector <Node> G[N];
int f[N][N << 1][6];
int sum[N];
int g[N << 1][6];
int T, siz[N], n;
inline void cmin(int &x, int y) {
	x = min(x, y);
}
void dfs(int u, int fa) {
	siz[u] = 1;
	sum[u] = 0;
	int cnt = 0;
	for(int k = 0; k < 6; ++k) f[u][0][k] = 0;
//	f[u][0][2] = inf;
	for(auto tmp : G[u]) {
		int v = tmp.v, c = tmp.val;
		if(v == fa) continue;
		sum[u] += c;
		dfs(v, u);
		for(int uz = ((siz[u] + siz[v]) << 1) - 2; uz >= 0; --uz) {
			g[uz][0] = g[uz][1] = g[uz][2] = g[uz][3] = g[uz][4] = g[uz][5] = inf;
//			if(cnt >= 1) {
				for(int k = 0; k < 6; ++k) {
					if(k == 2) continue;
					cmin(g[uz][k], f[u][uz][k] + c + c + f[v][0][0]);
				}
//			}
		}
		cnt = cnt + 1;
		for(int vz = 0; vz <= (siz[v] << 1) - 2; ++vz) 
			for(int k = 0; k < 6; ++k) {
				cmin(g[vz][0], f[v][vz][k] + 2 * sum[u]);
			}	
//		if(u == 4) {
//			for(int i = 0; i <= (siz[v] << 1) - 2; ++i) {
//				cout << "i = " << i << " " << g[i][0] << ' ' << g[i][1] << ' ' << g[i][2] << ' ' << g[i][3] << ' ' << g[i][4] << '\n';
//			}
//		}
		for(int uz = (siz[u] << 1) - 2; uz >= 0; --uz) {
			for(int vz = 0; vz <= (siz[v] << 1) - 2; ++vz) {
				int nz = uz + vz;
				
//				cmin(g[nz + 2][2], f[u][uz][2] + f[v][vz][2]);
//				cmin(g[nz + 1][1], f[u][uz][2] + f[v][vz][1] + c);
//				cmin(g, f[u][uz][2])
				
//				cmin(g[nz + 1][4], f[u][uz][2] + f[v][vz][4] + c);
//				cmin(g[nz + 2][4], f[u][uz][4] + f[v][vz][2]); // ok
//				cmin(g[nz + 1][3], f[u][uz][4] + f[v][vz][1] + c);
//				cmin(g[nz + 1][3], f[u][uz][1] + f[v][vz][4] + c);
//				cmin(g[nz + 2][3], f[u][uz][3] + f[v][vz][2]); // ok
//				
//				cmin(g[nz + 1][4], f[u][uz][2] + f[v][vz][2] + c);
//				cmin(g[nz + 1][3], f[u][uz][2] + f[v][vz][2] + c);
//				cmin(g[nz + 2][2], f[u][uz][2] + f[v][vz][2]); // ok
//				cmin(g[nz + 1][1], f[u][uz][2] + f[v][vz][1] + c);
//				
//				cmin(g[nz + 1][3], f[u][uz][1] + f[v][vz][2] + c);
//				cmin(g[nz + 2][1], f[u][uz][1] + f[v][vz][2]); // ok
//				if(u == 4) cout << "v = " << v << " vz = " << vz << " opt = 2 val = " << f[v][vz][2] << '\n';
//				cmin(g[nz + 1][3], f[u][uz][1] + f[v][vz][1] + c);
				
				cmin(g[nz + 2][2], f[u][uz][2] + f[v][vz][2]);
				cmin(g[nz + 1][5], f[u][uz][2] + f[v][vz][2] + c);
				cmin(g[nz + 1][5], f[u][uz][2] + f[v][vz][1] + c);
				cmin(g[nz + 1][3], f[u][uz][2] + f[v][vz][3] + c);
				cmin(g[nz + 1][5], f[u][uz][2] + f[v][vz][5] + c);
				
				cmin(g[nz + 2][1], f[u][uz][1] + f[v][vz][2]);
				cmin(g[nz + 1][5], f[u][uz][1] + f[v][vz][2] + c);
				cmin(g[nz + 1][5], f[u][uz][1] + f[v][vz][1] + c);
				cmin(g[nz + 1][3], f[u][uz][1] + f[v][vz][3] + c);
				cmin(g[nz + 1][5], f[u][uz][1] + f[v][vz][5] + c);
				
				cmin(g[nz + 2][3], f[u][uz][3] + f[v][vz][2]);
				cmin(g[nz + 1][4], f[u][uz][3] + f[v][vz][2] + c);
				cmin(g[nz + 1][4], f[u][uz][3] + f[v][vz][1] + c);
				cmin(g[nz + 1][4], f[u][uz][3] + f[v][vz][3] + c);
				cmin(g[nz + 1][4], f[u][uz][3] + f[v][vz][5] + c);
				
				cmin(g[nz + 2][4], f[u][uz][4] + f[v][vz][2]);
				
				cmin(g[nz + 2][5], f[u][uz][5] + f[v][vz][2]);
				cmin(g[nz + 1][4], f[u][uz][5] + f[v][vz][2] + c);
				cmin(g[nz + 1][4], f[u][uz][5] + f[v][vz][1] + c);
				cmin(g[nz + 1][4], f[u][uz][5] + f[v][vz][3] + c);
				
				
			}
		}
		siz[u] += siz[v];
		sum[u] += sum[v];
		for(int uz = (siz[u] << 1) - 2; uz >= 0; --uz) {
			for(int k = 0; k < 6; ++k) f[u][uz][k] = g[uz][k];
		}
	}
}
void work() {
	dfs(1, 0);
	for(int i = 0; i <= n + n - 2; ++i) {
		int ans = inf;
		for(int k = 0; k < 6; ++k) cmin(ans, f[1][i][k]);
		cout << ans << ' ';
	}
	cout << '\n';
//	for(int k = 0; k <= 10; ++k) cout << f[5][k][2] << '\n';
	for(int i = 0; i <= n; ++i) {
		G[i].clear();
		siz[i] = 0;
		for(int j = 0; j <= (n + n - 2); ++j) {
			for(int k = 0; k < 6; ++k) {
				f[i][j][k] = g[j][k] = 0;
			}
		}
	}
}
signed main() {
	cin >> T; while(T--) {
		cin >> n;
		for(int i = 1; i < n; ++i) {
			int u, v, c;
			cin >> u >> v >> c;
			G[u].push_back(Node(v, c));
			G[v].push_back(Node(u, c));
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j <= (n << 1) - 2; ++j) {
				f[i][j][0] = f[i][j][1] = f[i][j][2] = f[i][j][3] = f[i][j][4] = f[i][j][5] = inf;
			}
		}
		work();
	}	
	return 0;
}