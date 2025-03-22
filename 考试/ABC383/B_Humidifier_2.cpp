#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e2+5;
int n, m, h, w, d;
int s[qwe][qwe];
bool vis[qwe][qwe];
pair<int, int> pos[qwe];
int cnt = 0;
int main(){
    cin >> h >> w >> d;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            char c;
            cin >> c;
            if(c == '.'){
                s[i][j] = 1;
                pos[++cnt] = make_pair(i ,j);
            }
            else if(c == '#'){
                s[i][j] = 0;
            }
            // else{
            //     j--;
            // }
        }
    }
    for(int i = 1; i <= cnt; i++){
        for(int k = 1; k <= cnt; k++){
            if(i == k){
                continue;
            }
            int tmp = 0;
            for(int j = 1; j <= cnt; j++){
                vis[pos[j].first][pos[j].second] = 0;
            }
            for(int j = 1; j <= cnt; j++){
                if(vis[pos[j].first][pos[j].second] == 1)
                    continue;
                int dis = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
                if(dis > d){
                    continue;
                }
                tmp ++ ;
                vis[pos[j].first][pos[j].second] = 1;
            }
            for(int j = 1; j <= cnt; j++){
                if(vis[pos[j].first][pos[j].second] == 1)
                    continue;
                int dis = abs(pos[k].first - pos[j].first) + abs(pos[k].second - pos[j].second);
                if(dis > d){
                    continue;
                }
                tmp ++;
                vis[pos[j].first][pos[j].second] = 1;
            }
            n = max(n, tmp);
        }
    }
    cout << n << endl;
}