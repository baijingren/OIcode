#include<bits/stdc++.h>
using namespace std;
struct stu
{
    int chi, mat, eng, all;
    char nam[10];
};
stu st[1005];
int n;
bool cmp(stu x,stu y){
    return x.all > y.all;
}
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin>>st[i].nam>>st[i].chi>>st[i].mat>>st[i].eng;
        st[i].all = st[i].chi + st[i].mat + st[i].eng;
    }
    sort(st + 1, st + n + 1, cmp);
    printf("%s %d %d %d", st[1].nam, st[1].chi, st[1].mat, st[1].eng);
    return 0;
}