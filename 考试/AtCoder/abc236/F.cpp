#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int qwe=1e6+5;
int n;
ull ans=0;
// int x[1<<17];
struct Node{
    int id;
    ull num;
} x[1<<17];
vector<int> P;
void insert(int x,ull c){
    for(auto b:P){
        x=min(x,x^b);
    }
    for(auto &b:P){
        b=min(b,x^b);
    }
    if(x){
        P.push_back(x);
        ans+=c;
    }
}
bool cmp(Node x,Node y){
    return x.num<y.num;
}
int main(){
    scanf("%d",&n);
    int k=(1<<n)-1;
    for(int i=1;i<=k;i++){
        // int a;
        scanf("%d",&x[i].num);
        x[i].id=i;
        // insert(i,a);
    }
    sort(x+1,x+k+1,cmp);
    for(int i=1;i<=k;i++){
        insert(x[i].id,x[i].num);
    }
    printf("%llu",ans);
    return 0;
}