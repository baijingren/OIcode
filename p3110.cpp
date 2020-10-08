#include<bits/stdc++.h>
using namespace std;
void add(int u, int v)
{
	cnt++;
	edge[cnt].to = v;

struct Node
{
	int n;
	bool p;
};
queue<Node> q;
int main()
{
	scanf("%d%d%d%d%d", &B, &E, &P, &N, &M);
	for(int i = 1; i <= M; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	Node x;
	x.n = 1, x.p = 0;
	q.push(x);
	x.n = 2, x.p = 1;
	q.push(x);
	vis[1] = 1;
	vis[2] = 1;
	while(!q.empty())
	{
		Node ux = q.front();
		q.pop();
		for(int i = hd[ux.x]; i; i = edge[i].nxt)
		{
			int vx = edge[i].to;
			if(
