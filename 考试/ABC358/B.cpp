#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, T;
int cnt, num;
int a[qwe], s[qwe];
int main()
{
    cin >> n >> T;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cnt = 0;
    num = 1;
    for (int i = 1; i <= n; i++)
    {
        // cerr<<(i-num)*T<<' '<<a[i]-cnt<<endl;
        if ((i - num) * T > a[i] - cnt)
        {
            cout << cnt + (i - num + 1) * T << endl;
        }
        else
        {
            cnt = a[i];
            num = i;
            cout << cnt + T << endl;
        }
    }
}