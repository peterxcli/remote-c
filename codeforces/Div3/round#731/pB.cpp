//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    string str;
    cin >> str;
    char last = 'a';
    for (auto x : str) last = max(last, x);
    bool flag = false;
    while (!str.empty() && str.find(last) != string::npos) {
        // cout << str << "\n";
        if (str.front() == last) {
            str.erase(str.begin(), str.begin()+1);
        }
        else if (str.back() == last) {
            str.pop_back();
        }
        else break;
        last--;
        if (last == 'a'-1 && str.empty()) flag = true;
    }
    cout << (flag ? "YES\n" : "NO\n");
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