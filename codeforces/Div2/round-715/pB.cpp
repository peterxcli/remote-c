//codeforces template
#define MANY_SUBTASK
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
void solve_subtask() {
    int n, QQ = 0;
    cin >> n;
    string str;
    cin >> str;
    for (int i = 0; i < n; i++) if (str[i] == 'M') QQ++;
    if (QQ == n/3 && str.back() != 'M' && str.front() != 'M') cout << "yes\n";
    else cout << "no\n";
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