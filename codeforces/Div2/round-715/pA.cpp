//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n, tmp;
    vector<int> odd, even;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp&1) odd.emplace_back(tmp);
        else even.emplace_back(tmp);
    }
    // if (odd.size()&1) {
    //     cout << odd.back() << " ";
    //     odd.pop_back();
    // } 
    // if (even.size()&1) {
    //     cout << even.back() << " ";
    //     even.pop_back()
    // }
    for (auto i:even) cout << i << " ";
    for (auto i:odd) cout << i << " ";
    cout << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 1;
#ifdef MANY_SUBTASK
    cin >> cnt;
#endif
    while (cnt--)
    {
        solve_subtask();
    }
    return 0;
}