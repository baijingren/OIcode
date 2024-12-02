#include<bits/stdc++.h>
using namespace std;

#define val first
#define nd second

const int qwe = 1e6+5;
int n,k;
class pri_queue{
    int cnt = 0;
    pair<int,int> tr[qwe];
    int fa(int rt){
        if(rt == 1){
            return 1;
        }
        if(rt % 2 == 1){
            return (rt-1)/2;
        }
        else{
            return rt/2;
        }
    }
    void add(int val,int nod){
        tr[++cnt].val = val;
        tr[cnt].nd = nod;
        int rt = cnt;
        int f = fa(rt);
        while(tr[rt].val>tr[f].val){
            swap(tr[rt],tr[f]);
            swap(rt,f);
        }
    }
    void del(){
        
    }
    int query(){
        return tr[1].nd;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    
}