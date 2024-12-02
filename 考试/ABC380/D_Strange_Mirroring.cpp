#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe = 1e6+5;
int T, m ,n, q, t;
ll a[qwe];
ll b[qwe];
string s;

char f(char a){
    if(a >= 'A' && a <= 'Z'){
        a -= 'A';
        a += 'a';
    }
    else if(a >= 'a' && a <= 'z'){
        a -= 'a';
        a += 'A';
    }
    return a;
}

int main(){
    cin>> s;
    cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> a[i];
    }
    n = s.length();
    ll tmp = n, cnt = 1;
    b[0] = tmp;
    while((tmp << 1) > 0){
        b[cnt] = tmp << 1;
        tmp <<= 1;
        cnt++;
    }
    b[cnt] = tmp;
    // cerr << i << endl;
    for(int i =1; i <= q;i++){
        int x = 0;
        while(a[i] > (ll)n){
            ll t = lower_bound(b, b + cnt + 1, a[i]) - b;
            // cerr << t <<' ' << a[i] << endl;
            a[i] -= b[t - 1];
            x ^= 1;
        }
        if(x == 0){
            cout << s[a[i] - 1] << ' ';
        }
        else {
            cout << f(s[a[i] - 1]) << ' ';
        }
    }
}