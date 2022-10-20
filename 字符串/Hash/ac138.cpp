#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
// typedef long long ll;
const int qwe = 1e6 + 5;
const int P = 131;
int n;
ull s[qwe];
ull po[qwe];
char dna[qwe];
int main()
{
    scanf("%s", dna);
    int m = strlen(dna);
    for (int i = 1; i <= m; i++)
    {
        s[i] = (s[i - 1] * P + (dna[i] - 'a' + 1) + P) % P;
        po[i] = po[i - 1] * P;
    }
    scanf("%d", &n);
    int la, lb, ra, rb;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &la, &ra, &lb, &rb);
        ull stra=(s[ra]-s[la-1])//err:s[ra]-s[la+1]
    }
}