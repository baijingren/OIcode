#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
const int MAXN = 20;

int n, m;
vector<pair<int, int>> adj[MAXN];
ll ec[MAXN];
int usedc[MAXN];
bool vis[MAXN];
int visCnt;
ll tour[2 * MAXN];
int tourLen;
ll windowBest[2 * MAXN + 1];
ll ans[MAXN * 2];
ll totalCost;

void updateWindowBest() {
    int len = tourLen;
    for (int k = 0; k <= len; k++) windowBest[k] = 0;
    for (int s = 0; s < len; s++) {
        ll sum = 0;
        for (int e = s; e < len; e++) {
            sum += tour[e];
            windowBest[e - s + 1] = max(windowBest[e - s + 1], sum);
        }
    }
    for (int k = 0; k <= len; k++)
        ans[k] = min(ans[k], totalCost - windowBest[k]);
}

void dfs(int u) {
    if (visCnt == n && u == 1) {
        for (int i = 0; i < m; i++)
            if (usedc[i] != 2) return;
        updateWindowBest();
        return;
    }
    for (auto& pr : adj[u]) {
        int v = pr.first, e = pr.second;
        if (usedc[e] >= 2) continue;
        usedc[e]++;
        bool nv = !vis[v];
        if (nv) {
            vis[v] = true;
            visCnt++;
        }
        tour[tourLen++] = ec[e];
        dfs(v);
        tourLen--;
        if (nv) {
            vis[v] = false;
            visCnt--;
        }
        usedc[e]--;
    }
}

void solve() {
    cin >> n;
    m = n - 1;
    for (int i = 1; i <= n; i++) adj[i].clear();
    totalCost = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        ec[i] = c;
        totalCost += 2 * c;
    }
    int maxk = 2 * n - 2;
    for (int k = 0; k <= maxk; k++) ans[k] = INF;
    vis[1] = true;
    visCnt = 1;
    tourLen = 0;
    dfs(1);
    for (int k = 0; k <= maxk; k++) {
        cout << ans[k];
        if (k < maxk) cout << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
