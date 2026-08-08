#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T;

int n,m;
char a[qwe],b[qwe];

int ans = 0;
void chk(){
    ans = 0;
    for(int i=0;i<m;i++){
        int j=0,k=i;
        int cnt = 0;
        while(j<n && k<m){
            if(a[j] == b[k]){
                cnt++;
                ans = max(cnt,ans);
                j++,k++;
            }
            else{
                // k = i;
                j++;
                // cnt = 0;
            }
        }
    }
}

int main(){
    cin>>T;
    while(T--){
        cin>>a>>b;
        n=strlen(a);
        m=strlen(b);
        // if(!strcmp(a,b)){
        //     cout<<n<<endl;
        //     continue;
        // }
        chk();
        // cerr<<ans<<endl;
        cout<<(n+m-ans)<<endl;
    }
}