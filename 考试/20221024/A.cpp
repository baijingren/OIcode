#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n;
int a[qwe];
int tmp[qwe];
long long ans=0;
queue<int> pos[105];
string s,t;
void merge_sort(int l,int r){
    if(r-l<=1){
        return;
    }
    int mid=(l+((r-l)>>1));
    merge_sort(l,mid);
    merge_sort(mid,r);
    for(int cnt=l,ta=l,tb=mid;cnt<r;cnt++){
        if(tb==r || (ta<mid) &&a[ta]<=a[tb]){
            tmp[cnt]=a[ta];
            ta++;
        }
        else{
            ans+=mid-ta;
            tmp[cnt]=a[tb];
            tb++;
        }
    }
    for(int i=l;i<r;i++){
        a[i]=tmp[i];
    }
}
int main(){
    freopen("letter.in","r",stdin);
    freopen("letter.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    cin>>s;
    cin>>t;
    s=" "+s;
    t=" "+t;
    for(int i=1;i<=n;i++){
        pos[t[i]-'A'+1].push(i);
    }
    for(int i=1;i<=n;i++){
        a[i]=pos[s[i]-'A'+1].front();
        pos[s[i]-'A'+1].pop();
    }
    merge_sort(1,n+1);
    // for(int i=1;i<=n;i++){
    //     cerr<<a[i]<<endl;
    // }
    cout<<ans<<endl;
    return 0;
}