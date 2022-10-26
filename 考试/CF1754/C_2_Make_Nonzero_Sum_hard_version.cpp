#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int T;
int n,sum;
int a[qwe],b[qwe];
int l[qwe],r[qwe],cnt=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
            b[i]=0;
        }
        cerr<<sum%2<<endl;
        if(abs(sum%2)==1){
            cout<<"-1\n";
            continue;
        }
        sum/=2;
        l[1]=r[1]=cnt=1;
        for(int i=2;i<=n;i++){
            if(a[i]*sum>0 && !b[i-1]){
                sum-=a[i];
                b[i]=1;
                r[cnt]=i;
            }
            else{
                ++cnt;
                l[cnt]=r[cnt]=i;
            }
        }
        cout<<cnt<<'\n';
        for(int i=1;i<=cnt;i++){
            cout<<l[i]<<' '<<r[i]<<endl;
        }
    }
    return 0;
}