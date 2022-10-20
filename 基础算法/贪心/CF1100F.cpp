#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,Q;
int a[qwe];
int pos[qwe];
int p[105];
int ans[qwe];
struct Node{
    int l,r;
    int id;
} b[qwe];
void insert(int x,int id){
    for(int i=20;i>=0;i--){
        if(x & (1<<i)){
            if(!p[i]){
                p[i]=x;
                pos[i]=id;
                return;
            }
            if(pos[i]<id){
                swap(pos[i],id);
                swap(x,p[i]);
            }
            x^=p[i];
        }
    }
}
int work(int x){
    int ans=0;
    for(int i=20;i>=0;i--){
        if(pos[i]>=x && ans<(ans^p[i])){
            ans^=p[i];
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>Q;
    for(int i=1;i<=Q;i++){
        cin>>b[i].l>>b[i].r;
        b[i].id=i;
    }
    sort(b+1,b+Q+1,[](Node a,Node b){
        return a.r<b.r;
    });
    int rt=0;
    for(int i=1;i<=Q;i++){
        while(rt<b[i].r){
            rt++;
            insert(a[rt],rt);
        }
        ans[b[i].id]=work(b[i].l);
    }
    for(int i=1;i<=Q;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}