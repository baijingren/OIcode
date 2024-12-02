#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;

int T,n;
char c[qwe];

struct Cha{
    int cnt;
    char c;
};
Cha a[35];
void init(){
    for(int i=1;i<27;i++){
        a[i].cnt=0;
        a[i].c = 'a'+i-1;
    }
}
int main(){
    cin>>T;
    while(T--){
        // cerr<<T<<endl;
        
        cin>>n;
        init();
        for(int i=1;i<=n;i++){
            cin>>c[i];
            a[c[i]-'a'+1].cnt++;
            // a[c[i]-'a'+1].c = c[i];
        }
        // if(n <= 3){
        //     for(int i=1;i<=n;i++){
        //         cout<<c[i];
        //     }
        //     cout<<endl;
        // }
        // else{
            // sort(a+1,a+n+1,[](Cha x,Cha y){
            sort(a+1,a+26+1,[](Cha x,Cha y){
                return x.cnt>y.cnt;
            });
            int tmp = a[1].cnt - a[2].cnt;
            for(int i=1;i<=tmp;i++){
                cout<<a[1].c;
            }
            a[1].cnt -= tmp;
            queue<int> q;
            for(int i=1;i<=26;i++){
                q.push(i);
            }
            while(q.size()){
                int tmp = q.front();
                q.pop();
                if(a[tmp].cnt == 0){
                    continue;
                }
                a[tmp].cnt--;
                cout<<a[tmp].c;
                q.push(tmp);
            }
            cout<<endl;
        // }
    }
    return 0;
}