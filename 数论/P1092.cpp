#include<bits/stdc++.h>
using namespace std;
const int qwe=1005;
int n;
int mp[4][qwe];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            char c;
            scanf("%c",&c);
            mp[i][j]=int(c-'A'+1);
        }
    }
    return 0;
}
