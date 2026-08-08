#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n;
pair<int, int> a[qwe];
map<int, int> mp;
long long mx;
int id;
int main(){
    cin >> n; 
    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1, [](pair<int, int> x, pair<int, int> y){
        return x.first < y.first;
    });
    for(int i = n ;i >= 1; i--){
        if(a[i].first != a[i - 1].first && a[i].first != a[i + 1].first){
            cout << a[i].second;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}