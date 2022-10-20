#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
struct Node{
    int num;
    vector<int> k;
} a[qwe];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].num);
        for(int j=1;j<=a[i].num;j++){
            int x;
            scanf("%d",&x);
            a[i].k.push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        
    }

}