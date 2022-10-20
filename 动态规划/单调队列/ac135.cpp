#include<bits/stdc++.h>
using namespace std;
const int qwe=100005;
int n,m;
int s[qwe],q[qwe];
deque<int> qmax;
int main(){
    scanf("%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
        s[i]+=s[i-1];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(qmax.front()<(i-m)){
            qmax.pop_back();
        }
        ans=max(ans,s[i]-s[])
    }
}