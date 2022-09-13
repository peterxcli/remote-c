//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n;
    string s;
    cin >> n >> s;
    int d = 0, k = 0;
    map<pair<int, int>, int> mp;
    for (char c : s) {
        if (c == 'D') d++;
        else k++;
        cout << ++mp[make_pair(d / __gcd(d, k), k / __gcd(d, k))] << " ";
    }
    cout << "\n";
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