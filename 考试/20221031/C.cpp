#include<bits/stdc++.h>
using namespace std;
const int qwe=25;
int T,tot,mx;
int a[qwe];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        tot=0,mx=0;
        for(int i=0;i<=9;i++){
            cin>>a[i];
            tot+=a[i];
            mx=max(a[i],mx);
        }
        if(tot==1 && a[0]==1){
            cout<<'0'<<endl;
            continue;
        }
        if ((mx>tot-mx+1)||(a[0]>=tot-a[0]+1))
        {
            cout <<"-1\n";
            continue;
        }
        int pre=0;
        for(int i=0;i<tot;i++){
            bool f=1;
            for(int j=0;j<=9;j++){
                if(a[j]==tot-i-a[j]+1){
                    cout<<j;
                    // cout<<'a';
                    a[j]--;
                    pre=j;
                    f=0;
                    break;  
                }
            }
            if(f){
                for(int j=0;j<=9;j++){
                    if(j!=pre && a[j]!=0){
                        cout<<j;
                        // cout<<'b';
                        a[j]--;
                        pre=j;
                        break;
                    }
                }
            }
        }
        cout<<endl;
    }
    return 0;
}