#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n;
vector<int> e[qwe];
int dfn[qwe], low[qwe], cnt = 0, ans = 0;
void init()
{
    cnt = ans = 0;
    for (int i = 1; i <= n; i++)
    {
        e[i].clear();
    }
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (1)
    {
        string ch;
        int a = 0, b = 0;
        // cin.getline(ch, 1005);
        getline(cin,ch);
        if (ch[0] == '0')
            break;
        int i;
        for (i = 0; i < ch.length(); ++i)
        {
            if (ch[i] >= '0' && ch[i] <= '9')
                a = a * 10 + ch[i] - '0';
            else
                break;
        }
        i++;
        while (1)
        {
            b = 0;
            for (; i < ch.length(); ++i)
            {
                if (ch[i] >= '0' && ch[i] <= '9')
                    b = b * 10 + ch[i] - '0';
                else
                    break;
            }
            // printf("%d %d\n",a,b);
            e[a].push_back(b);
            e[b].push_back(a);
            i++;
            if (i >= ch.length())
                break;
        }
        for(int i=1;i<=n;i++){
            if(!dfn[i]){
                tarjan(i,0);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}