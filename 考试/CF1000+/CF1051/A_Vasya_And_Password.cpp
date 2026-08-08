#include<bits/stdc++.h>
using namespace std;
int T;
string s;
int a[105],vis[3];
vector<int> Char[3];
int BS,SN,BN;
int SB,NS,NB;
char c(int x){
    if(x==0){
        return 'A';
    }
    else if(x==1){
        return '1';
    }
    else{
        return 'a';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>s;
        int n=s.length();
        Char[0].clear();
        Char[1].clear();
        Char[2].clear();
        for(int i=0;i<3;i++){
            vis[i]=0;
        }
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z'){
                a[i]=0;
                Char[0].emplace_back(i);
            }
            else if(s[i]>='0' && s[i]<='9'){
                a[i]=1;
                Char[1].emplace_back(i);
            }
            else{
                a[i]=2;
                Char[2].emplace_back(i);
            }
        }
        int cnt=0;
        for(int i=0;i<3;i++){
            if(Char[i].size()==0){
                vis[i]=1;
                cnt++;
            }
        }
        if(cnt==0){
            cout<<s<<endl;
        }
        else{
            if(cnt==2){
                int b=0;
                for(int i=0;i<3;i++){
                    if(vis[i]){
                        s[b++]=c(i);
                    }
                }
            }
            else if(cnt==1){
                int temp=3,tmp=0;
                for(int i=0;i<3;i++){
                    if(Char[i].size()<=1){
                        temp-=i;
                    }
                    if(Char[i].size()==0){
                        tmp=i;
                    }
                }
                if(temp==3){
                    temp=1;
                }
                s[Char[temp][0]]=c(tmp);
            }
            cout<<s<<endl;
        }
    }
    return 0;
}