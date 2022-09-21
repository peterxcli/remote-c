// codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
bool is_regular(string &str, int l, int r) {
    int cur = 0;
    for (int i = l; i <= r; i++) {
        if (str[i] == '(') cur++;
        else if (str[i] == ')') cur--;
        if (cur < 0) return false;
    }
    if (cur == 0) return true;
    else return false;
}
bool is_palindrome(string &str, int l, int r) {
    for (int i = 0; i < r-l+1; i++) {
        if (str[l+i] != str[r-i]) return false;
    }
    return true;
}
void solve_subtask() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int i = 0, ans = 0;
    for (i = 0; i < n;) {
        int j = i+1;
        while (j < n && !is_regular(str, i, j) && !is_palindrome(str, i, j)) {
            j++;
        }
        if (j >= n) break;
        ans++;
        i = j+1;
    }
    cout << ans << " " << n-i << "\n";

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