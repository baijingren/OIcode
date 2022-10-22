#include<bits/stdc++.h>
using namespace std;
const int qwe=1e3+5;
int n,m,a,b,c,d,ans=0;
int mp[qwe][qwe];
int fir[qwe][qwe];
int tmp[qwe][qwe];
int mn[qwe][qwe];
int seat[qwe][qwe];
deque<int> q;
int main(){
    freopen("trip.in","r",stdin);
    freopen("trip.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n>>b>>a>>d>>c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1,l=1;i<=n-a+1;i++){
            while(l-i+1<=a){
                tmp[i][j]+=mp[l][j];
                l++;
            }
            tmp[i+1][j]=tmp[i][j]-mp[i][j];
        }
    }
    for(int i=1;i<=n-a+1;i++){
        for(int j=1,l=1;j<=m-b+1;j++){
            while(l-j+1<=b){
                seat[i][j]+=tmp[i][l];
                l++;
            }
            seat[i][j+1]=seat[i][j]-tmp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            tmp[i][j]=0;
        }
    }
    for(int j=1;j<=m;j++){
        // tmp[1][j]=0;
        for(int i=1,l=1;i<=n-c+1;i++){
            while(l-i+1<=c){
                tmp[i][j]+=mp[l][j];
                l++;
            }
            tmp[i+1][j]=tmp[i][j]-mp[i][j];
        }
    }
    for(int i=1;i<=n-c+1;i++){
        for(int j=1,l=1;j<=m-d+1;j++){
            while(l-j+1<=d){
                fir[i][j]+=tmp[i][l];
                l++;
            }
            fir[i][j+1]=fir[i][j]-tmp[i][j];
        }
    }
    // for(int i=1;i<=n-c+1;i++){
    //     for(int j=1;j<=m-d+1;j++){
    //         cerr<<setw(2)<<fir[i][j]<<' ';
    //     }
    //     cerr<<endl;
    // }
    // cerr<<"--------------------\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            tmp[i][j]=0;
            // cerr<<setw(2)<<seat[i][j]<<' ';
        }
        // cerr<<endl;
    }
    // for(int i=1;i<=n-a+1;i++){
    //     for(int j=1;j<=m-b+1;j++){
    //         // tmp[i][j]=0;
    //         cerr<<setw(2)<<seat[i][j]<<' ';
    //     }
    //     cerr<<endl;
    // }
    // cerr<<"---------------------\n";
    int k=a-c-1;
    for(int j=2;j<=m-1;j++){
        q.clear();
        for(int i=2,l=2;i<=n-c;i++){
            while(l-i+1<=k){
                while(!q.empty() && l-q.front()>=k){
                    q.pop_front();
                }
                while(!q.empty() && fir[q.back()][j] > fir[l][j]){
                    q.pop_back();
                }
                q.push_back(l);
                l++;
            }
            if(!q.empty()){
                tmp[i-1][j-1]=fir[q.front()][j];
            }
        }
    }
    // for(int i=1;i<=n-a+1;i++){
    //     for(int j=1;j<=m-d+1;j++){
    //         cerr<<setw(2)<<tmp[i][j]<<' ';
    //     }
    //     cerr<<endl;
    // }
    // cerr<<"---------------------\n";
    k=b-d-1;
    for(int i=1;i<=n-a+1;i++){
        q.clear();
        for(int j=1,l=1;j<=m-c+1;j++){
            while(l-j+1<=k){
                while(!q.empty() && l-q.front()>=k){
                    q.pop_front();
                }
                while(!q.empty() && tmp[i][q.back()] > tmp[i][l]){
                    q.pop_back();
                }
                q.push_back(l);
                l++;
            }
            if(!q.empty()){
                mn[i][j]=tmp[i][q.front()];
            }
        }
    }
    // for(int i=1;i<=n-a+1;i++){
    //     for(int j=1;j<=m-d+1;j++){
    //         cerr<<setw(2)<<mn[i][j]<<' ';
    //     }
    //     cerr<<endl;
    // }
    for(int i=1;i<=n-a+1;i++){
        for(int j=1;j<=m-b+1;j++){
            ans=max(ans,seat[i][j]-mn[i][j]);
        }
    }
    cout<<ans<<endl;
    // cerr<<ans<<endl;
    return 0;
}