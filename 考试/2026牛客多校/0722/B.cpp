#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int qwe = 1e6 + 5;
#define LOG(...)                                      \
    do {                                              \
        fprintf(stderr, "\033[31m");                 \
        fprintf(stderr, __VA_ARGS__);                 \
        fprintf(stderr, "\033[0m\n");                \
    } while (0)
int n;
int T;
int a[qwe];
// vector<int> set1, set2, set;
// vector<int> p;
int p[40];
// void insert(int x)
// {
//     for (auto b : p)
//     {
//         x = min(x, b ^ x);
//     }
//     for (auto &b : p)
//     {
//         b = min(b, x ^ b);
//     }
//     if (x)
//     {
//         p.push_back(x);
//     }
// }
void insert(int x, int b){
    for(int i = 31; i >= 0; i--){
        if(((x >> i) & 1) && !((b >> i) & 1)){
            if(!p[i]){
                p[i] = x;
                break;
            }
            x ^= p[i];
        }
    }
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        memset(p, 0, sizeof(p));
        int b = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b ^= a[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            insert(a[i], b);
        }
        int ans = 0;
        // for(int i = 31; i >= 0; i--){
        //     LOG("i = %d, p[i] = %d", i, p[i]);
        // }
        for(int i = 31; i >= 0; i--){
            if(!((b >> i) & 1) && p[i] != 0){
                if((ans >> i) & 1){
                    continue;
                }
                ans ^= p[i];
            }
        }
        ans = (b ^ ans) + ans;
        cout << ans << endl;
    }
    return 0;
}

