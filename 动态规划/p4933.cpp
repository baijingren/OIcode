#include<bits/stdc++.h>
using namespace std;
const int qw = 1005, we = 20005;
int n;
int a[we];
int f[qw][we];
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        f[0][i] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            f[j][i] = 