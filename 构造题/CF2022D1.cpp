#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T, n;
int ask(int a, int b){
    int tmp;
    cout<< "! " << a << ' ' << b << '\n';
            cout.flush();
            cin>>tmp;
            return tmp;
}
int main(){
    cin>>T;
    while(T--){
        string s;
        cin >> n >> s;
        for(int i = 1; i <= n - (n % 2); i += 2){
            int tmp_1, tmp_2;
            tmp_1 = ask(i, i + 1);
            tmp_2 = ask(i + 1, i);
            if(tmp_1 != tmp_2){
                tmp_1 = ask(i - 1, i);
                tmp_2 = ask(i, i - 1);
                int ans_1 = (tmp_1 == tmp_2);
                tmp_1 = ask(i - 1, i + 1);
                tmp_2 = ask(i + 1, i - 1);
                int ans_2 = (tmp_1 == tmp_2);
                if(ans_1 == 0){
                    cout << "! " << i << '\n';
                    return 0;
                }
                else if(ans_2 == 0){
                    cout << "! " << i + 1 << '\n';
                    return 0;
                }
            }
        }
        if(n % 2 == 1){
            int tmp_1 = ask(1, n);
            int tmp_2 = ask(n, 1);
            if(tmp_1 != tmp_2){
                cout << "! " << n << '\n';
            }
        }
    }
    return 0;
}