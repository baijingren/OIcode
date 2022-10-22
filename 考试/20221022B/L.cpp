#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,k;
int Mxc;
double ans=0.0;
string a[qwe];
string s[]={
    " ","perfect","good","bad","miss"
};
double sc[]={
    0,900000,585000,0,0,100000
};
int combo=0;
int cnt[10];
int main(){
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>a[i];
        if(a[i].compare(s[1])==0 || s[2].compare(a[i])==0){
            combo++;
            Mxc=max(Mxc,combo);
        }
        else{
            combo=0;
        }
        for(int j=1;j<=4;j++){
            if(s[j].compare(a[i])==0){
                cnt[j]++;
                break;
            }
        }
    }
    combo+=(n-k);
    cnt[1]+=(n-k);
    Mxc=max(Mxc,combo);
    for(int i=1;i<=4;i++){
        ans+=(cnt[i]*sc[i]/n);
        // cerr<<ans<<' '<<cnt[i]<<endl;
    }
    ans+=sc[5]*Mxc*1.0/n;
    int x=ans*10;
    x%=10;
    if(x>=5){
        ans=ceil(ans);
    }
    else{
        ans=floor(ans);
    }
    cout<<(int)ans<<endl;
    return 0;
}