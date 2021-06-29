#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    a = 1, b = 2, c = 3;
    map<int, map<int, int>> mp;
    mp[a][b] = c;
    printf("%d", mp[a][b]);
    return 0;
}