#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[25],dp[25][15];
int dfs(int l,int sta,int fl){
  if(l < 1) return 1;//
  if(!fl && dp[l][sta] != -1) return dp[l][sta];
  int res = 0;
  int mx = fl ? a[l] : 9;
  for(int i = sta; i <= mx; i++){
    res += dfs(l-1, i, fl && (i == mx));
  }
  if(!fl) dp[l][sta] = res;
  return res;
}
int solve(int x){
  memset(dp, -1, sizeof dp);
  int len = 0;
  while(x){
    a[++len] = x % 10;
    x /= 10;
  }
  return dfs(len,0,1);
}
int p,q;
int main(){
  while(~scanf("%d%d",&p,&q)){
    int ans = solve(q) - solve(p-1);
    printf("%d\n",ans);
  }
  return 0;
}