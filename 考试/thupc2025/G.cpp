#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int T, n;
char c[qwe];
struct A
{
    int w, m;
} a[qwe];
int cnt = 0;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> (c + 1);
        n = strlen(c + 1);
        cnt = 0;
        int l = 1, r, tmpw, tmpm, movw = 0, movm = 0;
        int answ = 0, ansm = 0;
        for (int i = 1; i <= n + 1; i++)
        {
            if (c[i] == 'X' || i == n + 1)
            {
                r = i - 1;
                if (c[l] == 'X' || c[r] == 'X')
                {
                    continue;
                }
                if (c[l] == c[r] && c[l] == 'W')
                {
                    a[++cnt].w = 0;
                    a[cnt].m = 1;
                    if (tmpm == 0)
                    {
                        movm++;
                        a[cnt].m = 2;
                    }
                }
                else if (c[l] != c[r])
                {
                    a[++cnt].w = 1;
                    a[cnt].m = 1;
                }
                else if (c[l] == c[r] && c[l] == 'M')
                {
                    a[++cnt].w = 1;
                    a[cnt].m = 0;
                    if (tmpw == 0)
                    {
                        movw++;
                        a[cnt].w = 2;
                    }
                }
                l = i + 1;
                tmpw = 0, tmpm = 0;
            }
            else if (c[i] == 'W')
            {
                tmpw++;
            }
            else if (c[i] == 'M')
            {
                tmpm++;
            }
        }
        sort(a + 1, a + cnt + 1, [](A x, A y)
             { return x.w == y.w ? x.m > y.m : x.w < y.w; });
        // for(int i = 1; i <= cnt; i++){
        //     cerr << a[i].w << ' ';
        // }
        // cerr << endl;
        // for(int i = 1; i <= cnt; i++){
        //     cerr << a[i].m << ' ';
        // }
        // cerr << endl;
        if (cnt == 1)
        {
            cout << (a[1].w ? "Water" : "Draw") << endl;
            continue;
        }
        if (movm + movw == cnt)
        {
            if (movm == movw)
            {
                cout << "Water" << endl;
            }
            else if (movm > movw)
            {
                cout << "Menji" << endl;
            }
            else
            {
                cout << "Water" << endl;
            }
            continue;
        }
        int tmp = 0, cntw = 0, cntm = 0;
        for (int i = 1; i <= cnt; i++)
        {
            if (a[i].w == 0)
            {
                cntw++;
            }
            if (a[i].m == 0)
            {
                cntm++;
            }
        }
        if (cntm * 2 > cnt)
        {
            cout << "Water" << endl;
            continue;
        }
        if (cntw * 2 > cnt)
        {
            cout << "Menji" << endl;
            continue;
        }
        // if(cntw == cntm){
        //     cout << "Draw" << endl;
        // }
        if (cntw < cntm)
        {
            cout << "Water" << endl;
        }
        else if (cntm < cntw)
        {
            cout << "Menji" << endl;
        }
        else if (cntm == cntw)
        {
            if (a[cntm + 1].w == 2)
            {
                cout << "Water" << endl;
            }
            if (a[cntw + 1].m == 2)
            {
                cout << "Menji" << endl;
            }
            else cout << "Draw" << endl;
        }
        // for(int i = 1; i <= cnt; i++){
        //     if(a[cnt - i + 1].m == 0 && a[i].w == 0){
        //         continue;
        //     }
        //     tmp = i;
        //     break;
        // }
        // cerr << tmp <<' '<< min(cntw, cntm)<< endl;
    }
    return 0;
}