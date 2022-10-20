#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,ans=0,cnt=0,anscnt=1;
// string bracket;
char bracket[qwe];
stack<int> s;
int main(){
    scanf("%s",bracket);
    n=strlen(bracket);
    for(int i=0;i<n;i++){
        // if(bracket[i]==')'){
        //     if(s.empty()){
        //         cnt=0;
        //     }
        //     else{
        //         s.pop();
        //         // cnt++;
        //         cnt+=2;
        //         if(ans==cnt && ans!=0){
        //             anscnt++;
        //             // cout<<i<<endl;
        //         }
        //         else if(ans<cnt){
        //             anscnt=1;
        //         }
        //         ans=max(cnt,ans);
        //     }
        // }
        // else{
        //     s.push(1);
        //     // cnt++;
        // }
        if(bracket[i]==')' && !s.empty() && bracket[s.top()]=='('){
            s.pop();
        }
        else{
            s.push(i);
        }
        cnt=0;
        if(s.size()){
            cnt=i-s.top();
        }
        else{
            cnt=i+1;
        }
        if(cnt>ans){
            ans=cnt;
            anscnt=1;
        }
        else if(cnt!=0 && cnt==ans){
            anscnt++;
        }
    }
    // if(s.empty()){
    //     if(ans==cnt){
    //         anscnt++;
    //         // cout<<'a';
    //     }
    //     else{
    //         anscnt=1;
    //     }
    //     ans=max(cnt,ans);
    // }
    printf("%d %d",ans,anscnt);
    return 0;
}