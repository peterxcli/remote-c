//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int a[110];

int Mex(int x) {
    for (int i = 0; i <= x; i++) {
        if (a[i] != i) return a[i];
    }
    return x+1;
}

void solve_subtask() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> st;vector<int> remain;
    for (int i = 0; i < n; i++) {
        if (st.find(a[i]) == st.end()) st.insert(a[i]);
        else remain.push_back(a[i]);
    }
    for (auto x:st) cout << x << " ";
    for (auto x:remain) cout << x << " ";
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