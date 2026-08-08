#include <bits/stdc++.h>
using namespace std;

static mt19937_64 rng;

long long rnd(long long l, long long r) {
    if (l > r) swap(l, r);
    return uniform_int_distribution<long long>(l, r)(rng);
}

long long gen_cost(int cost_mode, long long Cmax) {
    switch (cost_mode) {
        case 0: return rnd(0, Cmax);
        case 1: return Cmax;
        case 2: return 0;
        case 3: return rnd(0, 1);
        case 4: return rnd(0, 1000);
        case 5: return rnd(0, Cmax / 2);
    }
    return rnd(0, Cmax);
}

void emit_test(int n, int shape, int cost_mode, long long Cmax) {
    cout << n << '\n';
    if (n == 1) return;
    vector<pair<int, int>> edges;
    if (shape == 0) {
        for (int v = 2; v <= n; v++) edges.push_back({(int)rnd(1, v - 1), v});
    } else if (shape == 1) {
        for (int v = 2; v <= n; v++) edges.push_back({v - 1, v});
    } else if (shape == 2) {
        for (int v = 2; v <= n; v++) edges.push_back({1, v});
    } else if (shape == 3) {
        for (int v = 2; v <= n; v++) {
            int u = (rng() & 1) ? v - 1 : (int)rnd(1, v - 1);
            edges.push_back({u, v});
        }
    } else if (shape == 4) {
        for (int v = 2; v <= n; v++) edges.push_back({v / 2, v});
    }
    for (int i = 0; i < (int)edges.size(); i++) {
        int j = (int)rnd(i, (int)edges.size() - 1);
        swap(edges[i], edges[j]);
    }
    for (auto& e : edges) {
        cout << e.first << ' ' << e.second << ' ' << gen_cost(cost_mode, Cmax) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    rng.seed(chrono::steady_clock::now().time_since_epoch().count());

    int mode = (int)rnd(0, 6);
    int n = (int)rnd(1, 8);
    long long Cmax = 1000000000LL;

    if (mode == 0) {
        cout << 1 << '\n';
        emit_test(n, 0, 0, Cmax);
    } else if (mode == 1) {
        cout << 1 << '\n';
        emit_test(n, (int)rnd(0, 4), (int)rnd(0, 5), Cmax);
    } else if (mode == 2) {
        cout << 1 << '\n';
        emit_test(n, 1, (int)rnd(0, 5), Cmax);
    } else if (mode == 3) {
        cout << 1 << '\n';
        emit_test(n, 2, (int)rnd(0, 5), Cmax);
    } else if (mode == 4) {
        cout << 1 << '\n';
        emit_test(n, 0, (int)rnd(0, 5), Cmax);
    } else if (mode == 5) {
        int t = (int)rnd(2, 10);
        int total = 0;
        vector<int> sizes;
        for (int i = 0; i < t; i++) {
            int left = t - i - 1;
            int sz = (int)rnd(1, max(1, n - total - left));
            sizes.push_back(sz);
            total += sz;
        }
        cout << t << '\n';
        for (int sz : sizes) emit_test(sz, 0, 0, Cmax);
    } else {
        cout << 1 << '\n';
        emit_test(1, 0, 0, Cmax);
    }
    return 0;
}
