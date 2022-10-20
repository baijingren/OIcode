#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
const int qwe=1e6+5;
const int mod=1e9+7;
int n,m,q,k,T,tl;
double x_1,x_2;
double ans=0.0;
double a[qwe],b[qwe];
vector<int> e[qwe];
int q[qwe];
int hd=1,ed=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>x_1>>x_2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        
    }
    cout<<std::fixed<<setprecision(2)<<ans;
    return 0;
}
/*
25 av983530810
134 940805584
15 983524791
~20 343343487
~18 598184649
10 
8 
6 
5
*/