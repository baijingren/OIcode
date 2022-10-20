#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
int a[qwe];
vector<int> e[qwe];
char c[qwe];
int main(){
    scanf("%d%d ",&n,&m);
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        e[i].push_back(x);
        e[x].push_back(i);
    }
    for(int i=1;i<=n;i++){
        scanf("%c",&c[i]);
    }
    
}