#include <iostream>
#include <vector>
using namespace std;
const int qwe = 1e5 + 5;

int n, k;
int t[qwe], p[qwe];
int dp[qwe];
vector<int> tm[qwe];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> p[i] >> t[i];
        tm[p[i]].push_back(t[i]);
    }
    dp[n + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        if (tm[i].size())
        {
            for (auto v : tm[i])
            {
                dp[i] = max(dp[i + v], dp[i]);
            }
        }
        else
        {
            dp[i] = dp[i + 1] + 1;
        }
    }
    cout << dp[1] << '\n';
    return 0;
}