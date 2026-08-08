#include<bits/stdc++.h>
using namespace std;
const int qwe=2e6+5;
int n,k,ansf=0,ansg=0;
int a[qwe];
int cnt[101];
void add(int x){
    int cnt=1;
    while(x){
        if(x&1){
            ::cnt[cnt]++;
        }
        x>>=1;
        cnt++;
    }
}
void del(int x){
    int cnt=1;
    while(x){
        if(x&1){
            ::cnt[cnt]--;
        }
        x>>=1;
        cnt++;
    }
}
int chk(){
    int ans=0;
    for(int i=1;i<=32;i++){
        if(cnt[i]==k){
            ans+=(1<<(i-1));
        }
    }
    return ans;
}
int main(){
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ansf|=a[i];
    }
    int tmp=0;
    for(int i=1,j=1;i<=n;i++){
        while(j-i+1<=k){
            add(a[j++]);
        }
        if(tmp=chk()){
            ansg=max(ansg,tmp);
        }
        del(a[i]);
    }
    cout<<ansf<<' '<<ansg<<endl;
    return 0;
}