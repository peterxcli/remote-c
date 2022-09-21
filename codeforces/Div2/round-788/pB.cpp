// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n, k;
    cin >> n;
    string str;
    cin >> str;
    cin >> k;
    set<char> st;
    for (int i = 0; i < k; i++) {
        char tmp; cin >> tmp;
        st.insert(tmp);
    }
    int tmp = 0, ans = 0;;
    for (int i = 0; i < str.length(); i++) {
        if (st.find(str[i]) != st.end()) ans = max(tmp, ans), tmp = 0;
        tmp++;
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