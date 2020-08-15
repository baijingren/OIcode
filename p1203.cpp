#include<bits/stdc++.h>
using namespace std;
const int qwe = 10005;
int n;
char s[qwe];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d ", &n);
    scanf("%s", s);
    for(int i = 1; i <= n; i++)
    { 
        s[i + n] = s[i];
    }
    for(int i = 1; i <= n; i++)
    { 
        
    }
}