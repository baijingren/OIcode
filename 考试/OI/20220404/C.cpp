#include "candies.h"
#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
struct Node{
    int mn,mx,num,l,r;
} tree[qwe];
void build(int rt,int l,int r,vector<int> a){
    tree[rt].l=l;
    tree[rt].r=r;
    if(l==r){
        tree[rt].mn=a[l];
        tree[rt].mx=a[r];
        tree[rt].num=1;
        return;
    }
    int mid=(l+r)>>1;
    build(rt>>1,l,mid,a);
    build(rt>>1|1,mid+1,r,a);
    pushup(rt); 
}
std::vector<int> distribute_candies(std::vector<int> c, std::vector<int> l,
                                    std::vector<int> r, std::vector<int> v) {
    int n = c.size();
    std::vector<int> s(n);
    // s=c;if9
    int q=l.size();
    // c.emplace_back(1);
    for(int j=1;j<=q;j++){
        if(v[j]>0){
            for(int i=l[j];i<=r[j];i++){
                s[i]=min(c[i],s[i]+v[j]);
            }
        }
        else{
            for(int i=l[j];i<=r[j];i++){
                s[i]=max(0,s[i]+v[j]);
            }
        }
        for()
    }
    
    return s;
}