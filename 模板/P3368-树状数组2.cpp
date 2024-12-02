#include<bits/stdc++.h>
using namespace std;
#define lb(x) (x&-x);
const int qwe=1e6+5;
int n,m;
int a[qwe];
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
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int op,x,y,k;
        cin>>op>>x;
        if(op==1){
            cin>>y>>k;
            t.add(x,k);
            t.add(y+1,-k);
        }
        else{
            int ans=a[x]+t.query(x);//此程序存储的是差分数组，所以在输出的时候需要将原始值域差值相加
            cout<<ans<<'\n';
        }
    }
    return 0;
}