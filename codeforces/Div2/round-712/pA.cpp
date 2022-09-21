//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
bool is_palindrome(string s) {
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    if (tmp == s) return true;
    else return false;
}

void solve_subtask() {
    string s;
    cin >> s;
    if (!is_palindrome(s+'a')) {
        cout << "yes\n";
        cout << (s+'a') << "\n";
    }
    else if (!is_palindrome('a'+s)) {
        cout << "yes\n";
        cout << ('a'+s) << "\n";
    }
    else cout << "NO\n";
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