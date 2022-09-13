//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int gcdSum(int x) {
    int tmp = x;
    int rhs = 0;
    while (tmp) {
        rhs += tmp%10; 
        tmp/=10;
    }
    return __gcd(x, rhs);
}

void solve_subtask() {
    int x;
    cin >> x;
    while(gcdSum(x) == 1) {
        x++;
    }
    cout << x << "\n";
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