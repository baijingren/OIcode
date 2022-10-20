#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
typedef long long ll;
int n,m;
ll a[qwe],sum[qwe],f[qwe],d[qwe];
deque<int> q;
ll query(int i){
    d[i]=f[i-1]-sum[i];
    while(q.size()&&d[i]>d[q.back()]){
        q.pop_back();
    }
    q.push_back(i);
    while(q.size()&&q.front()<i-m){
        q.pop_front();
    }
    return d[q.front()];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    // f[1]=a[1];
    q.push_back(0);//hd=0,ed=1;
    for(int i=1;i<=n;i++){
        f[i]=query(i)+sum[i];
    }
    printf("%lld",f[n]);
}