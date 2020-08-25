#include <bits/stdc++.h>
using namespace std;
struct CPU
{
    int id, fst, gttme, rntme;
};
CPU jc[15005];
struct cmp
{
    bool operator()(const CPU &x, const CPU &y)
    {
        return x.fst < y.fst || x.fst == y.fst && x.id > y.id;
    }
};
int n = 1, lst, cnt = 1, ing = 0, tme;
priority_queue<CPU, vector<CPU>, cmp> q;
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    while (scanf("%d", &jc[n].id) != EOF)
    {
        scanf("%d%d%d", &jc[n].gttme, &jc[n].rntme, &jc[n].fst);
        n++;
    }
    lst = n;
    jc[n + 1].gttme = 99999999;
    while (lst > 1)
    {
        if (!ing)
        {
            q.push(jc[cnt]);
            tme = jc[cnt].gttme;
            ing++;
            cnt++;
        }
        CPU sve = q.top();
        q.pop();
        ing--;
        int edtme = tme;
        tme = min(jc[cnt].gttme, edtme + sve.rntme);
        if (tme == edtme + sve.rntme)
        {
            printf("%d %d\n", sve.id, tme);
            lst--;
        }
        else
        {
            sve.rntme -= tme - edtme;
            q.push(sve);
            ing++;
        }
        if (tme==jc[cnt].gttme)
        {
            q.push(jc[cnt]),ing++,cnt++;
        }
    }
    return 0;
}