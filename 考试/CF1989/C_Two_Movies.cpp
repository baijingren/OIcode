#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int T;

int n;
int a[qwe], b[qwe];

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }

        int cnt_pos = 0, cnt_neg = 0;
        int A = 0, B = 0;
        for (int i = 1; i <= n; i++) 
        {
            if (a[i] == b[i] && a[i] == 1)
            {
                cnt_pos += a[i];
            }
            else if (a[i] == b[i])
            {
                cnt_neg += a[i];
            }
            else if (a[i] > b[i])
            {
                A += a[i];
            }
            else
            {
                B += b[i];
            }
        }

        int cnt = (cnt_neg + cnt_pos) / 2;
        if ((-cnt_neg) % 2 == 1)
        {
            cnt_neg = -1;
        }
        else
        {
            cnt_neg = 0;
        }
        if (cnt_pos % 2 == 1)
        {
            cnt_pos = 1;
        }
        else
        {
            cnt_pos = 0;
        }
        // A += cnt, B += cnt;
        int ans = max({min(A + cnt_neg + cnt_pos, B),
                       min(A + cnt_neg, B + cnt_pos),
                       min(A + cnt_pos, B + cnt_neg),
                       min(A, B + cnt_neg + cnt_pos)});

        cout << ans + cnt << endl;
    }
    return 0;
}