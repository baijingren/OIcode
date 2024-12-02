#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
#define ll long long
int n, m;
ll a[qwe], b[qwe];
ll ans = 0;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    sort(b + 1, b + m + 1);
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        if(j > m){
            break;
        }
        if (a[i] >= b[j])
        {
            ans += a[i];
            j++;
        }
    }
    if(j != m+1){
        cout<<-1;
        return 0;
    }
    cout<<ans;
    return 0;
}