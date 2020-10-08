#include<bits/stdc++.h>
using namespace std;
const int qwe =100005;
int n, ans;
int vis[qwe];
queue<int> q ,qt;
int main()
{
	scanf("%d", &n);
	for(int i = 1;i <= n; i++)
	{
		int a ,m;
		scanf("%d%d", &a, &m);
		for(int j = 1; j <= m; j++)
		{
			int x;
			scanf("%d", &x);
			//cout << endl << "qwe " << x << ' ';
			if(!vis[x])
			{
			//	cout << "rty";
				ans++;
			}
			//cout << endl;
			vis[x]++;
			qt.push(a);
			q.push(x);
		}
		while(a - qt.front() >= 86400)
		{
			int x = q.front();
			vis[x]--;
			//cout << "asd" << endl;
			if(vis[x] == 0)
			{
				ans--;
			}
			q.pop(), qt.pop();
		}
		printf("%d\n", ans);
	}
	return 0;
}
