#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
const double PI = 3.14159265358979323;
int n, sr, sd, tr, td;
struct building{
    int r;
    int ds, dt;
} b[qwe];
struct SegmentTree{
    int t[qwe];
    bool lzy[qwe];
    void pushup(int rt){
        t[rt] = min(t[rt << 1], t[rt << 1 | 1]);
    }
    void pushdown(int rt){
        t[rt << 1] = t[rt];
        t[rt << 1 | 1] = t[rt];
        lzy[rt << 1] = 1;
        lzy[rt << 1 | 1] = 1;
        lzy[rt] = 0;
    }
    void build(int rt, int l, int r){
        if(l == r){
            t[rt] = 0x3f3f3f3f;
            return;
        }
        int mid = (l + r) >> 1;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
        pushup(rt);
    }
    void update(int rt, int l, int r, int L, int R, int w){
        if(l <= L && R <= r){
            t[rt] = w;
            lzy[rt] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        if(lzy[rt] == 1){
            pushdown(rt);
        }
        update(rt << 1, l, mid + 1, L, R, w);
        update(rt << 1 | 1, mid + 1, r, L, R, w);
        pushup(rt);
    }
    int query(int rt, int l, int r, int t){
        if(l == r && l == t){
            return t[rt];
        }
        int mid = (l + r) >> 1;
        if(t <= mid){
            return query(rt << 1, l, mid, t);
        }
        else{
            return query(rt << 1 | 1, mid + 1, r, t);
        }
    }
} t;
int main(){
    cin >> n >> sr >> sd >> tr >> td;
    for(int i = 1; i <= n; i++){
        cin >> b[i].r >> b[i].ds >> b[i].dt;
    }
    sort(b + 1, b + n +1, [](building x, building y){
        return x.r > y.r;
    });
    t.build(1,1,n);
    for(int i = 1; i <= n; i++){
        if(b[i].ds > b[i].dt){
            t.update(1, 1, n, b[i].ds, 2 * PI, b[i].r);
        }
        t.update(1, 1, n, b[i].ds, b[i].dt, b[i].r);
        
    }
}