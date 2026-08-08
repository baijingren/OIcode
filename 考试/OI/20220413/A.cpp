#include<bits/stdc++.h>
using namespace std;
const int qwe=1e3+5;
int cnt=0,n;
map<string,int> mp;
string s[qwe],rd[qwe];
int add_node(string x){
    cnt++;
    
}
int main(){
    n=1;
    while(1){
        scanf("%s",rd[n++]);
        if(rd[n-1][0]='0'){
            n--;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        int m=rd[i].length(),k;
        string temp="";
        for(int j=1;j<=m;j++){
            if(rd[i][j]=='/'){
                int id=add_node(temp)
            }
            temp.append(s[j]);
        }
    }
    for(int i)
}