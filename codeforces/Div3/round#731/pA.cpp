#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    pair<int, int> A, B, F;
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> F.first >> F.second;
    int ans = abs(B.first-A.first) + abs(B.second-A.second);
    if (A.first == B.first && A.second == B.second) ans = 0;
    else if (A.first == B.first && A.first == F.first) {
        if (min(A.second, B.second) < F.second && max(A.second, B.second) > F.second) ans += 2;
    } 
    else if (A.second == B.second && A.second == F.second) {
        if (min(A.first, B.first) < F.first && max(A.first, B.first) > F.first) ans += 2;
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