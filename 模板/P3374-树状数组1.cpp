#include<bits/stdc++.h>
using namespace std;
#define lb(x) (x&-x)
const int qwe=1e6+5;
int n,m;
struct SegmentTree{
    int a[qwe];
    void add(int x,int w){
        while(x<qwe){
            a[x]+=w;
            x+=lb(x);
        }
    }
    int query(int x){
        int ans=0;
        while(x){
            ans+=a[x];
            x-=lb(x);
        }
        return ans;
    }
} t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        t.add(i,x);
    }
    for(int i=1;i<=m;i++){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            t.add(x,y);
        }
        else{
            int ans=t.query(y)-t.query(x-1);//此程序存储的是前缀和数组
            cout<<ans<<'\n';
        }
    }
    return 0;
}