#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T, n, m, r, c;
int a[qwe];
bool vis[qwe];
int bits(int a){
    int cnt = 0;
    while(a){
        a >>= 1;
        cnt++;
    }
    return cnt - 1;
}
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        memset(vis,0,sizeof(vis));
        if(n % 2 == 0 && (n != (1 << bits(n)))){
            a[n] = (1 << (bits(n))) - 1;
            cout << (1 << (bits(n) + 1)) - 1 << endl;
            a[n - 1] = n - 1;
            a[n - 2] = n;
            vis[(1 << bits(n)) - 1] = 1;
            vis[n] = vis[n-1] = 1;
            for(int i = 1, j = 1; i <= n - 3 && j <= n; i++,j++){
                if(vis[j]){
                    j++;
                }
                a[i] = j;
            }
        }
        else if(n % 2 == 1){
            cout << n << endl;
            a[n] = n;
            a[n-1] = n-1;
            a[n-2] = (1 << bits(n)) - 1;
            a[n-3] = 1;
            vis[n] = vis[n-1] =vis[(1 << bits(n)) - 1] = vis[1] = 1;
            for(int i = 1, j = 1; i <= n - 4 && j <= n; i++,j++){
                if(vis[j]){
                    j++;
                }
                a[i] = j;
            }
        }
        else{
            cout << (1 << (bits(n) + 1)) - 1 << endl;
            a[n] = n;
            a[n - 1] = n - 1;
            a[n-2] = n-2;
            a[n-3] = 3;
            a[n-4] = 1;
            vis[1] = vis[3] = vis[n-2] = vis[n-1] = vis[n] = 1;
            for(int i = 1, j = 1; i <= n - 5 && j <= n; i++,j++){
                if(vis[j]){
                    j++;
                }
                a[i] = j;
            }
        }
        for(int i = 1; i <= n; i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}