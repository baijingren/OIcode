#include<bits/stdc++.h>
using namespace std;
const int qwe = 2e6 + 5;
int n;
int a[qwe];
// int ans[qwe];
int dfs(int x,bool ad){
    if(!ad){

    }
    return a[i] + dfs(i + 1, 0) + dfs(i + 1, 1);
}
int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n;i++){
        scanf("%d", &a[i]);
    }
    dfs(1,0);
}