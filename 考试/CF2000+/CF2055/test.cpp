#include <bits/stdc++.h>
using namespace std;
int a[2000005], b[2000005];
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        int flag = 0, cha1 = 0, cha2 = INT_MAX;
        for (int j = 1; j <= n; j++)
        {
            cin >> a[j];
        }
        // long long mina=100000000000;
        for (int j = 1; j <= n; j++)
        {
            cin >> b[j];
            if (a[j] - b[j] >= 0)
            {
                // if(mina>=(a[j]-b[j]))
                // {
                // 	mina=a[j]-b[j];
                // 	cha2=mina;
                // }
                cha2 = min(cha2, a[j] - b[j]);
            }
        }
        for (int j = 1; j <= n; j++)
        {
            if (a[j] - b[j] < 0)
            {
                flag++;
                cha1 += b[j] - a[j];
            }
        }
        // cout<<"flag="<<flag<<" "<<"cha1="<<cha1<<"cha2="<<cha2;
        if (flag == 0)
            cout << "YES" << endl;
        if (flag == 1)
        {
            if (cha2 < cha1)
                cout << "NO" << endl;
            else if (cha2 >= cha1)
                cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}