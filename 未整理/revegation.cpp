/*
5 3
S 1 2
D 2 3
S 4 5

1 2 һ���� 2 3 ��һ���� 4 5 һ��

1 2 3+5
6 7 3
4 5
9 10
����һ���ĸ���ͨ�飬���ڵ�һ���͵ڶ�����ͨ���ǿ���������ɫ
���ڵ������ĸ���ͨ�������������ɫ
���仰˵�������й�������ͨ������ǺϷ��ģ������ͨ�鶼������������ɫ

������Ҫ�ж��Ƿ���һ������ͨ�飬��Ҫͨ������������������������ɫ������˿��Կ���������
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
    if(u == v){//����Ѿ���һ�������ˣ�Ҫ�ж��Ƿ��ϵ�Ϸ�
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
        fa[v] = u;//��д��x,y�� 
        if(p == 'S'){
          fa[x_n] = y_n;
          fa[x_2n] = y_2n;
        }else if(p == 'D'){
          fa[y_2n] = x_n;
          fa[x_2n] = y_n;
        }
    }
  }
  //���ͳ����ͨ�������
  for(int i = 1; i <= n; i++){
    if(fa[i] == i) cnt++;
  }
  printf("1");
  for(int i = 1; i <= cnt; i++)
    printf("0");
  return 0;
}
//1 2 3

