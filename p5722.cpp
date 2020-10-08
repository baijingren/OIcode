#include<bits/stdc++.h>
using namespace std;
int n,s;
int main(){
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        s += 1 + i;
    }
    printf("%d", s);
    return 0;
}