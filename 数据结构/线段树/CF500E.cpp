#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n;
int pos[qwe],l[qwe];
//动态开点线段树
class SegmentTree{
    void pushup(int rt){

    }
    void build(int rt,int l,int r){
        if(l == r){
            return;
        }
        int mid = (l+r)>>1;
        build(rt>>1,l,mid);
        build(rt>>1|1,mid+1,r);
        pushup(rt);
    }
    void add(int rt){
        
    }
    int query(int rt,int l,int r,int L,int R){

    }
} T;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
         
    }
}