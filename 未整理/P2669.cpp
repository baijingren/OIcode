#include<bits/stdc++.h>
using namespace std;
int n, ans = 0, tot = 0;
int main()
{
    scanf("%d", &n);
    for (int i = 1;i<=n;i++){
        for (int j = 1; j <= i;j++){
            if(tot==n){
                printf("%d",ans);
                return 0;
            }
            tot++;
            ans += i;
        }
    }
}