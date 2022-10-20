#include<bits/stdc++.h>
using namespace std;
const int pnt = 10005;
const int lne = 1000005;
int n, m, cnt = 0;
int hd[lne], b[pnt], o[pnt];
struct EDGE
{
	int to, nxt;
} edge[lne];
void add(int u, int v)
{
	cnt++;
	edge[cnt].to = v;
	edge[cnt].nxt = hd[u];
	hd[u] = cnt;
}
queue<int> q;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		add(x, y);
		b[y]++;
		o[x]++;
	}
	for(int i = 1; i <= n; i++)
	{
		if(
