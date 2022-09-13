//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int MAX = 100000010;
int a, b, c, flag =1;
bool notPrime[MAX];
void sieve() {
    notPrime[1] = 1;
    for (int i = 2; i * i < MAX; i++) if (!notPrime[i]) {
        for (int j = i*i; j < MAX; j += i) notPrime[j] = true;
    }
    notPrime[1] = 0;
    notPrime[0] = 1;
}
void solve_subtask() {
    cin >> a >> b >> c;
    int x, y, z;
    for (int i = pow(10, c-1); i ; i++) if (!notPrime[i]) {
        z = i;
        break;
    }
    for (int i = pow(10, a-1)/z; i>=0 ; i++) if ((int)log10(i*z)+1 == a && i) {
        x = i*z;
        break;
    }
    for (int i = pow(10, b-1)/z; i>=0 ; i++) {
        // cout << i*z << endl;
        if (__gcd(x, i*z) == z && i && (int)log10(i*z)+1 == b) {
            y = i*z;
            break;
        }
    }
    // cout << x << " " << y << " " << z << endl;
    cout << x << " " << y << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
    sieve();
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--)
    {
        solve_subtask();
    }
    return 0;
}