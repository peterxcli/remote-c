#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define int long long
const int mod = 1e9+7;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> C(N);
    for (auto &x : C) cin >> x;
    int ans = 1 , tmp = 0;
    sort(C.begin(), C.end());
    for (int i = 0; i < C.size(); i++) {
        ans = ans * max(0LL, C[i]-i) % mod;
    }
    cout << ans << "\n";
    return 0;
}