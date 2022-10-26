#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n;
int len[qwe];
struct Node{
    int id,t,x;
    Node()=default;
    Node(int a,int b){
        x=a,t=b;
    }
} a[qwe];
struct mos{
    int p,q;
};
vector<Node> tmp;
int clac(int X){
    int l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].t;
        a[i].id=i;
        len[i]=a[i].t;
    }
    sort(a+1,a+n+1,[](Node a,Node b){
        return a.x==b.x?a.x<b.x:a.t<b.t;
    });
    int mx=0;
    
    for(int i=1;i<=n;i++){
        
    }
}
//25 223 32 14 12 