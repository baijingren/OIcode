#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int T;
int n, m;
int a[qwe];
int b[qwe], s[qwe], t[qwe * 2];
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
        long long cnt = 0;
        for (int i = 1; i <= 10; i++)
        {
            s[0] = n;
            memset(t, 0, 3 * n * sizeof(int));
            bool flag = false;
            for (int j = 1; j <= n; j++)
            {
                if (a[j] == i)
                {
                    flag = true;
                }
                if (a[j] > i)
                {
                    b[j] = 1;
                }
                else
                {
                    b[j] = -1;
                }
                s[j] = s[j - 1] + b[j];
            }
            if(!flag)
                continue;
            int tmp = 0;
            int sum = n;
            for(int j = 0; j < n; j++){
                if(a[j + 1] == i){
                    while(tmp <= j){
                        t[s[tmp]]++;
                        tmp++;
                    }
                }
                cnt += t[s[j + 1]];
            }
        }
        cout << 1ll * n * (n + 1) / 2 - cnt << endl;
    }
    return 0;
}