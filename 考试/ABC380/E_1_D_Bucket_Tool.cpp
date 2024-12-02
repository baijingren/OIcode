#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T, m ,n, q, t;
int c[qwe];
string s;
struct Node{
    int l, r, fa;
    int col, num;
} a[qwe];

int fnd(int x){
    if(a[x].fa == x){
        return x;
    }
    return a[x].fa = fnd(a[x].fa);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        a[i].l = i - 1;
        a[i].r = i + 1;
        a[i].fa = i;
        a[i].col = i;
        a[i].num = 1;
        c[i]++;
    }
    for(int i = 1; i <= m; i++){
        int op;
        int x, w;
        cin >> op;
        if(op == 1){
            cin >> x >> w;
            x = fnd(x);
            c[w] += a[x].num;
            c[a[x].col] -= a[x].num;
            a[x].col = w;
            if(a[fnd(a[x].l)].col == w){
                int L = fnd(a[x].l);
                // c[w] 
                a[L].num += a[x].num;
                a[L].r = a[x].r;
                a[x].fa = L;
                x = L;
                int R = a[x].r;
                if(a[R].col == a[x].col){
                    a[x].num += a[R].num;
                    a[x].r = a[R].r;
                    a[R].fa = x;
                }
            }
            else if(a[a[x].r].col == w){
                int R  = fnd(a[x].r);
                // c[w] += a[x].num;
                a[x].num += a[R].num;
                a[x].r = a[R].r;
                a[R].fa = x;
            }
            else{
                a[x].col = w;
                // c[w] ++;
            }
            // cerr << x << ' '<< w << ' ' << c[w] << endl;
        }
        else{
            cin >> x;
            // x = fnd(x);
            cout << c[x] << '\n';
        }
    }
    return 0;
}