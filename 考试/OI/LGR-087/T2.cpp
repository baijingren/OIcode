#include<bits/stdc++.h>
using namespace std;
const int qwe=100005;
int n,ans=INT_MIN;
int P=998244353;
bool vis[qwe];
struct diamond{
    bool pl;
    int num;
} dia[qwe];
int main(){
    freopen("/home/bai/code/test.in", "r", stdin);
    scanf("%d\n",&n);
    char c;
    for(int i=1;i<=n;i++){
        scanf("\n%c %d",&c,&dia[i].num);
        if(c=='+') dia[i].pl=1;
        else if(c=='*') dia[i].pl=0;
    }
    
    printf("%d",(ans%P+P)%P);
    return 0;
}