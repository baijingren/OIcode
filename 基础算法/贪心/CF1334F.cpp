#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe = 1e6 + 5;
int n, m;
int a[qwe], p[qwe], b[qwe];
ll c[qwe];
int f[qwe], pos[qwe];
void change(int x, ll y)
{
    x+=1;
    while (x <= m+1)
    {
        c[x] += y;
        x += (x & -x);
    }
}
ll query(int x)
{
    x+=1;
    ll ans = 0;
    while (x)
    {
        ans += c[x];
        x -= (x & -x);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        pos[b[i]] = i;
    }
    change(1, 1e18);
    for (int i = 1; i <= n; i++)
    {
        ll u, v;
        if (pos[a[i]])
        {
            u = query(pos[a[i]] - 1);
        }
        change(0, p[i]);
        if (p[i] > 0)
        {
            change(lower_bound(b + 1, b + m + 1, a[i]) - b, -p[i]);
        }
        if(pos[a[i]]){
            v=query(pos[a[i]]);
            if(u<v){
                change(pos[a[i]],u-v);
                change(pos[a[i]]+1,v-u);
            }
        }
        
    }
    ll ans=query(m);
    if(ans>1e16){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        cout<<ans<<"\n";
    }
    return 0;
}