    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    const int qwe=5e5+100;
    int n,m,T;
    vector<ll> a[qwe],s[qwe];
    map<pair<int,int>,ll> mp;
    int main(){
        freopen("veb.in","r",stdin);
        freopen("veb.out","w",stdout);
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cin>>n>>m>>T;
        for(int i=1;i<=m;i++){
            a[i].emplace_back(0);
            for(int j=1;j<=n;j++){
                int x;
                cin>>x;
                a[i].emplace_back(x);
            }
        }
        for(int i=1;i<=m;i++){
            s[i].emplace_back(0);
            for(int j=1;j<=n;j++){
                s[i].emplace_back(s[i][j-1]+a[i][j]);
            }
        }
        for(int i=1;i<=T;i++){
            int x,y;
            cin>>x>>y;
            // cerr<<x<<' '<<y<<endl;
            if(mp.find({x,y})!=mp.end()){
                cout<<mp[{x,y}]<<'\n';
                continue;
            }
            ll ans=INT_MIN;
            for(int j=1;j<=m;j++){
                // if(x==1){
                //     ans=max(ans,s[j][y]);
                // }
                // else{
                ans=max(ans,s[j][y]-s[j][x-1]);
                // }
            }
                mp[{x,y}]=ans;
            cout<<ans<<'\n';
        }
        return 0;
    }