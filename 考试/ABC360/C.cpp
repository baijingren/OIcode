#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n;
struct Item{
    int a,w;
} m[qwe];
bool vis[qwe];
int ans = 0;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i].a;
    }
    for(int i=1;i<=n;i++){
        cin>>m[i].w;
    }
    sort(m+1,m+n+1,[](Item x,Item y){
        return (x.a == y.a)?(x.w<y.w):(x.a<y.a);
    });
    for(int i=1;i<=n;i++){
        if(m[i+1].a!=m[i].a){
            continue;
        }
        else{
            ans+=m[i].w;
        }
    }
    cout<<ans<<endl;
    return 0;
}