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
    int s[2];
    memset(s,0x06,sizeof(s));
    printf("%d\n%d", s[0], s[1]);
    return 0;
}