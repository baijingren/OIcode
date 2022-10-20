#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,k;
string s;
bool chk(int x){
    int mgc=0,cnt=0;
    for(int i=0;i<n;i++){
        if(mgc==0 && s[i]=='1'){
            mgc=x-1;
            cnt++;
        }
        else if(mgc!=0){
            mgc--;
        }
    }
    if(cnt>k){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    cin>>s;
    bool f=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            f=1;
            break;
        }
    }
    if(!f){
        cout<<0<<endl;
        return 0;
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        if(chk(mid)){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    cout<<l<<endl;
    return 0;
}