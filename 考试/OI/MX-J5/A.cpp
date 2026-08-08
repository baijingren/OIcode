#include<bits/stdc++.h>
using namespace std;
int n;
int pr[] = {2,3,5,7,11,13,17,19,4};
bool cnt[30];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<9;i++){
        cnt[pr[i]] = 1;
    }
    if(cnt[n+1]){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
    return 0;
}