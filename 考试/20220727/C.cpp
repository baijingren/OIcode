#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int qwe = 1e6 + 5;
int n, m;
int a[qwe];
vector<PII> e[qwe];
struct Node
{
    int a, b, c;
    explicit Node(int a = 0, int b = 0, int c = 0)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    bool operator<(const Node &x) const
    {
        return a < x.a;
    }
};
priority_queue<Node> q;
bool vis[qwe];
int dis[qwe];
void dij(int){
    memset(vis,0,sizeof(vis));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c = 0;
        string s;
        cin >> a >> b >> s;
        if (s.compare("x") == 0)
        {
            c = -1;
        }
        else
        {
            for (auto a : s)
            {
                c = c * 10 + a - '0';
            }
        }
        e[a].emplace_back(b,c);
    }
    for(int i=1;i<=n;i++){
        
    }
}