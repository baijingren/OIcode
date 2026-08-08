#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe = 1e2 +5;
int n, m;
int x, y;
ll ans = 0;
int mv[2][9] = {
    {2, 1, -1, -2, -2, -1, 1, 2, 0},
    {1, 2, 2, 1, -1, -2, -2, -1, 0}
};
map<pair<int,int>, bool> mp;

int main(){
    cin >> n >> m;
    ans = 1ll * n * n;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        for(int i = 0; i <= 8; i ++){
            pair<int,int> tmp = make_pair(x + mv[0][i], y + mv[1][i]);
            if(x + mv[0][i] > n || x + mv[0][i] <= 0 || y + mv[1][i] > n || y + mv[1][i] <= 0){
                continue;
            }
            if(mp[tmp] != 1){
                mp[tmp] = 1;
                ans--;
            }
        }
    }
    cout << ans <<endl;
    return 0;
}