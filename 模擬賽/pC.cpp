#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
int mod(string D, int N) {
    return 1;
}
int R, N, D;

int fast_pow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % D;
        b >>= 1, a = a * a % D;
    }
    return ret;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> D >> R >> N;
        int ans = 0, tmp = 1;
        int up = (fast_pow(R, N+1) -1 + D) % D;
        int down = R - 1;
        ans = fast_pow(down, D-2) * up % D;
        cout << ans << "\n";
        // for (int i = 0; i <= N; i++) {
        //     ans = ans + tmp;
        //     ans %= D;
        //     tmp = tmp * R % D;
        // }
        // cout << ans << "\n";
    }
    return 0;
}