#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n,q;
int pos[qwe],val[qwe];
unsigned long long s[qwe];
int ckL(int x){
    int l = 1, r = n;
    int mid;
    while(l<r){
        mid = (l+r)>>1;
        if(x>pos[mid]){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    return r;
}
int ckR(int x){
    int l = 1, r = n;
    int mid;
    while(l<r){
        mid = (l+r)>>1;
        if(x<=pos[mid]){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    // return l;
    if(x<pos[r]){
        return r-1;
    }
    else return r;
}
int main(){
    cin>>n;
    pos[0] = INT_MIN;
    for(int i=1;i<=n;i++){
        cin>>pos[i];
    }
    s[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        s[i] = s[i-1] + val[i];
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        int L,R;
        cin>>L>>R;
        int l = lower_bound(pos, pos + n + 1 , L) - pos;
        assert(l == ckL(L));
        int r = upper_bound(pos, pos + n + 1 , R) - pos - 1;
        assert(r == ckL(R));
        // cerr<<"l:"<<l<<" "<<"r:"<<r<<endl;
        if(r<l){
            cout<<0<<endl;
            continue;
        }
        cout<<s[r]-s[l-1]<<endl;
    }
    return 0;
}