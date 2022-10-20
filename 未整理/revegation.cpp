/*
5 3
S 1 2
D 2 3
S 4 5

1 2 一样； 2 3 不一样； 4 5 一样

1 2 3+5
6 7 3
4 5
9 10
现在一共四个联通块，对于第一个和第二个连通块是可以两种颜色
对于第三第四个连通块可以是两种颜色
换句话说，凡是有关联的连通块如果是合法的，则该连通块都可以有两种颜色

对于又要判断是否处于一个大连通块，又要通过补集（即两个集合区别颜色），因此可以开三个集合
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,x,y,fa[300005],vis[300005],fl[300005],cnt;
char p;
int find(int x){
  return x == fa[x]? x: fa[x] = find(fa[x]);
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i = 1; i <= 3*n; i++) fa[i] = i;
  for(int i = 1; i <= m; i++){
    scanf(" %c%d%d",&p,&x,&y);
    int u = find(x), v = find(y);
    int x_n = find(x + n), x_2n = find(x + 2 * n);
    int y_n = find(y + n), y_2n = find(y + 2 * n);
    if(u == v){//如果已经在一个集合了，要判断是否关系合法
        if(p == 'S'){
          if(x_n == y_2n || x_2n == y_n){
             printf("0\n"); return 0;
          }
        }
        if(p == 'D'){
          if(x_n == y_n || x_2n == y_2n){
             printf("0\n"); return 0;
          }
        }
    }else{
        fa[v] = u;//又写成x,y了 
        if(p == 'S'){
          fa[x_n] = y_n;
          fa[x_2n] = y_2n;
        }else if(p == 'D'){
          fa[y_2n] = x_n;
          fa[x_2n] = y_n;
        }
    }
  }
  //如何统计连通块个数？
  for(int i = 1; i <= n; i++){
    if(fa[i] == i) cnt++;
  }
  printf("1");
  for(int i = 1; i <= cnt; i++)
    printf("0");
  return 0;
}
//1 2 3

