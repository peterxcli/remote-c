// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int b[4], c[4];

const int mod = 1e9+7;

int lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

void solve_subtask() {
    cin >> b[0] >> b[1] >> b[2]; 
    cin >> c[0] >> c[1] >> c[2];
    b[3] = b[0]+ (b[2]-1) * b[1];
    c[3] = c[0]+ (c[2]-1) * c[1];
    if (b[0] > c[0] || b[3] < c[3] || b[0] > c[3] || c[0] > b[3] || c[1] %  b[1] != 0 || (c[0]-b[0]) % b[1] != 0) {
        cout << "0\n";
        return;
    }
    if (c[0]-c[1] < b[0] || c[3] + c[1] > b[3]) {
        cout << "-1\n"; return;
    }
    int ans = 0;
    for (int i = 1; i * i <= c[1]; i++) {
        if (c[1] % i != 0) continue;
        if (lcm(i, b[1]) == c[1]) {
            int tmp = (c[1]/i)*(c[1]/i) % mod;
            ans = (ans + tmp) % mod;
        }
        if (i * i != c[1] && lcm(c[1]/i, b[1]) == c[1]) {
            int tmp = i * i % mod;
            ans = (ans + tmp) % mod;
        }
    }
    cout << ans << "\n";
    
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--) {
        solve_subtask();
    }
    return 0;
}