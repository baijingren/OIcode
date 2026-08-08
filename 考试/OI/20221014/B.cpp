#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
struct Node{
    int x,y;
    Node(){}
    Node(int a,int b){
        x=a;
        y=b;
    }
};
Node a[qwe];
int main(){
    freopen("golly.in","r",stdin);
    freopen("golly.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].x%=m;
        a[i].y%=m;
        if(a[i].y==0){
            a[i].y=m;
        }
    }
    for(int i=1;i<=n;i++){
        
    }
}