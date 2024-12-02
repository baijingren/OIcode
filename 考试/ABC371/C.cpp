#include <bits/stdc++.h>
using namespace std;
const int qwe = 15;
int n, G, H;

int edgeg[qwe][qwe], edgeh[qwe][qwe], valH[qwe][qwe];
int duh[qwe],dug[qwe];

int main()
{
    cin >> n;
    cin >> G;
    for (int i = 1; i <= G; i++)
    {
        int u, v;
        cin >> u >> v;
        dug[u]++,dug[v]++;
        edgeg[u][v] = 1;
        edgeg[v][u] = 1;
    }
    cin >> H;
    for (int i = 1; i <= H; i++)
    {
        int u, v;
        cin >> u >> v;
        duh[u]++,duh[v]++;
        edgeh[u][v] = 1;
        edgeh[v][u] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int tmp;
            cin >> tmp;
            valH[i][j] = tmp;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if
    }
}