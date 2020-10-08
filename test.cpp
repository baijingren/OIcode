#include<bits/stdc++.h>
using namespace std;
    int a, b,c,d[100],e[10000],f[10000];
bool jud(int x, int y)
{
	if (x % y == 0)
	{
		return true;
	}
	else if (e[x % y] == 1)
	{
		return true;
	}
    else if (f[x % y] == 1)
    {
        return true;
    }

    return false;
}
int main(){
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
    scanf("%d %d %d", &a,&b,&c);
    for (int i = 1; i <= c; i++)
    {
        scanf("%d",&d[i]);
    }
    sort(d + 1, d + c + 1);
    for (int i = 1; i <= c; i++)
    {
        e[d[i] - d[1]] = 1;
        f[d[i] - d[i - 1]] = 1;
    }

    if (jud(b, d[1]))
    {
        printf("1");
    }
    else
    {
        cout << 0;
    }

    return 0;
}