#include<bits/stdc++.h>
#define ll long long
#define un unsigned
using namespace std;
const int qwe=1e6+5;
int T;
int n,m;
int a[qwe];
priority_queue<int> q;

int main(){
    //freopen("/home/bai/code/test.in","r",stdin);
    //freopen("/home/bai/code/test.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        int ans=0;
        scanf("%d",&n);
        while(!q.empty()){
            q.pop();
        }
        for(int i=1;i<=n;i++){
            a[i]=0;
        }
        for(int i=1;i<n;i++){
            int x;
            scanf("%d",&x);
            a[x]++;
        }
        // for(int )
        sort(a+1,a+n+1,[](int x,int y){
            return x>y;
        });
        m=n;
        while(!a[m]){
            m--;
        }
        a[++m]=1;
        for(int i=1;i<=m;i++){
            if((a[i]-=m-i+1)>0){
                q.push(a[i]);
            }
        }
        if(!q.empty()){
            for(int i;q.top()>ans;++ans){
                i=q.top();
                q.pop();
                q.push(i-1);
            }
        }
        printf("%d\n",ans+m);
    }
    return 0;
}