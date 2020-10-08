#include<bits/stdc++.h>
using namespace std;
const int qwe = 1005;
int n ,m;
struct NODE
{
	int x, cnt;
};
queue<int> q, qc;
int main()
{
	scanf("%d %d", &n, &m);
	q.push(n);
	int ans = 0;
	while(!q.empty())
	{
		int u = q.front();
		int uc = qc.front();
		q.pop(), qc.pop();
		int v, vc;
		v = yfwe(u);
		vc = uc + 1;
		if(v)
		{
			q.push(v);
			qc.push(vc);
		}
		v = dsls(u);
		if(v)
		{
			q.push(v);
