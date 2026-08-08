#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, V, G;
int f[qwe];
int s[qwe][qwe];
struct Node
{
    int w, v, k;
} a[qwe];
void init(){
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].k >> a[i].w >> a[i].v;
    }
    cin >> G;
    for (int i = 1; i <= G; i++)
    {
        cin >> s[i][0];
        for (int j = 1; j <= s[i][0]; j++)
        {
            cin >> s[i][j];
        }
    }
    init();
    for(int i=1;i<=n;i++){
        
    }
}