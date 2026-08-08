#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n, m, T, t, q;
string s;

// int a[qwe], b[qwe];
int a[qwe];
pair<int, int> b[qwe];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int j = 1; j <= m; j++){
        // cin >> b[j];
        cin >> b[j].first;
        b[j].second = j;
    }
    sort(b + 1, b + 1 + m, [](pair<int,int> a, pair<int, int> b){
        return a.first < b.first;
    });
    // for(int i = 1; i <= m ; i++){
    //     cerr << b[i].first << ' ';
    // }
    // cerr << endl;
    int L = 1, R = m;
    for(int i = 1; i <= n; i++){
        // t = lower_bound(b + 1, b + m + 1, a[i]) - b;
        int l = 1, r = R;
        int mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(b[mid].first >= a[i]){
                // mid = r - 1;
                r = mid;
            }
            else {
                // mid = l;
                l = mid + 1;
            }
        }
        // cerr << l << endl;
        if(a[i] > b[l].first){
            continue;
        }
        for(int j = l; j <= R; j++){
            b[j].first = i;
        }
        R = l - 1;
        // cerr << R << endl;
    }
    for(int i = 1; i <= R; i++){
        b[i].first = -1;
    }
    sort(b + 1, b + 1 + m, [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });

    for(int i = 1; i <= m; i++){
        cout << b[i].first << endl;
    }
    return 0;

}